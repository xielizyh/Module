/**
  ******************************************************************************
  * File Name:      app_key.c
  *
  * Description:    app_key function for xxx
  * Author:         Xli
  * Revision:       0.0
  * Date:           2018-12-11
  * History:
  * 			1.<2019-xx-xx, by Xli>
  *                 xxxx
  ******************************************************************************
 **/

/* Includes ------------------------------------------------------------------*/
#include "xli_err.h"
#include "app_key.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

/* Private define ------------------------------------------------------------*/
#define APP_KEY_TASK_STK_SIZE       1024
#define APP_KEY_TASK_PRIO           5

/* Private macro -------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
typedef struct{
    app_key_evt_t   evt;            /*按键事件*/
    app_key_cb_t    cb;             /*按键回调*/
    uint16_t        ticks;          /*计时*/
    uint8_t         polarity:1;     /*极性*/
    uint8_t         ispushed:1;     /*是否按下*/
    uint8_t         debounce:6;     /*消抖计时*/
}_key_t;

/* Private variables ---------------------------------------------------------*/
//按键列表
static _key_t _key_list[] = {
    {{BSP_KEY1}, NULL, 0, 0, 0, 0},
    {{BSP_KEY2}, NULL, 0, 0, 0, 0},
    {{BSP_KEY3}, NULL, 0, 0, 0, 0},
};

static TaskHandle_t app_key_task_handler;
/* Private function prototypes -----------------------------------------------*/
static void _key_state_change(_key_t *key, bsp_key_sta_t state);
static void _process_key_poll(void *arg);
static void _key_default_callback(app_key_evt_t *event);
static void app_key_task(void *arg);
/* Private functions ---------------------------------------------------------*/
/*==============================================================================
 * Function:        _key_state_change()
 * Description:     按键状态变化
 * Input:           none
 * Return:          none
 * Others:          none
 *============================================================================*/
static void _key_state_change(_key_t *key, bsp_key_sta_t state)
{
    key->evt.sta = state;

    if (state == BSP_KEY_IDLE) 
    {
        key->evt.clicks = 0;
    } 
    else 
    {
        key->cb(&key->evt);   //回调
    }
}

/*==============================================================================
 * Function:        _process_key_poll()
 * Description:     处理按键轮询
 * Input:           none
 * Return:          none
 * Others:          none
 *============================================================================*/
static void _process_key_poll(void *arg)
{
    _key_t *key = NULL;
    uint8_t ispushed = 0;

    for (uint8_t i = 0; i < BSP_KEY_NUM_MAX; i++)
    {
        key = &_key_list[i];
        if(key->evt.sta != BSP_KEY_IDLE)
        {
            key->ticks++;
        }
        ispushed = bsp_key_get_is_pushed(i);
        if ((ispushed != key->ispushed) && (++key->debounce >= BSP_KEY_DEBOUNCE_DISCERN_TICKS)) //消抖
        {
            key->ticks = 0;
            key->ispushed = ispushed;
            key->debounce = 0;

            if (ispushed) 
            {
                key->evt.clicks++;
            }
        }

        switch (key->evt.sta)
        {
        case BSP_KEY_IDLE:
            if (key->ispushed)  //检测到有效按下
            {
                _key_state_change(key, BSP_KEY_DOWN);
            }
            break;

        case BSP_KEY_DOWN:
            if (key->ispushed)
            {
                if(key->ticks >= BSP_KEY_HOLDING_DISCERN_TICKS) //长按
                {
                    _key_state_change(key, BSP_KEY_HOLDING);
                }
            }
            else
            {
                _key_state_change(key, BSP_KEY_UP); //弹起
            }
            break;
        
        case BSP_KEY_UP:
            if (key->ispushed) 
			{
                _key_state_change(key, BSP_KEY_DOWN);
            } 
			else 
			{
                if (key->ticks >= BSP_KEY_CLICK_DISCERN_TICKS) 
				{
                    _key_state_change(key, BSP_KEY_CLICK);
                }
            }        
            break;

        case BSP_KEY_HOLDING:
            if (!key->ispushed) 
			{
                _key_state_change(key, BSP_KEY_UP);
                _key_state_change(key, BSP_KEY_IDLE);
				//is_key_state_change = 0;
            }
            break;

        case BSP_KEY_CLICK:
            _key_state_change(key, BSP_KEY_IDLE);
			//is_key_state_change = 0;
            break;

        default:
            break;
        }
    }
}

/*==============================================================================
 * Function:        key_default_callback()
 * Description:     按键默认回调
 * Input:           none
 * Return:          none
 * Others:          none
 *============================================================================*/
static void _key_default_callback(app_key_evt_t *event)
{
    switch (event->sta)
    {
    case BSP_KEY_HOLDING:
        ESP_LOGI("Key", "Holding");
        break;

    case BSP_KEY_DOWN:
        ESP_LOGI("Key", "Down");
        break;

    case BSP_KEY_UP:
        ESP_LOGI("Key", "Up");
        break;

    case BSP_KEY_CLICK:
        ESP_LOGI("Key", "Click");
        break;

    default:
        break;
    }
}

/*==============================================================================
 * Function:        app_key_register_callback()
 * Description:     按键注册
 * Input:           none
 * Return:          none
 * Others:          none
 *============================================================================*/
xli_err_t app_key_register_callback(bsp_key_num_t key_num, app_key_cb_t callback)
{
    if (callback == NULL || key_num >= BSP_KEY_NUM_MAX) return XLI_ERR_FAIL;

    _key_list[key_num].cb = callback;

    return XLI_ERR_NONE;
}


/*==============================================================================
 * Function:        app_key_task()
 * Description:     按键任务
 * Input:           none
 * Return:          none
 * Others:          none
 *============================================================================*/
static void app_key_task(void *arg)
{
    
    while (1)
    {
        _process_key_poll(NULL);
        vTaskDelay(10/portTICK_PERIOD_MS);
    }
    
}

/*==============================================================================
 * Function:        app_key_init()
 * Description:     按键初始化
 * Input:           none
 * Return:          none
 * Others:          none
 *============================================================================*/
xli_err_t app_key_init(void *arg)
{
    bsp_key_init(NULL);

    for(uint8_t i = 0;i < BSP_KEY_NUM_MAX; i++)
    {
        _key_list[i].evt.sta = BSP_KEY_IDLE;
        _key_list[i].evt.clicks = 0;
        _key_list[i].cb = _key_default_callback;
    }

    xTaskCreate((TaskFunction_t )app_key_task,
                (const char*    )"app_key_task",
                (uint16_t       )APP_KEY_TASK_STK_SIZE,
                (void*          )NULL,
                (UBaseType_t    )APP_KEY_TASK_PRIO,
                (TaskHandle_t*  )&app_key_task_handler);   
    
    return XLI_ERR_NONE;
}

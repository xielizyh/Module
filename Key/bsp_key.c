/**
  ******************************************************************************
  * File Name:      bsp_key.c
  *
  * Description:    bsp_key function for xxx
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
#include "driver/gpio.h"
#include "bsp_gpio.h"
#include "bsp_key.h"

/* Private define ------------------------------------------------------------*/
//按键引脚定义
#define BSP_KEY1_PIN        (GPIO_NUM_21)
#define BSP_KEY2_PIN        (GPIO_NUM_22)
#define BSP_KEY3_PIN        (GPIO_NUM_23)

/* Private macro -------------------------------------------------------------*/
/*
#define BSP_KEY_PRESS       (1)
#define BSP_KEY_RELEASE     (0)
*/

/* Private typedef -----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/*==============================================================================
 * Function:        bsp_key_init()
 * Description:     按键驱动初始化
 * Input:           none
 * Return:          none
 * Others:          none
 *============================================================================*/
xli_err_t bsp_key_init(void *arg)
{
    return XLI_ERR_NONE;
}

/*==============================================================================
 * Function:        bsp_key_get_pushed()
 * Description:     获取按键状态
 * Input:           idx:索引
 * Return:          none
 * Others:          none
 *============================================================================*/
uint8_t bsp_key_get_is_pushed(uint8_t idx)
{
    switch (idx)
    {
    case BSP_KEY1:
        return !BSP_GPIO_READ(BSP_KEY1_PIN);
        break;

    case BSP_KEY2:
        return !BSP_GPIO_READ(BSP_KEY2_PIN);
        break;

    case BSP_KEY3:
        return !BSP_GPIO_READ(BSP_KEY3_PIN);
        break;    
                
    default:
        break;
    }

    return -1;
}

/*==============================================================================
 * Function:        bsp_key_read()
 * Description:     读取按键值
 * Input:           idx:索引
 * Return:          none
 * Others:          none
 *============================================================================*/
/*
uint16_t bsp_key_read(void)
{
    uint16_t key_value = 0;
    uint8_t level = 0;

    for (uint8_t i = 0; i < BSP_KEY_NUM_MAX; i++)
    {
        level = BSP_GPIO_READ(i);
        if (level == BSP_KEY_PRESS)
        {
            key_value |= (0x01 << i);
        }
        else
        {
            key_value |= (0x00 << i);
        }
        
    }
    
    return key_value;
}
*/
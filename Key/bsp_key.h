/**
  ******************************************************************************
  * File Name:      bsp_key.h
  *
  * Description:    bsp_key header for xxx
  * Author:         Xli
  * Revision:       0.0
  * Date:           2018-12-11
  * Modified:      
  * 		1.<2019-xx-xx, by Xli>		    
  *                 xxxx		         
  ******************************************************************************
 **/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BSP_KEY_H_
#define __BSP_KEY_H_

/* Includes ------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C"{
#endif

/* Exported constants --------------------------------------------------------*/
#define BSP_KEY_HOLDING_DISCERN_TICKS   250
#define BSP_KEY_DEBOUNCE_DISCERN_TICKS  2
#define BSP_KEY_CLICK_DISCERN_TICKS     5

/* Exported macros -----------------------------------------------------------*/
/* Exported action macros ----------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
//按键状态定义
typedef enum{
    BSP_KEY_IDLE,
    BSP_KEY_DOWN,
    BSP_KEY_UP,
    BSP_KEY_CLICK,
    BSP_KEY_HOLDING,
    BSP_KEY_STA_MAX,
}bsp_key_sta_t;

//按键索引定义
typedef enum{
    BSP_KEY1,
    BSP_KEY2,
    BSP_KEY3,
    BSP_KEY_NUM_MAX,
}bsp_key_num_t;

/* Exported variables ------------------------------------------------------- */
/* Exported functions ------------------------------------------------------- */
xli_err_t bsp_key_init(void *arg);
uint8_t bsp_key_get_is_pushed(uint8_t idx);

#ifdef __cplusplus
}
#endif

#endif  /* __BSP_KEY_H_ */

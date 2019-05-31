/**
  ******************************************************************************
  * File Name:      app_key.h
  *
  * Description:    app_key header for xxx
  * Author:         Xli
  * Revision:       0.0
  * Date:           2018-12-11
  * Modified:      
  * 		1.<2019-xx-xx, by Xli>		    
  *                 xxxx		         
  ******************************************************************************
 **/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __APP_KEY_H_
#define __APP_KEY_H_

/* Includes ------------------------------------------------------------------*/
#include "xli_err.h"
#include "bsp_key.h"

#ifdef __cplusplus
extern "C"{
#endif

/* Exported constants --------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/
/* Exported action macros ----------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
//按键事件定义
typedef struct{
  bsp_key_num_t num;
  bsp_key_sta_t sta;
  uint8_t       clicks;
}app_key_evt_t;


/* Exported variables ------------------------------------------------------- */
typedef uint8_t app_key_if_t; 

typedef void (*app_key_cb_t)(app_key_evt_t *event);

/* Exported functions ------------------------------------------------------- */
xli_err_t app_key_init(void *arg);
xli_err_t app_key_register_callback(bsp_key_num_t key_num, app_key_cb_t callback);

#ifdef __cplusplus
}
#endif

#endif  /* __APP_KEY_H_ */

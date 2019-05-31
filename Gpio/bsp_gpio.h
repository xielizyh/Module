/**
  ******************************************************************************
  * File Name:      bsp_gpio.h
  *
  * Description:    bsp_gpio header for xxx
  * Author:         Xli
  * Revision:       0.0
  * Date:           2018-12-11
  * Modified:      
  * 		1.<2018-xx-xx, by Xli>		    
  *                 xxxx		         
  ******************************************************************************
 **/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BSP_GPIO_H_
#define __BSP_GPIO_H_

/* Includes ------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C"{
#endif

/* Exported constants --------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/
/* Exported action macros ----------------------------------------------------*/
#define BSP_GPIO_READ(pin)          (gpio_get_level(pin))
#define BSP_GPIO_WRITE(pin, state)  do{gpio_set_level(pin, state);}while(0)

/* Exported types ------------------------------------------------------------*/
/* Exported variables ------------------------------------------------------- */
/* Exported functions ------------------------------------------------------- */

#ifdef __cplusplus
}
#endif

#endif  /* __BSP_GPIO_H_ */

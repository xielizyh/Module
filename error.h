/**
  ******************************************************************************
  * File Name:      err.h
  *
  * Description:    error header for xxx
  * Author:         Xli
  * Revision:       0.0
  * Date:           2018-12-11
  * Modified:      
  * 		1.<2018-xx-xx, by Xli>		    
  *                 xxxx		         
  ******************************************************************************
 **/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ERROR_H_
#define __ERROR_H_

/* Includes ------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C"{
#endif

/* Exported constants --------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/
/* Exported action macros ----------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
//err code
typedef enum{
  ERR_NONE,             /*无错误*/
}xli_err_t;

/* Exported variables ------------------------------------------------------- */
/* Exported functions ------------------------------------------------------- */

#ifdef __cplusplus
}
#endif

#endif  /* __ERROR_H_ */

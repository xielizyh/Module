/**
  ******************************************************************************
  * File Name:      xli_err.h
  *
  * Description:    xli_err header for xxx
  * Author:         Xli
  * Revision:       0.0
  * Date:           2018-12-11
  * Modified:      
  * 		1.<2018-xx-xx, by Xli>		    
  *                 xxxx		         
  ******************************************************************************
 **/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __XLI_ERROR_H_
#define __XLI_ERROR_H_

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>

#ifdef __cplusplus
extern "C"{
#endif

/* Exported constants --------------------------------------------------------*/
//error code definitions
#define XLI_ERR_NONE              (0)       /*无错误*/
#define XLI_ERR_FAIL              (0x01)    /*失败*/
#define XLI_ERR_NO_MEM            (0x02)    /*内存溢出*/
#define XLI_ERR_INVALID_ARG       (0x03)    /*变量非法*/

/* Exported macros -----------------------------------------------------------*/
/* Exported action macros ----------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
//err type
typedef uint8_t xli_err_t;

/* Exported variables ------------------------------------------------------- */
/* Exported functions ------------------------------------------------------- */

#ifdef __cplusplus
}
#endif

#endif  /* __XLI_ERROR_H_ */

/**
  ******************************************************************************
  * @file    XXXXXX.H
  * @author  Motus_LiuYaxin
  * @version V0.0.1
  * @date
  * @brief
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USER_CANOPEN_H
#define __USER_CANOPEN_H

#ifdef __cplusplus
 extern "C" {
#endif
	 
/* Includes ------------------------------------------------------------------*/
#include "canfestival.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
#define TIMEVAL_MAX 0xFFFF
/* Exported functions ------------------------------------------------------- */
extern void canOpenInit(UNS8 nodeId);
extern void timerForCan(void);
#ifdef __cplusplus
}
#endif

#endif /* __USER_CANOPEN_H */

/************************ (C) COPYRIGHT XXX *****END OF FILE****/

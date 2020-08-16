/**
 * @file stm32f1xx_it.h
 * @author Pawel Klisz (pawelochojec@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-04-07
 * 
 * @copyright Copyright (c) 2020 by Pawel Klisz. All rights reserved
 * 
 * Released under the terms of the GNU General Public License version 3 or later.
 * For full license please refer to LICENSE.txt
 * 
 * This project can be found on https://github.com/Sapieron/Step-motor-adapter-for-RPi
 * 
 */

#ifndef STM32F1XX_IT_H
#define STM32F1XX_IT_H


#ifdef __cplusplus
 extern "C" {
#endif 

#include "TargetsDefines.hpp"

/* Includes ------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

void NMI_Handler(void){while(1);}
void HardFault_Handler(void){ while(1);}
void MemManage_Handler(void){while(1);}
void BusFault_Handler(void){while(1);}
void UsageFault_Handler(void){while(1);}
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);

#ifdef __cplusplus
}
#endif


#endif /* STM32F1XX_IT_H */
/**
 * @file main.cpp
 * @author https://github.com/Sapieron
 * @brief Main application - this is where we start right after
 * 		  startup_stm32f103xb.s
 * @version 0.1
 * @date 2020-03-03
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <cstdint>

#include "stm32f1xx_hal.h"
#include "stm32f1xx.h"
#include "system_stm32f1xx.h"

#include "gpio/forward.hpp"
#include "mcu/board.hpp"

/**
 * @brief Instance of Board. Delivers access to peripherals
 * 		  and other //TODO what is ,,other?"
 */
BOARD Main;

void SetupHardware()
{
	__HAL_RCC_GPIOA_CLK_ENABLE();      //FIXME make it pretty!
	__HAL_RCC_GPIOB_CLK_ENABLE();
	//GPIO_PinModeSet(io_map::XTAL::HF::Pin1::Port, io_map::XTAL::HF::Pin1::PinNumber, );
	Main.Hardware.Initialize();
}

void wait()
{
	for(int i = 0; i < 15000; i++);
}

int main(void)
{
	HAL_Init();
	SetupHardware();

	while(1)
	{
		Main.Hardware.Pins.LedCommOk.High();
		wait();
		Main.Hardware.Pins.LedCommOk.Low();
		wait();
	}
}

#ifdef __cplusplus
 extern "C" {
#endif 

/* Includes ------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);

void SysTick_Handler(void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}

#ifdef __cplusplus
}
#endif

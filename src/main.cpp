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
	//GPIO_PinModeSet(io_map::XTAL::HF::Pin1::Port, io_map::XTAL::HF::Pin1::PinNumber, );
	Main.Hardware.Initialize();
}

int main(void)
{
	HAL_Init();
	SetupHardware();

	while(1)
	{
		Main.Hardware.Pins.LedCommOk.High();
	}
}
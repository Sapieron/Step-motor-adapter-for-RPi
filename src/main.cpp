/**
 * @file main.cpp
 * @author Pawel Klisz (pawelochojec@gmail.com)
 * @brief This file is executed right after default initialization
 * @version 0.1
 * @date 2020-03-14
 * 
 * @copyright Copyright (c) 2020 by Pawel Klisz. All rights reserved
 * 
 * Released under the terms of the GNU General Public License version 3 or later.
 * For full license please refer to LICENSE.txt
 * 
 * This project can be found on https://github.com/Sapieron/Step-motor-adapter-for-RPi
 * 
 */

/******************************************************************************\
 * 								Includes
\******************************************************************************/
/** Standard library includes */
#include <cstdint>
#include <cstring>

/** Hardware Abstraction Layer includes */
#include "stm32f1xx.h"
#include "stm32f1xx_hal.h"
#include "system_stm32f1xx.h"

/** General includes */
#include "gpio/forward.hpp"
#include "mcu/board.hpp"
#include "mcu/stm32f1xx_it.h"
#include "utils.hpp"

/******************************************************************************\
 * 								Global defines
\******************************************************************************/
/** @brief Instance of Board. Delivers access to peripherals */
BOARD Main;


void SetupHardware()
{
	__HAL_RCC_GPIOA_CLK_ENABLE();      //FIXME integrate these calls into initializations
	__HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_USART2_CLK_ENABLE();
    __HAL_RCC_AFIO_CLK_ENABLE();
    __HAL_RCC_DMA1_CLK_DISABLE();
	Main.Hardware.Initialize();
}

/******************************************************************************\
 * 							TEMPORARY CODE TO TEST ON
\******************************************************************************/


/******************************************************************************\
 * 								  IRQ Handlers
\******************************************************************************/
extern "C" void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    huart->Instance = USART2;   //FIXME just a dummy assignement to not generate warning of unused variable
    Main.Hardware.Pins.LedCommOk.Toggle();
}

extern "C" __attribute__((optimize("03"))) void USART2_IRQHandler(void)
{
    Main.Hardware.Terminal.OnReceived();
}


/************************************* *****************************************\
 * 								Main application
\******************************************************************************/
int main(void)
{
    HAL_Init();
    SetupHardware();

    /** @note Events are handled with interrupts */
	while(1);
}
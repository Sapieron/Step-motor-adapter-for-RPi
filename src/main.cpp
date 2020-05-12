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
#include "board_access.hpp"

/******************************************************************************\
 * 								Global defines
\******************************************************************************/
/** @brief Instance of Board. Delivers access to peripherals */
BOARD Main;


void SetupHardware()
{
	__HAL_RCC_GPIOA_CLK_ENABLE();      //FIXME integrate these calls into initializations
	__HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_TIM1_CLK_ENABLE();
	Main.Hardware.Initialize();
}

/******************************************************************************\
 * 							        Callbacks
\******************************************************************************/

extern "C" void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    UNUSED(huart);
    Main.Hardware.Terminal.CallbackHandler();
}

/** @brief send frame every 1000 ticks */
int tick = 1000;
extern "C" void HAL_SYSTICK_Callback(void)
{
    while(! tick--)
    {
        GetTerminal().Puts("Test\r\n");
        tick = 1000;
    }
}


/******************************************************************************\
 * 								  IRQ Handlers
\******************************************************************************/
/** @brief USART2 IRQ Handling */
extern "C" __attribute__((optimize("O3"))) void USART2_IRQHandler(void)
{
    Main.Hardware.Terminal.OnReception();
    Main.Hardware.Pins.LedCommOk.Toggle();
}

/** @brief DMA1 Channel 7 - transfer reception handler */
extern "C" __attribute__((optimize("O3"))) void DMA1_Channel6_IRQHandler(void)
{
    Main.Hardware.Terminal.OnDmaReceive();
}

/** @brief DMA1 Channel 7 - transfer transmission handler */
extern "C" __attribute__((optimize("O3"))) void DMA1_Channel7_IRQHandler(void)
{
    Main.Hardware.Terminal.OnDmaTransmit();
}

/******************************************************************************\
 * 								Main application
\******************************************************************************/
int main(void)
{
    __disable_irq();
    SystemCoreClock = 8_MHz;
    SystemCoreClockUpdate();
    HAL_Init();
    SetupHardware();

    /** @brief Generate interrupt with 1kHz rate */
    SysTick_Config(SystemCoreClock / 1_kHz);
    __enable_irq();

    /** @note Events are handled with interrupts */
    while (1)
    {
        /** @remark nothing to do here */
    }
}

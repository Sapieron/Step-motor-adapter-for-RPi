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
 *                                 Includes
\******************************************************************************/
/* Standard library includes */
#include <cstdint>

/* Hardware Abstraction Layer includes */
#include "TargetsDefines.hpp"

/* General includes */
#include "mcu/board.hpp"
#include "mcu/stm32f1xx_it.h"
#include "utils.hpp"
#include "board_access.hpp"

/* FreeRTOS includes */
#include "cmsis_os.h"

/******************************************************************************\
 *                               Global defines
\******************************************************************************/
/** @brief Instance of Board. Delivers access to peripherals */
BOARD Main;

/******************************************************************************\
 *                              Main application
\******************************************************************************/

/**
 * @brief Main function, that gets called after default initialization
 * 
 * @return int 
 */
int main(void)
{
    HAL_Init();

    Main.Hardware.Initialize();

    osKernelInitialize();

    osKernelStart();

    /* After kernel start following code should not be executed */
    while (1)
    {
        HardFault_Handler();
    }
}


/******************************************************************************\
 *                                 Callbacks
\******************************************************************************/

extern "C" void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    UNUSED(huart);
    Main.Hardware.Pins.LedCommOk.Low();
    Main.motorController.OnReception(GetTerminal().GetRxBuffer());
    Main.Hardware.Terminal.CallbackHandler();
}


extern "C" void HAL_UART_RxHalfCpltCallback(UART_HandleTypeDef *huart)
{
    UNUSED(huart);
    Main.Hardware.Pins.LedCommOk.High();
}


/******************************************************************************\
 *                               IRQ Handlers
\******************************************************************************/
/** @brief USART2 IRQ Handling */
extern "C" __attribute__((optimize("O3"))) void USART3_IRQHandler(void)
{
    Main.Hardware.Terminal.OnReception();
}

/** @brief DMA1 Channel 3 - transfer reception handler */
extern "C" __attribute__((optimize("O3"))) void DMA1_Channel3_IRQHandler(void)
{
    Main.Hardware.Terminal.OnDmaReceive();
}

/** @brief DMA1 Channel 2 - transfer transmission handler */
extern "C" __attribute__((optimize("O3"))) void DMA1_Channel2_IRQHandler(void)
{
    Main.Hardware.Terminal.OnDmaTransmit();
}


/******************************************************************************\
 *                              End of file
\******************************************************************************/

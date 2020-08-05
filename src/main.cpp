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
 *                               Global defines
\******************************************************************************/
/** @brief Instance of Board. Delivers access to peripherals */
BOARD Main;



/******************************************************************************\
 *                              Main application
\******************************************************************************/
int main(void)
{
    __disable_irq();

    HAL_Init();
    Main.Hardware.Initialize();

    /** @brief Generate interrupt with 1kHz rate */
    SysTick_Config(SystemCoreClock / 1_kHz);    //TODO move it to clock module?
    __enable_irq();

    /** @note Events are handled with interrupts */
    while (1)
    {
        /** @remark nothing to do here */
    }
}

/******************************************************************************\
 *                                 Callbacks
\******************************************************************************/

extern "C" void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    UNUSED(huart);
    Main.Hardware.Pins.LedCommOk.High();
    Main.Hardware.Terminal.CallbackHandler();
}

extern "C" void HAL_UART_RxHalfCpltCallback(UART_HandleTypeDef *huart)
{
    UNUSED(huart);
    Main.Hardware.Pins.LedCommOk.Low();
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


extern "C" __attribute__((optimize("O1"))) void TIM2_IRQHandler(void)
{
    // Main.Hardware.MotorX.OnInterrupt(); //TODO make this handling work
    if ((TIM2->SR &= TIM_SR_UIF) == 0b1)
    {
        TIM2->SR &= ~(TIM_SR_UIF);
    }

    /** @brief commutation update control */
    /* Reset the OC1M bits in the CCMR1 register */
    TIM1->CCMR1 &= TIM_CCMR1_OC2M;
    /* configure the OC1M bits in the CCMRx register to inactive mode*/
    TIM1->CCMR1 |= TIM_OCMODE_FORCED_INACTIVE;
}

extern "C" __attribute__((optimize("O1"))) void TIM4_IRQHandler(void)
{
    // Main.Hardware.MotorX.OnInterrupt(); //TODO make this handling work
    if ((TIM4->SR &= TIM_SR_UIF) == 0b1)
    {
        TIM4->SR &= ~(TIM_SR_UIF);
    }

    /** @brief commutation update control */
    /* Reset the OC1M bits in the CCMR1 register */
    TIM3->CCMR1 &= TIM_CCMR1_OC2M;
    /* configure the OC1M bits in the CCMRx register to inactive mode*/
    TIM3->CCMR1 |= TIM_OCMODE_FORCED_INACTIVE;
}
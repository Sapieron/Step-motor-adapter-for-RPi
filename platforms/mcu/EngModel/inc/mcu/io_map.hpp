/**
 * @file io_map.hpp
 * @author Pawel Klisz (pawelochojec@gmail.com)
 * @brief This file contains peripheral pin's definitions specific for Engineering Model
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

#ifndef ENG_MODEL_MCU_IO_MAP_HPP
#define ENG_MODEL_MCU_IO_MAP_HPP

#include <cstdint>

#include "TargetsDefines.hpp"

#include "base/io_map.hpp"
#include "utils.hpp"

namespace io_map
{
    using LedCommOk = PinLocation<GPIOC_BASE, GPIO_PIN_7>;

    using MotorControlEnable = PinLocation<GPIOA_BASE, GPIO_PIN_9>;

    struct Motor_X : public MotorPins<Motor_X>
    {
        using Dir   = PinLocation<GPIOB_BASE, GPIO_PIN_13>;
        using Ms1   = PinLocation<GPIOC_BASE, GPIO_PIN_0>;
        using Ms2   = PinLocation<GPIOC_BASE, GPIO_PIN_1>;
        using Ms3   = PinLocation<GPIOC_BASE, GPIO_PIN_2>;
        using Step  = PinLocation<GPIOC_BASE, GPIO_PIN_6>;

        static constexpr std::uint32_t OutputSlaveTimer = TIM8_BASE;
        static constexpr std::uint32_t MasterTimer      = TIM4_BASE;
        static constexpr IRQn_Type     MasterTimerIRQn  = IRQn_Type::TIM4_IRQn;   //FIXME is it correct irqn?
        static constexpr std::uint32_t TimerChannel     = TIM_CHANNEL_1;

        static constexpr std::uint32_t DutyCycleInPercent = 10_percent;

        static constexpr std::uint32_t Frequency        = 200_Hz;
        static constexpr std::uint32_t MotorStepsPerRev = 800;
        static constexpr std::uint32_t SteppingMode     = 2;
    };

    struct Motor_Y : public MotorPins<Motor_Y>
    {
        using Dir   = PinLocation<GPIOB_BASE, GPIO_PIN_0>;
        using Ms1   = PinLocation<GPIOC_BASE, GPIO_PIN_3>;
        using Ms2   = PinLocation<GPIOC_BASE, GPIO_PIN_4>;
        using Ms3   = PinLocation<GPIOC_BASE, GPIO_PIN_5>;
        using Step  = PinLocation<GPIOA_BASE, GPIO_PIN_8>;

        static constexpr std::uint32_t OutputSlaveTimer = TIM1_BASE;
        static constexpr std::uint32_t MasterTimer      = TIM2_BASE; //TODO use definitions from A4988/types.hpp
        static constexpr IRQn_Type     MasterTimerIRQn  = IRQn_Type::TIM2_IRQn;   //FIXME is it correct irqn?
        static constexpr std::uint32_t TimerChannel     = TIM_CHANNEL_1;

        static constexpr std::uint32_t DutyCycleInPercent = 10_percent;

        static constexpr std::uint32_t Frequency        = 200_Hz;
        static constexpr std::uint32_t MotorStepsPerRev = 800;
        static constexpr std::uint32_t SteppingMode     = 2;    //FIXME it's a magic number! maybe create enum instead of MSTable?
    };

    struct Motor_Z : public MotorPins<Motor_Z>
    {
        using Dir   = PinLocation<GPIOB_BASE, GPIO_PIN_15>;
        using Ms1   = PinLocation<GPIOC_BASE, GPIO_PIN_10>;
        using Ms2   = PinLocation<GPIOC_BASE, GPIO_PIN_11>;
        using Ms3   = PinLocation<GPIOC_BASE, GPIO_PIN_12>;
        using Step  = PinLocation<GPIOB_BASE, GPIO_PIN_14>;

        static constexpr std::uint32_t OutputSlaveTimer = TIM12_BASE;
        static constexpr std::uint32_t MasterTimer      = TIM5_BASE;
        static constexpr IRQn_Type     MasterTimerIRQn  = IRQn_Type::TIM5_IRQn;
        static constexpr std::uint32_t TimerChannel     = TIM_CHANNEL_1;

        static constexpr std::uint32_t DutyCycleInPercent = 10_percent;

        static constexpr std::uint32_t Frequency        = 100_Hz;
        static constexpr std::uint32_t MotorStepsPerRev = 800;
        static constexpr std::uint32_t SteppingMode     = 2;
    };

    struct UART_3 : public UARTPins<UART_3>
    {
        static constexpr std::uint32_t  Peripheral          = USART3_BASE;
        static constexpr std::uint32_t  Baudrate            = 115200;
        static constexpr std::uint32_t  WordLength          = UART_WORDLENGTH_8B;
        static constexpr std::uint32_t  StopBits            = UART_STOPBITS_1;
        static constexpr std::uint32_t  ParityBits          = UART_PARITY_NONE;
        static constexpr std::uint32_t  Mode                = UART_MODE_TX_RX;
        static constexpr std::uint32_t  HwFlowCtl           = UART_HWCONTROL_NONE;
        static constexpr std::uint32_t  OverSampling        = UART_OVERSAMPLING_16;

        static constexpr std::uint8_t   InterruptPriority   = 7;
        static constexpr IRQn_Type      Interrupt           = IRQn_Type::USART3_IRQn;

        static constexpr IRQn_Type      DmaRxIRQn           = IRQn_Type::DMA1_Channel3_IRQn;
        static constexpr std::uint32_t  DmaRxChannel        = DMA1_Channel3_BASE;

        static constexpr IRQn_Type      DmaTxIRQn           = IRQn_Type::DMA1_Channel2_IRQn;
        static constexpr std::uint32_t  DmaTxChannel        = DMA1_Channel2_BASE;

        using TX = PinLocation<GPIOB_BASE, GPIO_PIN_10>;
        using RX = PinLocation<GPIOB_BASE, GPIO_PIN_11>;
    };
}

#endif /* ENG_MODEL_MCU_IO_MAP_HPP */

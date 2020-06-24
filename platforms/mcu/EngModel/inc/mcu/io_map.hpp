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

#include "stm32f103xb.h"
#include "stm32f1xx_hal.h"

#include "base/io_map.hpp"
#include "utils.hpp"

namespace io_map
{
    using LedCommOk = PinLocation<GPIOA_BASE, GPIO_PIN_0>;


//     using MotorControlEnable = PinLocation<GPIOB, 9>;    //FIXME it's common for all motors
    struct Motor_X : public MotorPins<Motor_X>
    {
        using Dir   = PinLocation<GPIOB_BASE, GPIO_PIN_10>;
        using Ms1   = PinLocation<GPIOB_BASE, GPIO_PIN_0>;
        using Ms2   = PinLocation<GPIOB_BASE, GPIO_PIN_1>;
        using Ms3   = PinLocation<GPIOB_BASE, GPIO_PIN_2>;
        // using Step  = PinLocation<GPIOB_BASE, GPIO_PIN_13>;
        using Step  = PinLocation<GPIOA_BASE, GPIO_PIN_8>;

        static constexpr std::uint32_t OutputSlaveTimer = TIM1_BASE;
        static constexpr std::uint32_t MasterTimer      = TIM2_BASE;
        static constexpr IRQn_Type     MasterTimerIRQn  = IRQn_Type::TIM2_IRQn;

        static constexpr std::uint32_t DutyCycleInPercent = 10_percent;

        static constexpr std::uint32_t Frequency        = 200_Hz;
        static constexpr std::uint32_t MotorStepsPerRev = 800;
        static constexpr std::uint32_t SteppingMode     = 2;
    };

    struct Motor_Y : public MotorPins<Motor_Y>
    {
        using Dir   = PinLocation<GPIOB_BASE, GPIO_PIN_11>;
        using Ms1   = PinLocation<GPIOB_BASE, GPIO_PIN_3>;
        using Ms2   = PinLocation<GPIOB_BASE, GPIO_PIN_4>;
        using Ms3   = PinLocation<GPIOB_BASE, GPIO_PIN_5>;
        // using Step  = PinLocation<GPIOB_BASE, GPIO_PIN_14>;
        using Step  = PinLocation<GPIOA_BASE, GPIO_PIN_6>;  //TODO temporary, to check if tim3 is outputting

        static constexpr std::uint32_t OutputSlaveTimer = TIM3_BASE;
        static constexpr std::uint32_t MasterTimer      = TIM4_BASE;
        static constexpr IRQn_Type     MasterTimerIRQn  = IRQn_Type::TIM4_IRQn;

        static constexpr std::uint32_t DutyCycleInPercent = 10_percent;

        static constexpr std::uint32_t Frequency        = 200_Hz;
        static constexpr std::uint32_t MotorStepsPerRev = 800;
        // static constexpr std::uint32_t TargetRPM        = 30_rpm;
        static constexpr std::uint32_t SteppingMode     = 2;    //FIXME it's a magic number! maybe create enum instead of MSTable?
    };

    struct Motor_Z : public MotorPins<Motor_Z>
    {
        using Dir   = PinLocation<GPIOB_BASE, GPIO_PIN_12>;
        using Ms1   = PinLocation<GPIOA_BASE, GPIO_PIN_4>;
        using Ms2   = PinLocation<GPIOA_BASE, GPIO_PIN_5>;
        // using Ms3   = PinLocation<GPIOA_BASE, GPIO_PIN_6>;
        using Ms3 = PinLocation<GPIOA_BASE, GPIO_PIN_7>;    //FIXME this is temporary to make sure A6 is not overlapping
        using Step  = PinLocation<GPIOB_BASE, GPIO_PIN_15>;

        static constexpr std::uint32_t Frequency        = 100_Hz;
        static constexpr std::uint32_t MotorStepsPerRev = 800;
        // static constexpr std::uint32_t TargetRPM        = 30_rpm;
        static constexpr std::uint32_t SteppingMode     = 2;
    };

    struct UART_2 : public UARTPins<UART_2>
    {
        static constexpr std::uint32_t  Peripheral          = USART2_BASE;
        static constexpr std::uint32_t  Baudrate            = 115200;
        static constexpr std::uint32_t  WordLength          = UART_WORDLENGTH_8B;
        static constexpr std::uint32_t  StopBits            = UART_STOPBITS_1;
        static constexpr std::uint32_t  ParityBits          = UART_PARITY_NONE;
        static constexpr std::uint32_t  Mode                = UART_MODE_TX_RX;
        static constexpr std::uint32_t  HwFlowCtl           = UART_HWCONTROL_NONE;
        static constexpr std::uint32_t  OverSampling        = UART_OVERSAMPLING_16;

        static constexpr std::uint8_t   InterruptPriority   = 7;
        static constexpr IRQn_Type      Interrupt           = IRQn_Type::USART2_IRQn;
        

        static constexpr IRQn_Type      DmaRxIRQn           = IRQn_Type::DMA1_Channel6_IRQn;
        static constexpr std::uint32_t  DmaRxChannel        = DMA1_Channel6_BASE;

        static constexpr IRQn_Type      DmaTxIRQn           = IRQn_Type::DMA1_Channel7_IRQn;
        static constexpr std::uint32_t  DmaTxChannel        = DMA1_Channel7_BASE;

        using TX = PinLocation<GPIOA_BASE, GPIO_PIN_2>;
        using RX = PinLocation<GPIOA_BASE, GPIO_PIN_3>;
    };
}

#endif /* ENG_MODEL_MCU_IO_MAP_HPP */

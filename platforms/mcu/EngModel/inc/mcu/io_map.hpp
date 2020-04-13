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

namespace io_map
{
    // using LedCommOk = PinLocation<GPIOA_BASE, GPIO_PIN_0>;  //COMM Diode
    using LedCommOk = PinLocation<GPIOB_BASE, GPIO_PIN_9>; //tester diode

    // struct XTAL : public PinGroupTag
    // {
    //     struct HF
    //     {
    //         using Pin1 = PinLocation<GPIOD_BASE, GPIO_PIN_0>;
    //         using Pin2 = PinLocation<GPIOD_BASE, GPIO_PIN_1>;
    //     };

    //     struct Group
    //     {
    //         using Pins = PinContainer<HF::Pin1, HF::Pin2>;
    //     };
    // };

    // struct UART_1 : public UARTPins<UART_1>
    // {
    //     static constexpr std::uint32_t* Peripheral          = &USART1_BASE;
    //     static constexpr std::uint32_t  Baudrate            = 115200;
    //     static constexpr std::uint8_t   InterruptPriority   = 6;
    //     static constexpr IRQn_Type      WakeUpInterrupt     = IRQn_Type::USART1_IRQn;
    //     //static constexpr std::uint8_t WakeUpInterruptPriority = 5;

    //     using TX = PinLocation<GPIOA_BASE, GPIO_PIN_9>;
    //     using RX = PinLocation<GPIOA_BASE, GPIO_PIN_10>;
    // };

    struct UART_2 : public UARTPins<UART_2>
    {
        static constexpr std::uint32_t  Peripheral          = USART2_BASE;
        static constexpr std::uint32_t  Baudrate            = 2400;
        static constexpr std::uint32_t  WordLength          = UART_WORDLENGTH_8B;
        static constexpr std::uint32_t  StopBits            = UART_STOPBITS_1;
        static constexpr std::uint32_t  ParityBits          = UART_PARITY_NONE;
        static constexpr std::uint32_t  Mode                = UART_MODE_TX_RX;
        static constexpr std::uint32_t  HwFlowCtl           = UART_HWCONTROL_NONE;
        static constexpr std::uint32_t  OverSampling        = UART_OVERSAMPLING_16;

        static constexpr std::uint8_t   InterruptPriority   = 7;
        static constexpr IRQn_Type      Interrupt           = IRQn_Type::USART2_IRQn;

        using TX = PinLocation<GPIOA_BASE, GPIO_PIN_2>;
        using RX = PinLocation<GPIOA_BASE, GPIO_PIN_3>;
    };

//TODO add I2C functionality
//     struct I2C_1 : public I2CPins<I2C_1>
//     {
//         static constexpr std::uint32_t Location = I2C_ROUTE_LOCATION_LOC0;

//         using SCL = PinLocation<GPIOB_BASE, GPIO_PIN_6>;
//         using SDA = PinLocation<GPIOB_BASE, GPIO_PIN_7>;
//     };

//     struct I2C
//     {
//         static constexpr std::uint8_t InterruptPriority = 6;

//         static constexpr std::uint8_t SystemBus = 1;
//         static constexpr std::uint8_t PayloadBus = 0;
// #ifndef I2C_TIMEOUT
//         static constexpr std::uint32_t Timeout = 5; // in seconds
// #else
//         static constexpr std::uint32_t Timeout = I2C_TIMEOUT; // in seconds
// #endif
//     };


// struct MotorX : public MotorBase
    // {
    //     //
    // };
//     using MotorControlEnable = PinLocation<GPIOB, 9>;

//   //TODO it should be initialized somehow different, as a StepperMotor template maybe?
//     using MotorControlDirX   = PinLocation<GPIOB, GPIO_PIN_10>;
//     using MotorControlStepX  = PinLocation<GPIOB, GPIO_PIN_13>;
//     using MotorControlMsX1   = PinLocation<GPIOB, GPIO_PIN_0>;
//     using MotorControlMsX2   = PinLocation<GPIOB, GPIO_PIN_1>;
//     using MotorControlMsX3   = PinLocation<GPIOB, GPIO_PIN_2>;

//     using MotorControlDirY   = PinLocation<GPIOB, GPIO_PIN_11>;
//     using MotorControlStepY  = PinLocation<GPIOB, GPIO_PIN_14>;
//     using MotorControlMsY1   = PinLocation<GPIOB, GPIO_PIN_3>;
//     using MotorControlMsY2   = PinLocation<GPIOB, GPIO_PIN_4>;
//     using MotorControlMsY3   = PinLocation<GPIOB, GPIO_PIN_5>;

//     using MotorControlDirZ   = PinLocation<GPIOB, GPIO_PIN_12>;
//     using MotorControlStepZ  = PinLocation<GPIOB, GPIO_PIN_15>;
//     using MotorControlMsZ1   = PinLocation<GPIOA, GPIO_PIN_4>;
//     using MotorControlMsZ2   = PinLocation<GPIOA, GPIO_PIN_5>;
//     using MotorControlMsZ3   = PinLocation<GPIOA, GPIO_PIN_6>;

//     using SWDIO              = PinLocation<GPIOA, GPIO_PIN_13>;
//     using SWCLK              = PinLocation<GPIOA, GPIO_PIN_14>;

}

#endif /* ENG_MODEL_MCU_IO_MAP_HPP */

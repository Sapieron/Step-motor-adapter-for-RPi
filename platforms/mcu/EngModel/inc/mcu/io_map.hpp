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
#include "stm32f1xx_hal_gpio.h"

#include "base/io_map.hpp"

namespace io_map
{
    // using LedCommOk = PinLocation<GPIOA_BASE, GPIO_PIN_0>;  //COMM Diode
    using LedCommOk = PinLocation<GPIOB_BASE, GPIO_PIN_9>; //tester diode

    struct XTAL : public PinGroupTag
    {
        struct HF
        {
            using Pin1 = PinLocation<GPIOD_BASE, GPIO_PIN_0>;
            using Pin2 = PinLocation<GPIOD_BASE, GPIO_PIN_1>;
        };

        struct Group
        {
            using Pins = PinContainer<HF::Pin1, HF::Pin2>;
        };
    };

    // struct MotorX : public MotorBase
    // {
    //     //
    // };
//     using MotorControlEnable = PinLocation<GPIOB, 9>;

//   //TODO it should be initialized somehow different, as a StepperMotor template maybe?
//     using MotorControlDir1   = PinLocation<GPIOB, 10>;
//     using MotorControlDir2   = PinLocation<GPIOB, 11>;
//     using MotorControlDir3   = PinLocation<GPIOB, 12>;

//     using MotorControlStep1  = PinLocation<GPIOB, 13>;
//     using MotorControlStep2  = PinLocation<GPIOB, 14>;
//     using MotorControlStep3  = PinLocation<GPIOB, 15>;

//     /* Step resolution pins */
//     using MotorControlMS11   = PinLocation<GPIOB, 0>;
//     using MotorControlMS12   = PinLocation<GPIOB, 1>;
//     using MotorControlMS13   = PinLocation<GPIOB, 2>;

//     using MotorControlMS21   = PinLocation<GPIOB, 3>;
//     using MotorControlMS22   = PinLocation<GPIOB, 4>;
//     using MotorControlMS23   = PinLocation<GPIOB, 5>;

//     using MotorControlMS31   = PinLocation<GPIOA, 4>;
//     using MotorControlMS32   = PinLocation<GPIOA, 5>;
//     using MotorControlMS33   = PinLocation<GPIOA, 6>;

//     using SWDIO              = PinLocation<GPIOA, 13>;
//     using SWCLK              = PinLocation<GPIOA, 14>;

    //FIXME add UART
    // struct UART_1 : public UARTPins<UART_1>
    // {
    //     static constexpr std::uint32_t* Peripheral          = &USART1_BASE;
    //     static constexpr std::uint32_t  Baudrate            = 115200;
    //     static constexpr std::uint8_t   InterruptPriority   = 6;
    //     static constexpr IRQn_Type      WakeUpInterrupt     = IRQn_Type::USART1_IRQn;
    //     //static constexpr std::uint8_t WakeUpInterruptPriority = 5;

    //     using TX = PinLocation<GPIOA_BASE, 9>;
    //     using RX = PinLocation<GPIOA_BASE, 10>;
    // };

    // struct UART_2 : public UARTPins<UART_2>
    // {
    //     static constexpr std::uint32_t* Periheral           = &USART2_BASE;
    //     static constexpr std::uint32_t  Baudrate            = 115200;
    //     static constexpr std::uint8_t   InterruptPriority   = 7;
    //     static constexpr IRQn_Type      WakeUpInterrupt     = IRQn_Type::USART2_IRQn;
    //     //static constexpr std::uint8_t WakeUpInterruptPriority = 5;

    //     using TX = PinLocation<GPIOA_BASE, 2>;
    //     using RX = PinLocation<GPIOA_BASE, 3>;
    // };

//TODO add I2C functionality
//     struct I2C_1 : public I2CPins<I2C_1>
//     {
//         static constexpr std::uint32_t Location = I2C_ROUTE_LOCATION_LOC0;

//         using SCL = PinLocation<GPIOB_BASE, 6>;
//         using SDA = PinLocation<GPIOB_BASE, 7>;
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

}

#endif /* ENG_MODEL_MCU_IO_MAP_HPP */

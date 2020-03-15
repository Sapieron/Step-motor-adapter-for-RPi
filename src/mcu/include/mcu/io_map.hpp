/**
 * @file io_map.hpp
 * @author https://github.com/Sapieron
 * @brief  This file contains all peripheral pin mappings
 * 
 * @version 0.1
 * @date 2020-03-14
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef MCU_IO_MAP_HPP
#define MCU_IO_MAP_HPP

#include <cstdint>

#include "stm32f103xb.h"
#include "stm32f1xx_hal_gpio.h"

#include "templates/io_map.hpp"

namespace io_map
{
    using LedCommOk = PinLocation<GPIOA_BASE, GPIO_PIN_0>;

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

//TODO add UART functionality
//     struct UART_1 : public UARTPins<UART_1>
//     {
//         static constexpr USART_TypeDef* Peripheral = USART1;
// //        static constexpr std::uint32_t Location = UART_ROUTE_LOCATION_LOC2;
//         static constexpr std::uint32_t Baudrate = 115200;
//         static constexpr std::uint8_t InterruptPriority = 6;
//         static constexpr IRQn_Type WakeUpInterrupt = IRQn_Type::USART1_IRQn;
//         static constexpr std::uint8_t WakeUpInterruptPriority = 5;

//         using TX = PinLocation<GPIOA, 9>;
//         using RX = PinLocation<GPIOA, 10>;
//     };

//     struct UART_2 : public UARTPins<UART_2>
//     {
//         static constexpr USART_TypeDef* Peripheral = USART2;
// //        static constexpr std::uint32_t Location = UART_ROUTE_LOCATION_LOC2;
//         static constexpr std::uint32_t Baudrate = 115200;
//         static constexpr std::uint8_t InterruptPriority = 6;
//         static constexpr IRQn_Type WakeUpInterrupt = IRQn_Type::USART2_IRQn;
//         static constexpr std::uint8_t WakeUpInterruptPriority = 5;

//         using TX = PinLocation<GPIOA, 2>;
//         using RX = PinLocation<GPIOA, 3>;
//     };

//TODO add I2C functionality
//     struct I2C_1 : public I2CPins<I2C_1>
//     {
//         static constexpr std::uint32_t Location = I2C_ROUTE_LOCATION_LOC0;

//         using SCL = PinLocation<GPIOB, 6>;
//         using SDA = PinLocation<GPIOB, 7>;
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

#endif /* MCU_IO_MAP_HPP */

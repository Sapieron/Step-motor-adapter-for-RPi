/**
 * @file gpio.hpp
 * @author Pawel Klisz (pawelochojec@gmail.com)
 * @brief  Contains template structures describing peripheral pins,
 *         initialization functions
 * @version 0.1
 * @date 2020-02-27
 * 
 * @copyright Copyright (c) 2020 by Pawel Klisz. All rights reserved
 * 
 * Released under the terms of the GNU General Public License version 3 or later.
 * For full license please refer to LICENSE.txt
 * 
 * This project can be found on https://github.com/Sapieron/Step-motor-adapter-for-RPi
 * 
 */

#ifndef LIBS_BOARD_HARDWARE_INCLUDE_BOARD_GPIO_H_
#define LIBS_BOARD_HARDWARE_INCLUDE_BOARD_GPIO_H_

#pragma once

#include "stm32f1xx_hal_gpio.h"
#include "stm32f1xx_hal_rcc.h"


#include "gpio/forward.hpp"
#include "gpio/driver.hpp"

#include "mcu/io_map.hpp"
#include "gpio_internal.hpp"

namespace board
{
    /**
     * @defgroup obc_hardware_gpio OBC GPIO
     * @ingroup obc_hardware
     *
     * @{
     */
    //TODO add I2C functionality
    // /** @brief Structure describing I2C pins */
    // template <typename Location> struct I2CPins
    // {
    //     /** @brief SDA */
    //     const drivers::gpio::OutputPin<typename Location::SDA> SDA;
    //     /** @brief SCL */
    //     const drivers::gpio::OutputPin<typename Location::SCL> SCL;

    //     /** @brief Initializes I2C pins */
    //     void Initialize() const
    //     {
    //         this->SDA.Initialize();
    //         this->SCL.Initialize();
    //     }
    // };

    /** @brief Structure describing UART pins */
    template <typename Location> struct UARTPins
    {
        /** @brief TX */
        const drivers::gpio::OutputPinAF<typename Location::TX> TX;   //FIXME maybe using TX = ... would be better?
        /** @brief RX */
        const drivers::gpio::InputPinAF<typename Location::RX> RX;
        /** @brief Initializes UART pins */
        void Initialize() const
        {
            this->TX.Initialize();
            this->RX.Initialize();
        }
    };

    /**
     * @brief Composes all used GPIO pins together
     *
     * @remark All used pin locations must derive from tags defined in template/io_map.hpp
     */
    template <typename TCommOkIndicator,
        // typename TUART1,
        typename TUART2
        // typename TI2C0,
        >
    struct BoardGPIOBase
    {
        /** @brief LedCommOk onboard green led */
        const drivers::gpio::OutputPin<TCommOkIndicator, DISABLE> LedCommOk;

        /** @brief UART1 */
        // const UARTPins<TUART1> UART_1;   //TODO not yet implemented

        /** @brief UART2 */
        const UARTPins<TUART2> UART_2;

        // /** @brief I2C0 */
        // const I2CPins<TI2C0> I2C_0;   //TODO not yet implemented

        /** @brief Motor 1 */
        //const MOTORPins<TMOTOR1> MOTOR_1;   //TODO not yet implemented

        /** @brief Motor 2 */
        //const MOTORPins<TMOTOR2> MOTOR_2;   //TODO not yet implemented

        /** @brief Motor 3*/
        //const MOTORPins<TMOTOR3> MOTOR_3;   //TODO not yet implemented

        /** @brief Gripper */
        //const drivers::gpio::OutputPin<TGripper, DISABLE> Gripper;   //TODO not yet implemented

        /** @brief Initializes GPIO pins */
        void Initialize() const
        {
            this->LedCommOk.Initialize();
            // this->UART_1.Initialize();
            this->UART_2.Initialize();
            // this->I2C_0.Initialize();
        }
    };

    /** @brief Connects GPIO pins to IO map */
    using BOARDGPIO = gpio::VerifyPinsUniqueness<BoardGPIOBase,
        io_map::LedCommOk,
        // io_map::UART_1,
        io_map::UART_2
        // io_map::I2C_0,
        //io_map::XTAL
        >;

    /** @} */
}

#endif /* LIBS_BOARD_HARDWARE_INCLUDE_BOARD_GPIO_H_ */

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

#include "TargetsDefines.hpp"

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

    /** @brief Structure describing UART pins */
    template <typename Location> struct UARTPins
    {
        /** @brief TX */
        const drivers::gpio::OutputPinAF<typename Location::TX> TX;
        /** @brief RX */
        const drivers::gpio::InputPinAF<typename Location::RX> RX;
        /** @brief Initializes UART pins */
        void Initialize() const
        {
            this->TX.Initialize();
            this->RX.Initialize();
        }
    };

    template <typename Location> struct MotorPins
    {
        const drivers::gpio::OutputPin<typename Location::Dir>      Dir;
        const drivers::gpio::OutputPin<typename Location::Ms1>      Ms1;
        const drivers::gpio::OutputPin<typename Location::Ms2>      Ms2;
        const drivers::gpio::OutputPin<typename Location::Ms3>      Ms3;
        const drivers::gpio::CustomPin<typename Location::Step>     Step;
                                    //    typename Config::Step>       Step;

        void Initialize() const
        {
            this->Dir.Initialize();
            this->Ms1.Initialize();
            this->Ms2.Initialize();
            this->Ms3.Initialize();
            this->Step.Initialize();
        }
    };

    /**
     * @brief Composes all used GPIO pins together
     *
     * @remark All used pin locations must derive from tags defined in template/io_map.hpp
     */
    template <typename TCommOkIndicator,
              typename TUART3,
              typename TMotor_X,
              typename TMotor_Y,
              typename TMotor_Z >
    struct BoardGPIOBase
    {
        /** @brief LedCommOk onboard green led */
        const drivers::gpio::OutputPin<TCommOkIndicator, DISABLE> LedCommOk;

        /** @brief UART2 */
        const UARTPins<TUART3> UART_3;

        /** @brief Motor 1 */
        const MotorPins<TMotor_X> Motor_X;

        /** @brief Motor 2 */
        const MotorPins<TMotor_Y> Motor_Y;

        /** @brief Motor 3*/
        const MotorPins<TMotor_Z> Motor_Z;

        /** @brief Gripper */
        //const drivers::gpio::OutputPin<TGripper, DISABLE> Gripper;   //TODO not yet implemented

        /** @brief Initializes GPIO pins */
        void Initialize() const
        {
            this->LedCommOk.Initialize();
            this->UART_3.Initialize();
            this->Motor_X.Initialize();
            this->Motor_Y.Initialize();
            this->Motor_Z.Initialize();
        }
    };

    /** @brief Connects GPIO pins to IO map */
    using BOARDGPIO = gpio::VerifyPinsUniqueness<BoardGPIOBase,
        io_map::LedCommOk,
        io_map::UART_3,
        io_map::Motor_X,
        io_map::Motor_Y,
        io_map::Motor_Z>;

    /** @} */
}

#endif /* LIBS_BOARD_HARDWARE_INCLUDE_BOARD_GPIO_H_ */

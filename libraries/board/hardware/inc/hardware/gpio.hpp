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
#include "gpio/gpio.hpp"

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

    /**
     * @brief Structure describing UART pins
     * 
     * @tparam Location 
     */
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

    /**
     * @brief Structure describing MotorPins
     * 
     * @tparam Location 
     */
    template <typename Location> struct MotorPins
    {
        /** @brief Dir pin */
        const drivers::gpio::OutputPin<typename Location::Dir>      Dir;

        /** @brief Ms1 pin */
        const drivers::gpio::OutputPin<typename Location::Ms1>      Ms1;

        /** @brief Ms2 pin */
        const drivers::gpio::OutputPin<typename Location::Ms2>      Ms2;

        /** @brief Ms3 pin */
        const drivers::gpio::OutputPin<typename Location::Ms3>      Ms3;

        /** @brief Step pin */
        const drivers::gpio::OutputPin<typename Location::Step>     Step;

        /** @brief Initializes pins MotorPins */
        void Initialize() const
        {
            this->Dir.Initialize();
            this->Ms1.Initialize();
            this->Ms2.Initialize();
            this->Ms3.Initialize();
            this->Step.Initialize();
        }
    };

    template <typename Location>
    struct DigitalSensorPins
    {
        struct Options
        {
            static constexpr auto Mode  = GPIO_MODE_IT_RISING_FALLING;   //FIXME interrupt or event? event should be menaged by os, am I right?
            static constexpr auto Pull  = GPIO_NOPULL;
            static constexpr auto Speed = GPIO_SPEED_FREQ_LOW;
        };

        /** @brief SIG pin */
        const drivers::gpio::CustomPin<typename Location::SIG,
                                                Options> SIG;

        /** @brief Initializes digital sensor pins */
        void Initialize() const
        {
            this->SIG.Initialize();
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
              typename TMotor_Z,
              typename TWaterSensor_1>
    struct BoardGPIOBase
    {
        /** @brief LedCommOk onboard green led */
        const drivers::gpio::OutputPin<TCommOkIndicator, FunctionalState::DISABLE> LedCommOk;

        /** @brief UART2 */
        const UARTPins<TUART3> UART_3;

        /** @brief Motor 1 */
        const MotorPins<TMotor_X> Motor_X;

        /** @brief Motor 2 */
        const MotorPins<TMotor_Y> Motor_Y;

        /** @brief Motor 3*/
        const MotorPins<TMotor_Z> Motor_Z;

        /** @brief Water Sensor 1 */
        const DigitalSensorPins<TWaterSensor_1> WaterSensor_1;

        /** @brief Initializes GPIO pins */
        void Initialize() const
        {
            this->LedCommOk.Initialize();
            this->UART_3.Initialize();
            this->Motor_Y.Initialize();
            this->WaterSensor_1.Initialize();

        #ifndef DEVBOARD
            this->Motor_X.Initialize();
            this->Motor_Z.Initialize();
        #endif
        }
    };

    /** @brief Connects GPIO pins to IO map */
    using BOARDGPIO = gpio::VerifyPinsUniqueness<BoardGPIOBase,
                                                 io_map::LedCommOk,
                                                 io_map::UART_3,
                                                 io_map::Motor_X,
                                                 io_map::Motor_Y,
                                                 io_map::Motor_Z,
                                                 io_map::WaterSensor_1>;

    /** @} */
}

#endif /* LIBS_BOARD_HARDWARE_INCLUDE_BOARD_GPIO_H_ */

/**
 * @file hardware.hpp
 * @author Pawel Klisz (pawelochojec@gmail.com)
 * @brief  This file contains initializations of hardware
 *         peripherals
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

#ifndef MCU_HARDWARE_HPP
#define MCU_HARDWARE_HPP

#pragma once

/******************************************************************************\
 *                             Includes
\******************************************************************************/
#include "gpio.hpp"
#include "terminal/terminal.hpp"
#include "uart/uart.hpp"
#include "A4988/A4988.hpp"
#include "motorController/motor_controller.hpp"
#include "FS-IR02/FS-IR02.hpp"

#include "base/clock.hpp"
#include "mcu/config.hpp"


/******************************************************************************\
 *                             Code
\******************************************************************************/
namespace board
{
    /**
     * @defgroup board_hardware BOARD Hardware
     * @ingroup board
     * 
     * @{
     */

    /**
     * @brief BOARDHardware - structure containing all hardware drivers
     * 
     */
    struct BOARDHardware final
    {
        /** @brief Initializes board hardware  */
        void Initialize();

        /** @brief Board's clock handler */
        config::clock::Clock<config::Clock> ClockHandler;

        /** @brief Board pins */
        BOARDGPIO Pins;

        /** @brief Terminal interface */
        drivers::uart::UART<io_map::UART_3> Terminal;

        /** @brief Motor X controller */
        drivers::a4988::A4988<io_map::Motor_X> MotorX;

        /** @brief Motor Y controller */
        drivers::a4988::A4988<io_map::Motor_Y> MotorY;

        /** @brief Motor Z controller */
        drivers::a4988::A4988<io_map::Motor_Z> MotorZ;

        /** @brief Water sensor controller *///FIXME temporary, should be done within waterpump controller
        drivers::fs_ir02::FS_IR02<io_map::WaterSensor_1> WaterSensor1;
    };

    /** @} */
}


/******************************************************************************\
 *                             End of file
\******************************************************************************/
#endif /* MCU_HARDWARE_HPP */
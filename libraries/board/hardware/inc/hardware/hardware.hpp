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
#include "motorController/motorController.hpp"

#include "base/clock.hpp"
#include "mcu/config.hpp"


/******************************************************************************\
 *                             Code
\******************************************************************************/
namespace board
{
    struct BOARDHardware final
    {
        void Initialize();

        config::clock::Clock<config::Clock> ClockHandler;

        BOARDGPIO Pins;

        drivers::uart::UART<io_map::UART_2> Terminal;

        devices::motorController::MotorController<io_map::Motor_X,
                                                  io_map::Motor_Y,
                                                  io_map::Motor_Z> SyncMovementController;
    };
}


/******************************************************************************\
 *                             End of file
\******************************************************************************/
#endif /* MCU_HARDWARE_HPP */
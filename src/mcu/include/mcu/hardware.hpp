/**
 * @file hardware.hpp
 * @author https://github.com/Sapieron
 * @brief  This file contains initializations of hardware
 *         peripherals
 * 
 * @version 0.1
 * @date 2020-02-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef MCU_HARDWARE_HPP
#define MCU_HARDWARE_HPP

#include "mcu/gpio.hpp"

namespace board
{
    struct BOARDHardware final
    {
        void Initialize();

        BOARDGPIO Pins;

        //drivers::uart::UART<io_map::UART_0> Terminal;   //TODO add terminal to communicate with SBC

        //drivers::gpio::Pin        //TODO is this needed?
    };
}



#endif /* MCU_HARDWARE_HPP */
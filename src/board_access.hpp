/**
 * @file board_access.hpp
 * @author Pawel Klisz (pawelochojec@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-05-09
 * 
 * @copyright Copyright (c) 2020 by Pawel Klisz. All rights reserved
 * 
 * Released under the terms of the GNU General Public License version 3 or later.
 * For full license please refer to LICENSE.txt
 * 
 * This project can be found on https://github.com/Sapieron/Step-motor-adapter-for-RPi
 * 
 */

#ifndef BOARD_ACCESS_HPP
#define BOARD_ACCESS_HPP

/******************************************************************************\
 * 						        Includes
\******************************************************************************/
#include "terminal/forward.hpp"
#include "motorController/forward.hpp"

/******************************************************************************\
 * 						         CODE
\******************************************************************************/

devices::terminal::Terminal& GetTerminal();

// inline auto& GetMotorController()
// {
//     return Main.motorController;
// }

// inline auto& GetLedCommOk()
// {
//     return Main.Hardware.Pins.LedCommOk;
// }
#endif /* BOARD_ACCESS_HPP */

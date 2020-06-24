/**
 * @file board.hpp
 * @author Pawel Klisz (pawelochojec@gmail.com)
 * @brief 
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

#include "hardware/hardware.hpp"
#include "terminal/terminal.hpp"
// #include "motorController/motorController.hpp"

/**
 * @brief Object describing global BOARD state and drivers
 */
struct BOARD
{
public:
    BOARD();

    /** @brief BOARD hardware */
    board::BOARDHardware Hardware;

    /** @brief Terminal object */
    devices::terminal::Terminal terminal;

    // /** @brief motorController object */
    // devices::motorController::MotorController<io_map::Motor_X,
    //                                           io_map::Motor_Y,
    //                                           io_map::Motor_Z> motorController;  //TODO It has to instantiate other class
};

/**
 * @brief Global BOARD object
 * 
 */
extern BOARD Main;
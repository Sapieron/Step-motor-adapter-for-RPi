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

/**
 * @brief Object describing global BOARD state and drivers
 */
struct BOARD
{
    public:
        BOARD();

    /** @brief OBC hardware */
    board::BOARDHardware Hardware;
};

/**
 * @brief Global OBC object
 * 
 */
extern BOARD Main;
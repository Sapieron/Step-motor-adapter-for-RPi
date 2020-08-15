/**
 * @file types.hpp
 * @author Pawel Klisz (pawelochojec@gmail.com)
 * @brief This file contains types specific for motor controller.
 *        It is bound to @ref AdapterAPI (https://github.com/Sapieron/AdapterAPI)
 * @version 0.1
 * @date 2020-07-26
 * 
 * @copyright Copyright (c) 2020 by Pawel Klisz. All rights reserved
 * 
 * Released under the terms of the GNU General Public License version 3 or later.
 * For full license please refer to LICENSE.txt
 * 
 * This project can be found on https://github.com/Sapieron/Step-motor-adapter-for-RPi
 * 
 */

#ifndef MOTORCONTROLLER_TYPES_HPP
#define MOTORCONTROLLER_TYPES_HPP

#pragma once

/******************************************************************************\
 *                                Includes
\******************************************************************************/
#include <cstdint>

/******************************************************************************\
 *                                 Code
\******************************************************************************/

namespace devices
{
    namespace motorController
    {
        /** @brief Size of command frame in bytes */
        constexpr std::uint8_t CommandFrameSize = 21U;

        /** @brief Possible Motor Controller's commands */
        enum class MotorControllerCmd
        {
            SayHelloWorld            = 0x30U,
            MoveToCoordinate         = 0x31U,
            RotateStepper            = 0x32U,
            SetCurrentPositionAsZero = 0x33U,
            ForceStopMovement        = 0x34U,
            ForceStopAll             = 0x35U,
            RotateFoodDispenser      = 0x36U,
            RotateWaterPump          = 0x37U,
            FeedWater                = 0x38U
        };
    } // namespace motorController
    
} // namespace devices



/******************************************************************************\
 *                              End of file
\******************************************************************************/
#endif /* MOTORCONTROLLER_TYPES_HPP */
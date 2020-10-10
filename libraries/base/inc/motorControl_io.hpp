/**
 * @file motorControl_io.hpp
 * @author Pawel Klisz (pawelochojec@gmail.com)
 * @brief Provides common interface for controlling stepper motors
 * @version 0.1
 * @date 2020-08-12
 * 
 * @copyright Copyright (c) 2020 by Pawel Klisz. All rights reserved
 * 
 * Released under the terms of the GNU General Public License version 3 or later.
 * For full license please refer to LICENSE.txt
 * 
 * This project can be found on https://github.com/Sapieron/Step-motor-adapter-for-RPi
 * 
 */

#ifndef MOTORCONTROL_IO_BASE_HPP
#define MOTORCONTROL_IO_BASE_HPP

#pragma once

/******************************************************************************\
 *                                 Includes
\******************************************************************************/
#include <cstdint>
#include <cstdarg>


/******************************************************************************\
 *                                  Code
\******************************************************************************/
/**
 * @brief API for MotorControl interface
 * 
 */
class IMotorControlIO
{
public:
    /**
     * @brief Default ctor
     * 
     */
    IMotorControlIO() = default;

    /**
     * @brief Default destructor
     * 
     */
    ~IMotorControlIO() = default;

    /**
     * @brief Function that moves motor to given coordinate
     * 
     * @param coordinate coordinate to move to
     */
    virtual void MoveToCoordinate(std::vector<float> coordinate) = 0;

    /**
     * @brief Function that rotates motor by given rotations
     * 
     * @param rotations rotations to do
     */
    virtual void Rotate(std::vector<float> rotations) = 0;

    /**
     * @brief Sets current position of motor to be treated as 0
     * 
     */
    virtual void SetCurrentPositionAsZero() = 0;
};

/******************************************************************************\
 *                                 End of file
\******************************************************************************/
#endif /* MOTORCONTROL_IO_BASE_HPP */

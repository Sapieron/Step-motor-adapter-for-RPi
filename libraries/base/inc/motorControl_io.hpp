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

#include <cstdint>
#include <cstdarg>

class IMotorControlIO
{

public:
    IMotorControlIO() = default;
    ~IMotorControlIO() = default;

    virtual void MoveToCoordinate(std::int32_t args...) = 0;

    virtual void Rotate(std::int32_t args...) = 0;

    virtual void SetCurrentPositionAsZero() = 0;
};


#endif /* MOTORCONTROL_IO_BASE_HPP */
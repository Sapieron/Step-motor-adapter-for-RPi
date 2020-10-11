/**
 * @file digitalSensor_io.hpp
 * @author Pawel Klisz (pawelochojec@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-10-11
 * 
 * @copyright Copyright (c) 2020 by Pawel Klisz. All rights reserved
 * 
 * Released under the terms of the GNU General Public License version 3 or later.
 * For full license please refer to LICENSE.txt
 * 
 * This project can be found on https://github.com/Sapieron/Step-motor-adapter-for-RPi
 * 
 */

#ifndef DIGITAL_SENSOR_IO_BASE_HPP
#define DIGITAL_SENSOR_IO_BASE_HPP

/**
 * @brief Provides common interface for digital sensors control
 * 
 */
class IDigitalSensorIO
{
  public:
    IDigitalSensorIO() = default;
    ~IDigitalSensorIO() = default;

    //TODO To be implemented with water pump controller
};


#endif /* DIGITAL_SENSOR_IO_BASE_HPP */
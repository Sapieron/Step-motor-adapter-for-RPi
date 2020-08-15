/**
 * @file utils.hpp
 * @author Pawel Klisz (pawelochojec@gmail.com)
 * @brief  Utilites definitions 
 * @version 0.1
 * @date 2020-04-09
 * 
 * @copyright Copyright (c) 2020 by Pawel Klisz. All rights reserved
 * 
 * Released under the terms of the GNU General Public License version 3 or later.
 * For full license please refer to LICENSE.txt
 * 
 * This project can be found on https://github.com/Sapieron/Step-motor-adapter-for-RPi
 * 
 */

#ifndef BASE_UTILS_HPP
#define BASE_UTILS_HPP

#pragma once

/******************************************************************************\
 *                             Includes
\******************************************************************************/
/* Standard Library includes*/
#include <cstdint>

/******************************************************************************\
 *                              Code
\******************************************************************************/

/**
 * @brief Marker - indicates that value is in Hz
 * @param value - value to be converted
 * @return value in Hz
 */
constexpr std::uint64_t operator"" _Hz(std::uint64_t value)
{
    return value;
}

/**
 * @brief Marker - indicates value is in kHz
 * @param value - value to be converted
 * @return value in kHz
 */
constexpr std::uint64_t operator"" _kHz(std::uint64_t value)
{
    return value * 1000_Hz;
}

/**
 * @brief Marker - indicates value is in MHz
 * @param value - value to be converted
 * @return value in MHz
 */
constexpr std::uint64_t operator"" _MHz(std::uint64_t value)
{
    return value * 1000_kHz;
}

/**
 * @brief Marker - indicates value is micro seconds
 * @param value - value to be converted
 * @return value in microseconds
 */
constexpr std::uint64_t operator"" _us(std::uint64_t value)
{
    return value;
}

/**
 * @brief Marker - indicates value refers to rpm
 * @param value - value to be converted
 * @return value in rpm
 */
constexpr std::uint64_t operator"" _rpm(std::uint64_t value)
{
    return value;
}

/**
 * @brief Marker to indicate value is in percents
 * 
 * @param value 
 * @return constexpr std::uint32_t 
 */
constexpr std::uint32_t operator""_percent(std::uint64_t value)
{
    return value;
}

/**
 * @brief Marker - indicates value is in bytes
 * 
 * @param value 
 * @return value in bytes
 */
constexpr std::uint32_t operator""_B(std::uint64_t value)
{
    return value;
}

/**
 * @brief Marker - indicates value is in kilobytes
 * 
 * @param value 
 * @return value in kilobytes 
 */
constexpr std::uint32_t operator""_kB(std::uint64_t value)
{
    return value * 1024_B;
}

/******************************************************************************\
 *                            End of file
\******************************************************************************/
#endif /* BASE_UTILS_HPP */
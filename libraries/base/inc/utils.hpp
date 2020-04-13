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
 * 								Includes
\******************************************************************************/
/* Standard Library includes*/
#include <cstdint>

/******************************************************************************\
 * 								 CODE
\******************************************************************************/

/**
 * @brief Marker - indicates that value is in Hz
 * @param value - value to be converted
 * @return value in Hz
 */
constexpr std::uint32_t operator"" _Hz(unsigned long long int value)
{
    return value;
}

/**
 * @brief Marker - indicates value is in kHz
 * @param value - value to be converted
 * @return value in kHz
 */
constexpr std::uint32_t operator"" _kHz(unsigned long long int value)
{
    return value * 1000_Hz;
}

/**
 * @brief Marker - indicates value is in MHz
 * @param value - value to be converted
 * @return value in MHz
 */
constexpr std::uint32_t operator"" _MHz(unsigned long long int value)
{
    return value * 1000_kHz;
}



#endif /* BASE_UTILS_HPP */
/**
 * @file types.hpp
 * @author Pawel Klisz (pawelochojec@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-03-17
 * 
 * @copyright Copyright (c) 2020 by Pawel Klisz. All rights reserved
 * 
 * Released under the terms of the GNU General Public License version 3 or later.
 * For full license please refer to LICENSE.txt
 * 
 * This project can be found on https://github.com/Sapieron/Step-motor-adapter-for-RPi
 * 
 */


#ifndef TERMINAL_TYPES_HPP
#define TERMINAL_TYPES_HPP

#pragma once

#include <cstdint>

namespace devices
{
    namespace terminal
    {
        constexpr std::uint8_t CommandFrameSize = 8U;
    } // namespace terminal
    
} // namespace devices


#endif /* TERMINAL_TYPES_HPP */
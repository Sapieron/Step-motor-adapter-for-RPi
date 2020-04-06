/**
 * @file command_factory.hpp
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

#ifndef TERMINAL_COMMAND_FACTORY_HPP
#define TERMINAL_COMMAND_FACTORY_HPP

#pragma once

#include "terminal/types.hpp"
#include <cstdint>

namespace devices
{
    namespace terminal
    {
        class CommandFactory
        {
          public:
          /** @brief Type describing Frame buffer */
            using Frame = gsl::span<std::uint8_t, CommandFrameSize>; 
        };
    } // namespace terminal
    
} // namespace devices


#endif /* TERMINAL_COMMAND_FACTORY_HPP */
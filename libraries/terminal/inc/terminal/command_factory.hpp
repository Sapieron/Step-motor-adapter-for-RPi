/**
 * @file command_factory.hpp
 * @author https://github.com/Sapieron
 * @brief 
 * @version 0.1
 * @date 2020-03-17
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef TERMINAL_COMMAND_FACTORY_HPP
#define TERMINAL_COMMAND_FACTORY_HPP

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
/**
 * @file configuration.hpp
 * @author Pawel Klisz (pawelochojec@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-06-13
 * 
 * @copyright Copyright (c) 2020 by Pawel Klisz. All rights reserved
 * 
 * Released under the terms of the GNU General Public License version 3 or later.
 * For full license please refer to LICENSE.txt
 * 
 * This project can be found on https://github.com/Sapieron/Step-motor-adapter-for-RPi
 * 
 */

#ifndef TIMER_CONFIGURATION_HPP
#define TIMER_CONFIGURATION_HPP

/******************************************************************************\
 *                             Includes
\******************************************************************************/
/** @brief Deliver register & peripheral definitions */
#include "TargetsDefines.hpp"

/******************************************************************************\
 *                               Code
\******************************************************************************/

namespace drivers
{
    namespace timer
    {
        template <std::uint32_t SlaveTimer>
        struct Config;

        template<>
        struct Config<TIM1_BASE>
        {
            static constexpr auto slaveTimer    = TIM1_BASE;
            static constexpr auto masterTimer   = TIM2_BASE;
        };
    } // namespace timer
    
} // namespace drivers


/******************************************************************************\
 *                              End of file
\******************************************************************************/
#endif /* TIMER_CONFIGURATION_HPP */
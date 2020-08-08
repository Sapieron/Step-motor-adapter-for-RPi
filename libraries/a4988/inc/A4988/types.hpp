/**
 * @file types.hpp
 * @author Pawel Klisz (pawelochojec@gmail.com)
 * @brief Contatins MCU specific definitions of timer master-slave configuration,
 * that are provided to A4988 driver.
 * @version 0.1
 * @date 2020-08-06
 * 
 * @copyright Copyright (c) 2020 by Pawel Klisz. All rights reserved
 * 
 * Released under the terms of the GNU General Public License version 3 or later.
 * For full license please refer to LICENSE.txt
 * 
 * This project can be found on https://github.com/Sapieron/Step-motor-adapter-for-RPi
 * 
 */

#ifndef A4988_TYPES_HPP
#define A4988_TYPES_HPP

/******************************************************************************\
 *                             Includes
\******************************************************************************/
/** @brief Deliver register & peripheral definitions */
#include "TargetsDefines.hpp"

/******************************************************************************\
 *                               Code
\******************************************************************************/

namespace devices
{
    namespace a4988
    {
        /**
         * @defgroup a4988_driver A4988 Driver
         * @ingroup BSP
         */

        /**
         * @brief a4988_driver
         * @ingroup a4988_driver
         */

        /**
         * @brief Master-slave timer configuration for specified SlaveTimer
         * 
         * @tparam SlaveTimer 
         */
        template <std::uint32_t SlaveTimer> //FIXME add template parameter of MCU selected
        struct Config;

        /**
         * @brief Timers configuration for TIM1_BASE
         */
        template<>
        struct Config<TIM1_BASE>
        {
            static constexpr auto slaveTimer    = TIM1_BASE;
            static constexpr auto masterTimer   = TIM2_BASE;

            static constexpr auto slaveTimerITR = TIM_TS_ITR1;
            static constexpr auto masterTimerITR = TIM_TS_ITR0;
        };

        /**
         * @brief Timers configuration for TIM8_BASE
         */
        template<>
        struct Config<TIM8_BASE>
        {
            static constexpr auto slaveTimer    = TIM8_BASE;
            static constexpr auto masterTimer   = TIM4_BASE;

            static constexpr auto slaveTimerITR = TIM_TS_ITR2;
            static constexpr auto masterTimerITR = TIM_TS_ITR3;
        };

        /**
         * @brief Timers configuration for TIM12_BASE
         */
        template<>
        struct Config<TIM12_BASE>
        {
            static constexpr auto slaveTimer    = TIM12_BASE;
            static constexpr auto masterTimer   = TIM5_BASE;

            static constexpr auto slaveTimerITR = TIM_TS_ITR1;
            static constexpr auto masterTimerITR = TIM_TS_ITR0; //FIXME it's dummy, doesn't meet table
        };

    } // namespace a4988
    
} // namespace devices


/******************************************************************************\
 *                              End of file
\******************************************************************************/
#endif /* A4988_TYPES_HPP */
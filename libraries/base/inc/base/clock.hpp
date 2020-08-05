/**
 * @file config.hpp
 * @author Pawel Klisz (pawelochojec@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-06-14
 * 
 * @copyright Copyright (c) 2020 by Pawel Klisz. All rights reserved
 * 
 * Released under the terms of the GNU General Public License version 3 or later.
 * For full license please refer to LICENSE.txt
 * 
 * This project can be found on https://github.com/Sapieron/Step-motor-adapter-for-RPi
 * 
 */

#ifndef BASE_CLOCK_HPP
#define BASE_CLOCK_HPP

/******************************************************************************\
 *                             Includes
\******************************************************************************/
#include "TargetsDefines.hpp"

/******************************************************************************\
 *                              Code
\******************************************************************************/
namespace config
{
    namespace clock
    {
        template <typename ClockConfig>
        struct Clock final
        {
        public:
            void Initialize();

        private:
            RCC_OscInitTypeDef _oscInitStruct;
            RCC_ClkInitTypeDef _clkInitStruct;
        };

        template <typename ClockConfig>
        void Clock<ClockConfig>::Initialize()
        {
            _oscInitStruct.OscillatorType       = ClockConfig::OscillatorType;
            _oscInitStruct.HSIState             = ClockConfig::HSIState;
            _oscInitStruct.HSEState             = ClockConfig::HSEState;
            _oscInitStruct.LSEState             = ClockConfig::LSEState;
            _oscInitStruct.LSIState             = ClockConfig::LSIState;
            _oscInitStruct.HSICalibrationValue  = ClockConfig::HSICalibrationValue;
            _oscInitStruct.PLL.PLLState         = ClockConfig::PLL_PLLState;
            _oscInitStruct.PLL.PLLSource        = ClockConfig::PLL_PLLSource;
            _oscInitStruct.PLL.PLLMUL           = ClockConfig::PLL_PLLMUL;

            _clkInitStruct.ClockType            = ClockConfig::ClockType;
            _clkInitStruct.SYSCLKSource         = ClockConfig::SYSCLKSource;
            _clkInitStruct.AHBCLKDivider        = ClockConfig::AHBCLKDivider;
            _clkInitStruct.APB1CLKDivider       = ClockConfig::APB1CLKDivider;
            _clkInitStruct.APB2CLKDivider       = ClockConfig::APB2CLKDivider;

            HAL_RCC_OscConfig(&_oscInitStruct);
            HAL_RCC_ClockConfig(&_clkInitStruct, ClockConfig::FlashLatency);
        }
    } // namespace clock
    
} // namespace config



/******************************************************************************\
 *                           End of file
\******************************************************************************/
#endif /* BASE_CLOCK_HPP */
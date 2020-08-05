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

#ifndef DEVBOARD_CONFIG_HPP
#define DEVBOARD_CONFIG_HPP

/******************************************************************************\
 *                             Includes
\******************************************************************************/
#include "TargetsDefines.hpp"

/******************************************************************************\
 *                              Code
\******************************************************************************/
namespace config
{
    struct Clock
    {
        static constexpr std::uint32_t OscillatorType   = RCC_OSCILLATORTYPE_HSI;
        static constexpr std::uint32_t HSIState         = RCC_HSI_ON;
        static constexpr std::uint32_t HSEState         = RCC_HSE_OFF;
        static constexpr std::uint32_t LSEState         = RCC_LSE_OFF;
        static constexpr std::uint32_t LSIState         = RCC_LSI_OFF;
        static constexpr std::uint32_t HSICalibrationValue  = RCC_HSICALIBRATION_DEFAULT;
        static constexpr std::uint32_t PLL_PLLState     = RCC_PLL_ON;
        static constexpr std::uint32_t PLL_PLLSource    = RCC_PLLSOURCE_HSI_DIV2;
        static constexpr std::uint32_t PLL_PLLMUL       = RCC_PLL_MUL16;

        static constexpr std::uint32_t ClockType        =  RCC_CLOCKTYPE_HCLK |
                                                           RCC_CLOCKTYPE_SYSCLK |
                                                           RCC_CLOCKTYPE_PCLK1 |
                                                           RCC_CLOCKTYPE_PCLK2;
        static constexpr std::uint32_t SYSCLKSource     = RCC_SYSCLKSOURCE_PLLCLK;
        static constexpr std::uint32_t AHBCLKDivider    = RCC_SYSCLK_DIV1;
        static constexpr std::uint32_t APB1CLKDivider   = RCC_HCLK_DIV2;
        static constexpr std::uint32_t APB2CLKDivider   = RCC_HCLK_DIV1;

        static constexpr std::uint32_t FlashLatency     = FLASH_LATENCY_2;
    };
} // namespace config

/******************************************************************************\
 *                           End of file
\******************************************************************************/
#endif /* DEVBOARD_CONFIG_HPP */
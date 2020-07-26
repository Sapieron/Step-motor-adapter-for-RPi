/**
 * @file timer.hpp
 * @author Pawel Klisz (pawelochojec@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-04-25
 * 
 * @copyright Copyright (c) 2020 by Pawel Klisz. All rights reserved
 * 
 * Released under the terms of the GNU General Public License version 3 or later.
 * For full license please refer to LICENSE.txt
 * 
 * This project can be found on https://github.com/Sapieron/Step-motor-adapter-for-RPi
 * 
 */

#include "TargetsDefines.hpp"

#include <cstdint>

#include "configuration.hpp"

using std::uint32_t;

namespace drivers
{
    namespace timer
    {
        /**
         * @brief Timer class describing timer
         * 
         */
        template <typename TimerPeriph>
        class Timer
        {
        public:
            /** @brief Default ctor */
            Timer();

            /** @brief Timer initializer */
            void Initialize();

            /** @brief Generates pulses */
            void GeneratePulses(uint32_t count);
        
        private:
            /** @brief Enables clock specific to timer */
            void ClockEnable() const;
        };

        template <typename TimerPeriph>
        void Timer<TimerPeriph>::Initialize()
        {
            // TimerPeriph::
        }

        template <typename TimerPeriph>
        void Timer<TimerPeriph>::GeneratePulses(uint32_t count)
        {
            UNUSED(count);
        }

        template <typename TimerPeriph>
        void Timer<TimerPeriph>::ClockEnable() const
        {
            static constexpr auto selectedTimer = TimerPeriph::Peripheral;

            switch(selectedTimer)
            {
                #ifdef TIM1_BASE
                case TIM1_BASE:
                    __HAL_RCC_TIM1_CLK_ENABLE();
                    break;
                #endif /* TIM1_BASE */

                #ifdef TIM2_BASE
                case TIM2_BASE:
                    __HAL_RCC_TIM2_CLK_ENABLE();
                    break;
                #endif /* TIM2_BASE */

                #ifdef TIM3_BASE
                case TIM3_BASE:
                    __HAL_RCC_TIM3_CLK_ENABLE();
                    break;
                #endif /* TIM3_BASE */

                #ifdef TIM4_BASE
                case TIM4_BASE:
                    __HAL_RCC_TIM4_CLK_ENABLE();
                    break;
                #endif /* TIM4_BASE */

                #ifdef TIM5_BASE
                case TIM5_BASE:
                    __HAL_RCC_TIM5_CLK_ENABLE();
                    break;
                #endif /* TIM5_BASE */

                #ifdef TIM6_BASE
                case TIM6_BASE:
                    __HAL_RCC_TIM6_CLK_ENABLE();
                    break;
                #endif /* TIM6_BASE */

                #ifdef TIM7_BASE
                case TIM7_BASE:
                    __HAL_RCC_TIM7_CLK_ENABLE();
                    break;
                #endif /* TIM7_BASE */

                #ifdef TIM8_BASE
                case TIM8_BASE:
                    __HAL_RCC_TIM8_CLK_ENABLE();
                    break;
                #endif /* TIM8_BASE */

                #ifdef TIM9_BASE
                case TIM9_BASE:
                    __HAL_RCC_TIM9_CLK_ENABLE();
                    break;
                #endif /* TIM9_BASE */

                #ifdef TIM10_BASE
                case TIM10_BASE:
                    __HAL_RCC_TIM10_CLK_ENABLE();
                    break;
                #endif /* TIM10_BASE */

                #ifdef TIM11_BASE
                case TIM11_BASE:
                    __HAL_RCC_TIM11_CLK_ENABLE();
                    break;
                #endif /* TIM11_BASE */

                #ifdef TIM12_BASE
                case TIM12_BASE:
                    __HAL_RCC_TIM12_CLK_ENABLE();
                    break;
                #endif /* TIM12_BASE */

                #ifdef TIM13_BASE
                case TIM13_BASE:
                    __HAL_RCC_TIM13_CLK_ENABLE();
                    break;
                #endif /* TIM13_BASE */

                #ifdef TIM14_BASE
                case TIM14_BASE:
                    __HAL_RCC_TIM14_CLK_ENABLE();
                    break;
                #endif /* TIM14_BASE */
            }
        }
    } // namespace timer
} // namespace drivers

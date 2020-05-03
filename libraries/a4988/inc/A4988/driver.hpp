/**
 * @file driver.hpp
 * @author Pawel Klisz (pawelochojec@gmail.com)
 * @brief  Provides A4988 stepper driver based breakout board declaration
 * @version 0.1
 * @date 2020-04-19
 * 
 * @copyright Copyright (c) 2020 by Pawel Klisz. All rights reserved
 * 
 * Released under the terms of the GNU General Public License version 3 or later.
 * For full license please refer to LICENSE.txt
 * 
 * This project can be found on https://github.com/Sapieron/Step-motor-adapter-for-RPi
 * 
 */

#ifndef A4988_DRIVER_HPP
#define A4988_DRIVER_HPP

#pragma once

#include <array>
#include <float.h>
#include <limits>

#include "hardware/gpio.hpp"

using std::uint32_t;
using std::int32_t;

namespace devices
{
    namespace a4988
    {
        #define STEP_PULSE(steps, microsteps, rpm) (60.0*1000000L/steps/microsteps/rpm)

        template<typename MotorPort>
        class A4988 final
        {
        public:
            A4988();

            void Initialize();

            void MoveToCoordinate(int32_t coordinate);

            void Rotate(int32_t rotations);

            void SetCurrentPositionAsZero();
        private:
            /** @brief MSTable desrcibes MS Pins values, which will set microstepping value of A4988 */
            static constexpr std::array<std::uint_fast8_t, 5> MSTable = {0b000, 0b001, 0b010, 0b011, 0b111};

            /**
             * @brief Set the Microstepping Mode object
             */
            void SetMicrosteppingMode() const;

            /**
             * @brief InitializeTimer
             */
            void InitializeTimer() const;

            int32_t _position;
            int32_t _dirState;
            int32_t _steps_remaining;
            int32_t _steps_to_cruise;
            int32_t _step_pulse;
            int32_t _cruise_step_pulse;
            static constexpr float _oneRevEqualsmm = 4;    //FIXME make it being defined in API
            static constexpr float _factor = (float)MotorPort::MotorStepsPerRev / (float)360;

            const board::MotorPins<MotorPort> _PinsControl;
        };

        template<typename MotorPort>
        A4988<MotorPort>::A4988() : _position(0){}

        template<typename MotorPort>
        void A4988<MotorPort>::InitializeTimer() const
        {
            TIM_HandleTypeDef htim1;
            TIM_ClockConfigTypeDef sClockSourceConfig = {};
            TIM_MasterConfigTypeDef sMasterConfig = {};
            TIM_OnePulse_InitTypeDef sConfigOP = {};

            htim1.Instance = TIM1;
            htim1.Init.Prescaler = (16000 /2000); //FIXME hardcoded
            htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
            htim1.Init.Period = 500 - 1; //FIXME hardcoded
            htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
            htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
            HAL_TIM_Base_Init(&htim1);

            sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;

            HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig);

            HAL_TIM_OnePulse_Init(&htim1, TIM_OPMODE_SINGLE);
            HAL_TIM_PWM_Init(&htim1);

            sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
            sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
            HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig);

            sConfigOP.OCMode = TIM_OCMODE_PWM1;
            sConfigOP.Pulse = 475 - 1; //FIXME hardcoded
            sConfigOP.OCPolarity = TIM_OCPOLARITY_LOW;
            sConfigOP.OCNPolarity = TIM_OCNPOLARITY_LOW;
            sConfigOP.OCIdleState = TIM_OCIDLESTATE_RESET;
            sConfigOP.OCNIdleState = TIM_OCNIDLESTATE_RESET;
            sConfigOP.ICSelection = TIM_OCMODE_PWM1;

            HAL_TIM_OnePulse_ConfigChannel(&htim1, &sConfigOP, MotorPort::TimerChannel, TIM_CHANNEL_2); //FIXME only channel 1 and 2 can be supplied, changing approach is needed

            HAL_TIMEx_OnePulseN_Start(&htim1, MotorPort::TimerChannel);   //FIXME blocking function! use DMA
        }

        template<typename MotorPort>
        void A4988<MotorPort>::Initialize()
        {
            InitializeTimer();
            SetMicrosteppingMode();
            SetCurrentPositionAsZero();
        }

        template<typename MotorPort>
        void A4988<MotorPort>::MoveToCoordinate(int32_t coordinate)
        {
            float _moveBy = coordinate - _position;
            _position = _position + _moveBy;
            this->Rotate(360 * (_moveBy / _oneRevEqualsmm));
        }

        template<typename MotorPort>
        void A4988<MotorPort>::Rotate(int32_t rotations)
        {
            _dirState = (rotations >= 0) ? true : false;
            _PinsControl.Dir.Set(_dirState);
            _steps_to_cruise = abs(rotations * _factor);

            while( _steps_to_cruise > 0)
            {
                if( _steps_to_cruise > std::numeric_limits<std::uint8_t>::max() )
                {
                    TIM1->RCR = std::numeric_limits<std::uint8_t>::max();
                    _steps_to_cruise = _steps_to_cruise - std::numeric_limits<std::uint8_t>::max();
                }
                else
                {
                    TIM1->RCR = _steps_to_cruise;
                    _steps_to_cruise = 0;
                }
                //FIXME little refactoring is needed
                TIM1->CR1 |= (uint32_t)TIM_CR1_CEN; //Call burst
                while(TIM1->CR1 & TIM_CR1_CEN);     //Wait till burst is ended
            }
        }

        template<typename MotorPort>
        void A4988<MotorPort>::SetCurrentPositionAsZero()
        {
            this->_position = 0;
        }

        template<typename MotorPort>
        void A4988<MotorPort>::SetMicrosteppingMode() const
        {
            static_assert( MotorPort::SteppingMode < (this->MSTable.size()) );
            auto mask = A4988::MSTable[MotorPort::SteppingMode];
            _PinsControl.Ms1.Set(mask & 0b001);
            _PinsControl.Ms2.Set(mask & 0b010);
            _PinsControl.Ms3.Set(mask & 0b100);
        }
    } // namespace A4988
} // namespace drivers


#endif /* A4988_DRIVER_HPP */
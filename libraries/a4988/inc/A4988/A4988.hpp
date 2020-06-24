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

/******************************************************************************\
 *                             Includes
\******************************************************************************/
#include <array>
#include <float.h>
#include <limits>

#include "hardware/gpio.hpp"
#include "utils.hpp"

#include "timer/timer.hpp"

#include "timer/configuration.hpp"

/******************************************************************************\
 *                             Code
\******************************************************************************/
using std::uint32_t;
using std::int32_t;

namespace devices
{
    namespace a4988
    {
        template<typename MotorPort>
        class A4988 final
        {
        public:

            /**
             * @brief Construct a new A4988 object
             * 
             */
            A4988();

            /**
             * @brief Initializes //TODO 
             * 
             */
            void Initialize();

            /**
             * @brief Moves stepper motor to desired coordinate
             * 
             * @param coordinate 
             */
            void MoveToCoordinate(int32_t coordinate);

            /**
             * @brief Rotates stepper motor by desired number of steps
             * 
             * @param rotations 
             */
            void Rotate(int32_t rotations);

            /**
             * @brief Set the Current Position As Zero
             * 
             */
            void SetCurrentPositionAsZero();

        private:
            /** @brief MSTable desrcibes MS Pins values, which will set microstepping value of A4988 */
            static constexpr std::array<std::uint_fast8_t, 5> MSTable = {0b000, 0b001, 0b010, 0b011, 0b111};

            /**
             * @brief Set the Microstepping Mode object
             */
            void SetMicrosteppingMode() const;

            /**
             * @brief Initialize Timers
             */
            void InitializeTimers();

            /**
             * @brief Helper function to execute rotations
             */
            void ExecuteRotation(int32_t stepsToCruise);

            /**
             * @brief Helper function that initializes desired timer
             * 
             */
            void ClockTimerEnable() const;

            int32_t _position;
            int32_t _dirState;
            int32_t _steps_remaining;
            int32_t _steps_to_cruise;
            int32_t _step_pulse;
            int32_t _cruise_step_pulse;
            static constexpr float _oneRevEqualsmm = 4;    //FIXME make it being defined in API
            static constexpr float _factor = (float)MotorPort::MotorStepsPerRev / (float)360;

            const board::MotorPins<MotorPort> _PinsControl;

            TIM_TypeDef *const _slaveTimer  = reinterpret_cast<TIM_TypeDef *>(MotorPort::OutputSlaveTimer);
            TIM_TypeDef *const _masterTimer = reinterpret_cast<TIM_TypeDef *>(MotorPort::MasterTimer);
        };

        template<typename MotorPort>
        A4988<MotorPort>::A4988() : _position(0){}

        template<typename MotorPort>
        void A4988<MotorPort>::Initialize()
        {
            ClockTimerEnable();
            InitializeTimers();
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

            if(_steps_to_cruise != 0)
            {
                ExecuteRotation(_steps_to_cruise);
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

        template <typename MotorPort>
        void A4988<MotorPort>::InitializeTimers()
        {
            __HAL_RCC_TIM1_CLK_ENABLE();
            __HAL_RCC_TIM2_CLK_ENABLE();
            __HAL_RCC_TIM3_CLK_ENABLE();
            __HAL_RCC_TIM4_CLK_ENABLE();

            HAL_NVIC_SetPriority(MotorPort::MasterTimerIRQn, 0, 0);
            HAL_NVIC_EnableIRQ(MotorPort::MasterTimerIRQn);

            auto desiredSlaveClock = 10_kHz;
            auto slaveTimerPrescaler = (uint16_t)(SystemCoreClock / desiredSlaveClock) - 1;
            auto dutyCycleInPercent = MotorPort::DutyCycleInPercent;
            // auto pulses = 20;

            auto desiredFrequencySlaveTimer = MotorPort::Frequency;
            auto period = (uint16_t)(desiredSlaveClock / desiredFrequencySlaveTimer) - 1;

            auto desiredMasterClockClock = 100_kHz;
            auto MasterClockPrescaler = (uint16_t)(SystemCoreClock / desiredMasterClockClock) - 1;

            _slaveTimer->PSC = slaveTimerPrescaler; //configure prescaler
            _slaveTimer->ARR = period;        //configure period

            _slaveTimer->CCR1 = period * dutyCycleInPercent / 100; //configure pulse width

            /** @brief Select clock division to 1 */
            _slaveTimer->CR1 &= ~(TIM_CR1_CKD);
            _slaveTimer->CR1 |= TIM_CLOCKDIVISION_DIV1;

            /** @brief Select the upcounting for _slaveTimer */
            /* Reset mode selection bit fields */
            _slaveTimer->CR1 &= ~(TIM_CR1_DIR | TIM_CR1_CMS);
            /* select Up-counting mode */
            _slaveTimer->CR1 |= TIM_COUNTERMODE_UP;

            /** @brief SET PWM1 mode */
            /* Reset the Output Compare Mode Bits */
            _slaveTimer->CCMR1 &= ~TIM_CCMR1_OC1M;
            _slaveTimer->CCMR1 &= ~TIM_CCMR1_CC1S;
            /* Select the output compare mode 1*/
            _slaveTimer->CCMR1 |= TIM_OCMODE_PWM1;

            /** @brief Select active High as output polarity level */
            /* Reset the Output Polarity level */
            _slaveTimer->CCER &= ~TIM_CCER_CC1P;
            /* Set the high Output Compare Polarity */
            _slaveTimer->CCER |= TIM_OCPOLARITY_HIGH;
            /* Enable CC1 output on High level*/
            _slaveTimer->CCER |= TIM_CCER_CC1E; //TODO not sure if ODIdleState is correct

            /** @brief Select active High as output Complementary polarity level */
            /* Reset the Output N State */
            _slaveTimer->CCER &= ~TIM_CCER_CC1NP;
            /* Set the Output N Polarity to high level */
            _slaveTimer->CCER |= TIM_OCNPOLARITY_HIGH;
            /* Enable CC1 output on High level*/
            _slaveTimer->CCER |= TIM_CCER_CC1NE;

            /******************* COM Control update configuration ******************/
            /* Set the capture Compare Preload */
            _slaveTimer->CR2 |= TIM_CR2_CCPC;
            /* Set CCUS bit to select the COM control update to trigger input TRGI*/
            _slaveTimer->CR2 |= TIM_CR2_CCUS;
            /* Enable the Commutation Interrupt sources */
            _slaveTimer->DIER |= TIM_IT_COM;

            /********** Master mode configuration: Trigger Reset mode *********/
            /* configure _slaveTimer's trigger output Update to trig _masterTimer */
            _slaveTimer->CR2 &= ~TIM_CR2_MMS;
            _slaveTimer->CR2 |= TIM_TRGO_RESET; //TODO not sure if that's correct

            /************ Slave mode configuration: Trigger mode ************/
            /* Select the TIM_TS_ITR1 signal as Input trigger for the TIM */
            _slaveTimer->SMCR &= ~TIM_SMCR_TS;

            if (MotorPort::OutputSlaveTimer == TIM1_BASE) //FIXME move it to separate config module
            {
                _slaveTimer->SMCR |= TIM_TS_ITR1;
            }

            if (MotorPort::OutputSlaveTimer == TIM3_BASE) //FIXME move it to separate config module
            {
                _slaveTimer->SMCR |= TIM_TS_ITR3;
            }

            /* Select the Slave Mode */
            _slaveTimer->SMCR &= ~TIM_SMCR_SMS;
            _slaveTimer->SMCR |= TIM_SLAVEMODE_TRIGGER;

            /******************************************************************/
            /* Set the UG bit to enable UEV */
            _slaveTimer->EGR |= TIM_EGR_UG;
            /* Enable the _slaveTimer Main Output */
            _slaveTimer->BDTR |= TIM_BDTR_MOE; //TODO it should be done by itself


            /* configure the Timer prescaler */
            _masterTimer->PSC = MasterClockPrescaler;

            /* Select the Clock Divison to 1 */
            /* Reset clock Division bit field */
            _masterTimer->CR1 &= ~TIM_CR1_CKD;
            /* Select DIV1 as clock division*/
            _masterTimer->CR1 |= TIM_CLOCKDIVISION_DIV1;

            /* Select the Up-counting for _slaveTimer counter */
            /* Reset mode selection bit fields */
            _masterTimer->CR1 &= ~(TIM_CR1_DIR | TIM_CR1_CMS);
            /* select Up-counting mode */
            _masterTimer->CR1 |= TIM_COUNTERMODE_UP;

            /********** Master mode configuration: trigger update ***********/
            /* Trigger of _masterTimer Update into _slaveTimer Slave */
            _masterTimer->CR2 &= ~TIM_CR2_MMS;
            _masterTimer->CR2 |= TIM_TRGO_UPDATE;

            /********** Slave mode configuration: Trigger mode ************/
            /* Select the TIM_TS_ITR0 signal as Input trigger for the TIM */
            _masterTimer->SMCR &= ~TIM_SMCR_TS;

            if(MotorPort::MasterTimer == TIM2_BASE)  //TODO it should be handled by another module
            {
                _masterTimer->SMCR |= TIM_TS_ITR0;
            }

            if (MotorPort::MasterTimer == TIM4_BASE) //TODO it should be handled by another module
            {
                _masterTimer->SMCR |= TIM_TS_ITR2;
            }

            /* Slave Mode selection: Trigger reset Mode */
            _masterTimer->SMCR &= ~TIM_SMCR_SMS;
            _masterTimer->SMCR |= TIM_SLAVEMODE_RESET;

            /****************************************************************/
            /** @brief update interrupt enable */
            _masterTimer->DIER |= TIM_DIER_UIE;

            _slaveTimer->CCMR1 &= TIM_CCMR1_OC2M;
            _slaveTimer->CCMR1 |= TIM_OCMODE_FORCED_INACTIVE;

            /* Enable the both timers counters */
            _masterTimer->CR1 |= TIM_CR1_CEN;
            _slaveTimer->CR1 |= TIM_CR1_CEN;
        }

        template <typename MotorPort>
        void A4988<MotorPort>::ExecuteRotation(int32_t stepsToCruise)
        {
            //1. setup timer registers
            auto pulses = stepsToCruise;

            auto desiredFrequencySlaveTimer = MotorPort::Frequency;
            auto desiredMasterClockClock = 100_kHz;
            auto desiredFrequencyMasterClock = desiredFrequencySlaveTimer;
            auto periodMasterClock = (uint16_t)(desiredMasterClockClock / desiredFrequencyMasterClock * pulses) - 1;

            _masterTimer->CNT = 0;
            _slaveTimer->CNT = 0;
            _masterTimer->ARR = periodMasterClock;

            //2. force the movement!
            _slaveTimer->CCMR1 |= TIM_OCMODE_PWM1;
        }

        template <typename MotorPort>
        void A4988<MotorPort>::ClockTimerEnable() const
        {
            //TODO call timer driver
        }
    } // namespace A4988
} // namespace drivers

/******************************************************************************\
 *                             End of file
\******************************************************************************/
#endif /* A4988_DRIVER_HPP */
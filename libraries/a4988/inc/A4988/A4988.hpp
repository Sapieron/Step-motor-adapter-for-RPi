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
#include <string>
#include <vector>

#include "hardware/gpio.hpp"
#include "utils.hpp"

#include "motorControl_io.hpp"

#include "A4988/types.hpp"

#include "cmsis_os.h"
#include "task.h"

/******************************************************************************\
 *                             Code
\******************************************************************************/
using std::uint32_t;
using std::int32_t;

namespace drivers
{
    namespace a4988
    {
        /**
         * @defgroup a4988_driver A4988 Driver
         * A4988 step motor driver
         * 
         * @ingroup device_drivers
         * 
         * @{
         */

        /**
         * @brief Class describing A4988 driver
         * 
         * @tparam MotorPort 
         */
        template<typename MotorPort>
        class A4988 final : public IMotorControlIO
        {
        public:

            /**
             * @brief Default ctor
             * 
             */
            A4988();

            /**
             * @brief Initializes A4988 driver
             * 
             */
            void Initialize();

            /**
             * @brief Moves stepper motor to desired coordinate
             * 
             * @param coordinade desired coordinate 
             */
            virtual void MoveToCoordinate(std::vector<float> coordinate) override;

            /**
             * @brief Rotates stepper motor by desired number of steps
             * 
             * @param rotations desired number of rotations
             */
            virtual void Rotate(std::vector<float> rotations) override;

            /**
             * @brief Set the Current Position As Zero
             * 
             */
            virtual void SetCurrentPositionAsZero() override;

        private:

            /**
             * @brief Set the Microstepping Mode object
             */
            void SetMicrosteppingMode() const;

            /**
             * @brief FreeRTOS task with C linkage, responsible for executing
             * rotation
             * 
             * @param pvParameters not used
             */
            static void ExecuteRotation(void *pvParameters);

            /**
             * @brief Provides hardware instance of MotorPins, letting direct
             * access to pins
             * 
             */
            const board::MotorPins<MotorPort> _PinsControl;

            /** @brief Contains current position. It is zeroed after power-up */
            float _position = 0;

            /** @brief Helper variable containing desired direction */
            bool _dirState;

            /** @brief Used by @ref ExecuteRotation task. If this variable is
             * larger then 0, task gets automatically triggered
             */
            int32_t _stepsToCruise = 0;
        };


        template<typename MotorPort>
        A4988<MotorPort>::A4988() : _position(0){}

        template<typename MotorPort>
        void A4988<MotorPort>::Initialize()
        {
            SetMicrosteppingMode();
            SetCurrentPositionAsZero();

            #pragma GCC diagnostic ignored "-Wmissing-field-initializers"
            #pragma GCC diagnostic push
            const osThreadAttr_t rotationTask_attributes =
            {
                .name = MotorPort::Name,
                .stack_size = configMINIMAL_STACK_SIZE * 32,
                .priority = osPriorityNormal
            };
            #pragma GCC diagnostic pop

            osThreadNew(ExecuteRotation,
                        this,
                        &rotationTask_attributes);
        }

        template<typename MotorPort>
        void A4988<MotorPort>::MoveToCoordinate(std::vector<float> coordinate)
        {
            std::vector<float> moveBy;
            moveBy.push_back((coordinate.at(0) - _position) / MotorPort::OneRevEqualsMM);
            this->_position = coordinate.at(0);
            this->Rotate(moveBy);
        }

        template<typename MotorPort>
        void A4988<MotorPort>::Rotate(std::vector<float> rotations)
        {
            _dirState = (rotations.at(0) >= 0) ? true : false;
            _PinsControl.Dir.Set(_dirState);
            _stepsToCruise = abs(rotations.at(0) * MotorPort::MotorStepsPerRev);
        }

        template<typename MotorPort>
        void A4988<MotorPort>::SetCurrentPositionAsZero()
        {
            this->_position = 0;
        }

        template<typename MotorPort>
        void A4988<MotorPort>::SetMicrosteppingMode() const
        {
            static_assert( MotorPort::SteppingMode < MSTable.size() );
            auto mask = MSTable[MotorPort::SteppingMode];
            _PinsControl.Ms1.Set(mask & 0b001);
            _PinsControl.Ms2.Set(mask & 0b010);
            _PinsControl.Ms3.Set(mask & 0b100);
        }

        template <typename MotorPort>
        void A4988<MotorPort>::ExecuteRotation(void *pvParameters)
        {
            auto that = static_cast<A4988<MotorPort> * >(pvParameters);

            for(;;)
            {
                if (that->_stepsToCruise > 0)
                {
                    while (that->_stepsToCruise--)
                    {
                        that->_PinsControl.Step.High();
                        vTaskDelay(1);
                        that->_PinsControl.Step.Low();
                        vTaskDelay(1);
                    }
                }
            }
        }

        /** @} */
    } // namespace A4988
} // namespace drivers




/******************************************************************************\
 *                             End of file
\******************************************************************************/
#endif /* A4988_DRIVER_HPP */
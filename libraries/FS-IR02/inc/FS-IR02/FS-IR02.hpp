/**
 * @file FS-IR02.hpp
 * @author Pawel Klisz (pawelochojec@gmail.com)
 * @brief Provide driver class for water level sensor FS-IR02
 * @version 0.1
 * @date 2020-10-10
 * 
 * @copyright Copyright (c) 2020 by Pawel Klisz. All rights reserved
 * 
 * Released under the terms of the GNU General Public License version 3 or later.
 * For full license please refer to LICENSE.txt
 * 
 * This project can be found on https://github.com/Sapieron/Step-motor-adapter-for-RPi
 * 
 */

#ifndef FS_IR02_DRIVER_HPP
#define FS_IR02_DRIVER_HPP

/******************************************************************************\
 *                                 Includes
\******************************************************************************/
#include <cstdint>

#include "gpio/gpio.hpp"
#include "digitalSensor_io.hpp"

#include "types.hpp"

/******************************************************************************\
 *                                   Code
\******************************************************************************/
namespace drivers
{
    namespace fs_ir02
    {
        /**
         * @defgroup fs_ir02_driver FS-IR02 Driver
         * @ingroup device_drivers
         */

        /**
         * @brief Class describing FS-IR02 driver
         * 
         * @tparam FSPort 
         */
        template <typename FSPort>  //FIXME make it inherit from DigitalSensorIO
        class FS_IR02 : public ::IDigitalSensorIO
        {
          public:
            /** @brief Default ctor */
            FS_IR02();

            /** @brief Initializes driver and does initial check of water level */
            void Initialize(void);

            /** @brief Handles interrupt */
            void OnInterrupt(void);

          private:
            /** @brief Checks current sensor state */
            SensorState_t CheckSensorState(void);

            /** @brief Helper variable containing last read state */
            SensorState_t _lastState;

            /** @brief Provides access to mcu's pin */
            drivers::gpio::Pin _signalPin;
        };

        template <typename FSPort>
        FS_IR02<FSPort>::FS_IR02() : _lastState(SensorState_t::TankEmpty),
                                     _signalPin(FSPort::SIG::Port, FSPort::SIG::PinNumber)
        {
            // HAL_GPIO_EXTI_Callback //FIXME make custom callback for each sensor
        }

        template <typename FSPort>
        void FS_IR02<FSPort>::Initialize()
        {
            ::HAL_NVIC_SetPriority(FSPort::Interrupt, 0, 0);
            ::HAL_NVIC_EnableIRQ(FSPort::Interrupt);

            this->_lastState = this->CheckSensorState();
        }

        template <typename FSPort>
        void FS_IR02<FSPort>::OnInterrupt()
        {
            if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_5))
            {
                this->_lastState = CheckSensorState();

                ::HAL_GPIO_EXTI_IRQHandler(FSPort::SIG::PinNumber);
            }
        }

        template <typename FSPort>
        SensorState_t FS_IR02<FSPort>::CheckSensorState(void)
        {
            if (this->_signalPin.Read() == true)
            {
                this->_lastState = SensorState_t::TankFull;
            }
            else
            {
                this->_lastState = SensorState_t::TankEmpty;
            }

            return this->_lastState;
        }

        /** @} */
    } // namespace fs_ir02
} // namespace drivers


/******************************************************************************\
 *                                End of file
\******************************************************************************/
#endif /* FS_IR02_DRIVER_HPP */

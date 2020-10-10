/**
 * @file driver.hpp
 * @author Pawel Klisz (pawelochojec@gmail.com)
 * @brief  Contains thin wrapper over HAL libraries in order
 *         to provide API in C++
 * @version 0.1
 * @date 2020-03-14
 * 
 * @copyright Copyright (c) 2020 by Pawel Klisz. All rights reserved
 * 
 * Released under the terms of the GNU General Public License version 3 or later.
 * For full license please refer to LICENSE.txt
 * 
 * This project can be found on https://github.com/Sapieron/Step-motor-adapter-for-RPi
 * 
 */

#ifndef GPIO_DRIVER_HPP
#define GPIO_DRIVER_HPP

#pragma once

/******************************************************************************\
 *                             Includes
\******************************************************************************/
#include <cstdint>
#include <cstdbool>

#include "TargetsDefines.hpp"

/******************************************************************************\
 *                               Code
\******************************************************************************/
namespace drivers
{
    namespace gpio
    {
        /**
         * @defgroup gpio_driver GPIO driver
         * This module provides thin wrapper over HAL GPIO library
         * 
         * @ingroup peripheral_drivers
         * 
         * @{
         */

        /**
         * @brief Represents single GPIO pin
         */
        class Pin
        {
          public:

            /**
             * @brief Initializes single GPIO pin.
             * @param[in] GPIOxaddress GPIOx_BASE
             * @param[in] pin Pin number
             */
            Pin(std::uint32_t GPIOxaddress, std::uint16_t pin);

            /** @brief Drives pin high */
            inline void High()   const;

            /** @brief Drives pin low */
            inline void Low()    const;

            /** @brief Toggles pin */
            inline void Toggle() const;

            /** @brief Reads pin state */
            inline bool Read()   const;

            /**
             * @brief Sets pin with state argument
             * 
             * @param state 
             */
            inline void Set(bool state) const;

          private:
            /** @brief Port */
                  GPIO_TypeDef* _port;

            /** @brief Pin */
            const std::uint16_t _pin;

            /** @brief Enables clock */
            void ClockEnable();
        };

        void Pin::High() const
        {
            HAL_GPIO_WritePin(this->_port,
                              this->_pin,
                              GPIO_PIN_SET);
        }

        void Pin::Low() const
        {
            HAL_GPIO_WritePin(this->_port,
                              this->_pin,
                              GPIO_PIN_RESET);
        }

        void Pin::Toggle() const
        {
            HAL_GPIO_TogglePin(this->_port,
                               this->_pin);
        }

        bool Pin::Read() const
        {
            return HAL_GPIO_ReadPin(this->_port,
                                    this->_pin);
        }

        void Pin::Set(bool state) const
        {
            HAL_GPIO_WritePin(this->_port,
                              this->_pin,
                              static_cast<GPIO_PinState>(state) );
        }

        /**
         * @brief Output pin class
         * @tparam Location Type with two static members: Port and PinNumber
         * @tparam DefaultState flase if pin should be low by default
         */
        template<typename Location, bool DefaultState = false>
        class OutputPin final : public Pin
        {
          public:
            /** @brief default ctor */
            OutputPin();
            /**
             * @brief Location of port
             * 
             */
            static constexpr auto Port       = Location::Port;

            /**
             * @brief Location of pin
             * 
             */
            static constexpr auto PinNumber  = Location::PinNumber;

            /** @brief Initializes pin on port */
            void Initialize()   const;

            /** @brief Deinitializes pin on port */
            void DeInitialize() const;
        };

        /** @} */

        template <typename Location, bool DefaultState>
        OutputPin<Location, DefaultState>::OutputPin() : Pin(Port, PinNumber)
        {
        }

        template <typename Location, bool DefaultState>
        void OutputPin<Location, DefaultState>::Initialize() const
        {
            GPIO_InitTypeDef gpio_init;
            gpio_init.Mode  = GPIO_MODE_OUTPUT_PP;
            gpio_init.Pin   = PinNumber;
            gpio_init.Speed = GPIO_SPEED_FREQ_LOW;

            GPIO_TypeDef *hgpio = reinterpret_cast<GPIO_TypeDef*>(Location::Port);

            HAL_GPIO_Init(hgpio, &gpio_init);
            if(DefaultState == ENABLE)
            {
              this->High();
            }else{
              this->Low();
            }
        }

        template <typename Location, bool DefaultState>
        void OutputPin<Location, DefaultState>::DeInitialize() const
        {
            GPIO_TypeDef *helper = reinterpret_cast<GPIO_TypeDef*>(Port);

            HAL_GPIO_DeInit(helper, PinNumber);
        }

        template<typename Location, bool DefaultState = DISABLE>
        class OutputPinAF final : public Pin
        {
        public:
            static constexpr uint32_t Port      = Location::Port;
            static constexpr uint32_t PinNumber = Location::PinNumber;

            OutputPinAF();

            void Initialize() const;
        };

        template<typename Location, bool DefaultState>
        OutputPinAF<Location, DefaultState>::OutputPinAF() : Pin(Port, PinNumber)
        {
        }

        template<typename Location, bool DefaultState>
        void OutputPinAF<Location, DefaultState>::Initialize() const
        {
            GPIO_TypeDef *hgpio =  reinterpret_cast<GPIO_TypeDef*>(Location::Port);

            GPIO_InitTypeDef gpio_init;
            gpio_init.Pin = PinNumber;
            gpio_init.Mode = GPIO_MODE_AF_PP;
            gpio_init.Pull = GPIO_PULLUP;
            gpio_init.Speed = GPIO_SPEED_FREQ_HIGH;

            HAL_GPIO_Init(hgpio, &gpio_init);

            if(DefaultState == ENABLE)
            {
                this->High();
            }else{
                this->Low();
            }
        }

        /**
         * @brief Input pin class
         * 
         * @tparam Location - type with two static members: Port and PinNumber
         * @tparam DefaultState = ENABLE - indicates default state
         */
        template<typename Location, bool DefaultState = ENABLE>
        class InputPinAF final : public Pin
        {
        public:
            static constexpr auto Port        = Location::Port;
            static constexpr auto PinNumber   = Location::PinNumber;

            InputPinAF();
            void Initialize() const;
        };

        template<typename Location, bool DefaultState>
        InputPinAF<Location, DefaultState>::InputPinAF() : Pin(Port, PinNumber){}

        template<typename Location, bool DefaultState>
        void InputPinAF<Location, DefaultState>::Initialize() const
        {
            GPIO_TypeDef *hgpio = reinterpret_cast<GPIO_TypeDef*>(Port);

            GPIO_InitTypeDef gpio_init;
            gpio_init.Pin   = PinNumber;
            gpio_init.Speed = GPIO_SPEED_FREQ_HIGH;
            gpio_init.Pull  = GPIO_NOPULL;
            gpio_init.Mode  = GPIO_MODE_AF_INPUT;

            HAL_GPIO_Init(hgpio, &gpio_init);
        }

        template<typename Location, typename Options>
        class CustomPin final : public Pin
        {
        public:
            CustomPin();

            void Initialize() const;

            static constexpr auto Port      = Location::Port;
            static constexpr auto PinNumber = Location::PinNumber;
        };

        template<typename Location, typename Options>
        CustomPin<Location, Options>::CustomPin() : Pin(Port, PinNumber){}

        template <typename Location, typename Options>
        void CustomPin<Location, Options>::Initialize() const
        {
            GPIO_TypeDef *hgpio = reinterpret_cast<GPIO_TypeDef *>(Port);

            GPIO_InitTypeDef hgpio_init;
            hgpio_init.Pin      = PinNumber;
            hgpio_init.Mode     = Options::Mode;
            hgpio_init.Pull     = Options::Pull;
            hgpio_init.Speed    = Options::Speed;

            HAL_GPIO_Init(hgpio, &hgpio_init);
        }

    }//namespace gpio
}//namespace drivers

/******************************************************************************\
 *                           End of file
\******************************************************************************/
#endif /* GPIO_DRIVER_HPP */

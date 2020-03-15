/**
 * @file driver.hpp
 * @author https://github.com/Sapieron
 * @brief  Contains thin wrapper over HAL libraries in order
 *         to provide API in C++
 * 
 * @version 0.1
 * @date 2020-03-14
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef GPIO_DRIVER_HPP
#define GPIO_DRIVER_HPP

#pragma once

#include <cstdint>

#include "stm32f103xb.h"
#include "stm32f1xx_hal_gpio.h"

namespace drivers
{
    namespace gpio
    {
        /** @defgroup gpio GPIO periperhal driver
         * @ingroup perhipheral_drivers
         * This module provides thin wrapper over HAL GPIO library
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

            inline void High()   const;
            inline void Low()    const;
            inline void Toggle() const;
            inline bool Read()   const;

          private:
                  GPIO_TypeDef* _port;
            const std::uint16_t _pin;
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

        /**
         * @brief Output pin class
         * @tparam Location Type with two static members: Port and PinNumber
         * @tparam DefaultState flase if pin should be low by default
         */
        template<typename Location, bool DefaultName = false>
        class OutputPin final : public Pin
        {
          public:
            static constexpr auto Port       = Location::Port;
            static constexpr auto PinNumber  = Location::PinNumber;
            
            OutputPin();

            void Initialize()   const;
            void DeInitialize() const;
        };

        template <typename Location, bool DefaultState>
        OutputPin<Location, DefaultState>::OutputPin() : Pin(Port, PinNumber)
        {
        }

        template <typename Location, bool DefaultState>
        void OutputPin<Location, DefaultState>::Initialize() const
        {
            GPIO_InitTypeDef gpio_init;
            gpio_init.Mode = GPIO_MODE_OUTPUT_PP;
            gpio_init.Pin = PinNumber;
            gpio_init.Speed = GPIO_SPEED_FREQ_LOW;

            GPIO_TypeDef *helper = reinterpret_cast<GPIO_TypeDef*>(Port);

            HAL_GPIO_Init(helper, &gpio_init);
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
    }
}



#endif /* GPIO_DRIVER_HPP */
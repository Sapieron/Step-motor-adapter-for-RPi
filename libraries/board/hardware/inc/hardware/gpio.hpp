/**
 * @file gpio.hpp
 * @author https://github.com/Sapieron
 * @brief  Contains template structures describing peripheral pins,
 *         initialization functions
 * 
 * @version 0.1
 * @date 2020-02-27
 * 
 * @copyright Copyright (c) 2020
 */

#ifndef LIBS_OBC_HARDWARE_INCLUDE_OBC_GPIO_H_
#define LIBS_OBC_HARDWARE_INCLUDE_OBC_GPIO_H_

#include "stm32f1xx_hal_gpio.h"
#include "stm32f1xx_hal_rcc.h"

#include "gpio/forward.hpp"
#include "gpio/driver.hpp"

#include "mcu/io_map.hpp"
#include "gpio_internal.hpp"

namespace board
{
    /**
     * @defgroup obc_hardware_gpio OBC GPIO
     * @ingroup obc_hardware
     *
     * @{
     */
    //TODO add I2C functionality
    // /** @brief Structure describing I2C pins */
    // template <typename Location> struct I2CPins
    // {
    //     /** @brief SDA */
    //     const drivers::gpio::OutputPin<typename Location::SDA> SDA;
    //     /** @brief SCL */
    //     const drivers::gpio::OutputPin<typename Location::SCL> SCL;

    //     /** @brief Initializes I2C pins */
    //     void Initialize() const
    //     {
    //         this->SDA.Initialize();
    //         this->SCL.Initialize();
    //     }
    // };

    //TODO add UART functionality
    // /** @brief Structure describing UART pins */
    // template <typename Location> struct UARTPins
    // {
    //     /** @brief TX */
    //     const drivers::gpio::OutputPin<typename Location::TX> TX;
    //     /** @brief RX */
    //     const drivers::gpio::InputPin<typename Location::RX> RX;
    //     /** @brief Initializes UART pins */
    //     void Initialize() const
    //     {
    //         this->TX.Initialize();
    //         this->RX.Initialize();
    //     }
    // };

    /**
     * @brief Composes all used GPIO pins together
     *
     * @remark All used pin locations must derive from tags defined in template/io_map.hpp
     */
    template <typename TCommOkIndicator//,
        // typename TUART0,
        // typename TUART1,
        // typename TI2C0,
        >
    struct BoardGPIOBase
    {
        /** @brief LedCommOk onboard green led */
        const drivers::gpio::OutputPin<TCommOkIndicator, DISABLE> LedCommOk;
        /** @brief UART0 */
        // const UARTPins<TUART0> UART_0;
        // /** @brief UART1 */
        // const UARTPins<TUART1> UART_1;
        // /** @brief I2C0 */
        // const I2CPins<TI2C0> I2C_0;
        /** @brief Camera selector */
        //const drivers::gpio::OutputPin<TCamSelect> CamSelect;

        //TODO maybe pack up step-motors in such a structure?
        // /** @brief PayloadInterrupt */
        // const drivers::gpio::InterruptPin<TPayloadInterrupt, false, false, true> PayloadInterrupt;

        // /** @brief SunSInterrupt */
        // const drivers::gpio::InterruptPin<TSunSInterrupt, false, false, true> SunSInterrupt;

        // /** @brief Sail state indicator. */
        // const drivers::gpio::InputPin<TSailState> SailIndicator;

        /** @brief Initializes GPIO pins */
        void Initialize() const
        {
            this->LedCommOk.Initialize();
            // this->UART_0.Initialize();
            // this->UART_1.Initialize();
            // this->I2C_0.Initialize();
        }
    };

    /** @brief Connects GPIO pins to IO map */
    using BOARDGPIO = gpio::VerifyPinsUniqueness<BoardGPIOBase,
        io_map::LedCommOk
        // io_map::UART_0,
        // io_map::UART_1,
        // io_map::I2C_0,
        //io_map::BSP,
        //io_map::XTAL
        >;

    /** @} */
}

#endif /* LIBS_OBC_HARDWARE_INCLUDE_OBC_GPIO_H_ */

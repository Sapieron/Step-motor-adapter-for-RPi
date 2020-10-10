#include "gpio/gpio.hpp"
#include "TargetsDefines.hpp"

using drivers::gpio::Pin;

Pin::Pin(std::uint32_t GPIOxaddress,
         std::uint16_t pin) :
                              _port(reinterpret_cast<GPIO_TypeDef*>(GPIOxaddress)),
                              _pin(pin) 
{
    ClockEnable();
}

void Pin::ClockEnable()
{
    auto selectedClock = reinterpret_cast<std::uint32_t>(_port);

    switch(selectedClock)
    {
        #ifdef GPIOA_BASE
        case GPIOA_BASE:
            __HAL_RCC_GPIOA_CLK_ENABLE();
            break;
        #endif /* GPIOA_BASE */

        #ifdef GPIOB_BASE
        case GPIOB_BASE:
            __HAL_RCC_GPIOB_CLK_ENABLE();
            break;
        #endif /* GPIOB_BASE */

        #ifdef GPIOC_BASE
        case GPIOC_BASE:
            __HAL_RCC_GPIOC_CLK_ENABLE();
            break;
        #endif /* GPIOC_BASE */

        #ifdef GPIOD_BASE
        case GPIOD_BASE:
            __HAL_RCC_GPIOD_CLK_ENABLE();
            break;
        #endif /* GPIOD_BASE */

        #ifdef GPIOE_BASE
        case GPIOE_BASE:
            __HAL_RCC_GPIOE_CLK_ENABLE();
            break;
        #endif /* GPIOE_BASE */

        #ifdef GPIOF_BASE
        case GPIOF_BASE:
            __HAL_RCC_GPIOF_CLK_ENABLE();
            break;
        #endif /* GPIOF_BASE */
    }
}
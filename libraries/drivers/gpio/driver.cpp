#include "gpio/driver.hpp"

using namespace drivers::gpio;

Pin::Pin(std::uint32_t GPIOxaddress,
         std::uint16_t pin) :
                              _port(reinterpret_cast<GPIO_TypeDef*>(GPIOxaddress)),
                              _pin(pin) 
{
}
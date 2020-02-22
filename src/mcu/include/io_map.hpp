#include <cstdint>
#include "stm32f103xb.h"

/** @cond FALSE **/

namespace io_map
{
    using LedCommOk          = PinLocation<gpioPortA, 0>;

    using MotorControlEnable = PinLocation<gpioPortB, 9>;

    using MotorControlDir1   = PinLocation<gpioPortB, 10>;
    using MotorControlDir2   = PinLocation<gpioPortB, 11>;
    using MotorControlDir3   = PinLocation<gpioPortB, 12>;

    using MotorControlStep1  = PinLocation<gpioPortB, 13>;
    using MotorControlStep2  = PinLocation<gpioPortB, 14>;
    using MotorControlStep3  = PinLocation<gpioPortB, 15>;

    /* Step resolution pins */
    using MotorControlMS11   = PinLocation<gpioPortB, 0>;
    using MotorControlMS12   = PinLocation<gpioPortB, 1>;
    using MotorControlMS13   = PinLocation<gpioPortB, 2>;

    using MotorControlMS21   = PinLocation<gpioPortB, 3>;
    using MotorControlMS22   = PinLocation<gpioPortB, 4>;
    using MotorControlMS23   = PinLocation<gpioPortB, 5>;

    using MotorControlMS31   = PinLocation<gpioPortA, 4>;
    using MotorControlMS32   = PinLocation<gpioPortA, 5>;
    using MotorControlMS33   = PinLocation<gpioPortA, 6>;

    using SWDIO              = PinLocation<gpioPortA, 13>;
    using SWCLK              = PinLocation<gpioPortA, 14>;

    struct UART_1 : public UARTPins<UART_1>
    {
        static constexpr USART_TypeDef* Peripheral = USART1;
//        static constexpr std::uint32_t Location = UART_ROUTE_LOCATION_LOC2;
        static constexpr std::uint32_t Baudrate = 115200;
        static constexpr std::uint8_t InterruptPriority = 6;
        static constexpr IRQn_Type WakeUpInterrupt = IRQn_Type::USART1_IRQn;
        static constexpr std::uint8_t WakeUpInterruptPriority = 5;

        using TX = PinLocation<gpioPortA, 9>;
        using RX = PinLocation<gpioPortA, 10>;
    };

    struct UART_2 : public UARTPins<UART_2>
    {
        static constexpr USART_TypeDef* Peripheral = USART2;
//        static constexpr std::uint32_t Location = UART_ROUTE_LOCATION_LOC2;
        static constexpr std::uint32_t Baudrate = 115200;
        static constexpr std::uint8_t InterruptPriority = 6;
        static constexpr IRQn_Type WakeUpInterrupt = IRQn_Type::USART2_IRQn;
        static constexpr std::uint8_t WakeUpInterruptPriority = 5;

        using TX = PinLocation<gpioPortA, 2>;
        using RX = PinLocation<gpioPortA, 3>;
    };

    struct I2C_1 : public I2CPins<I2C_1>
    {
        static constexpr std::uint32_t Location = I2C_ROUTE_LOCATION_LOC0;

        using SCL = PinLocation<gpioPortB, 6>;
        using SDA = PinLocation<gpioPortB, 7>;
    };

    struct I2C
    {
        static constexpr std::uint8_t InterruptPriority = 6;

        static constexpr std::uint8_t SystemBus = 1;
        static constexpr std::uint8_t PayloadBus = 0;
#ifndef I2C_TIMEOUT
        static constexpr std::uint32_t Timeout = 5; // in seconds
#else
        static constexpr std::uint32_t Timeout = I2C_TIMEOUT; // in seconds
#endif
    };

    struct Watchdog
    {
        static constexpr WDOG_PeriodSel_TypeDef Period = wdogPeriod_1k; // About 1 second
    };

    struct RAMScrubbing
    {
        static constexpr auto TimerHW = TIMER0;
        static constexpr auto Prescaler = timerPrescale1024;
        static constexpr auto TimerTop = 468;
        static constexpr auto IRQ = IRQn_Type::TIMER0_IRQn;
        static constexpr std::size_t MemoryStart = 0x20000000;
        static constexpr std::size_t MemorySize = 128_KB;
        static constexpr std::size_t CycleSize = 8;
    };
}

/** @endcond */

#endif

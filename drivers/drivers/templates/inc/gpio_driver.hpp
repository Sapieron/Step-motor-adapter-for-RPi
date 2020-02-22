#include <cstdint>

typedef enum
{
#if ( _GPIO_PORT_A_PIN_COUNT > 0 )
  gpioPortA = 0,
#endif
#if ( _GPIO_PORT_B_PIN_COUNT > 0 )
  gpioPortB = 1,
#endif
#if ( _GPIO_PORT_C_PIN_COUNT > 0 )
  gpioPortC = 2,
#endif
#if ( _GPIO_PORT_D_PIN_COUNT > 0 )
  gpioPortD = 3,
#endif
#if ( _GPIO_PORT_E_PIN_COUNT > 0 )
  gpioPortE = 4,
#endif
#if ( _GPIO_PORT_F_PIN_COUNT > 0 )
  gpioPortF = 5
#endif
#if defined( _GPIO_PORT_G_PIN_COUNT ) && ( _GPIO_PORT_G_PIN_COUNT > 0 )
  gpioPortG = 6
#endif
#if defined( _GPIO_PORT_H_PIN_COUNT ) && ( _GPIO_PORT_H_PIN_COUNT > 0 )
  gpioPortH = 7
#endif
} GPIO_Port_TypeDef;
#include "mcu/board.hpp"

BOARD::BOARD() : Hardware(),
                 terminal(this->Hardware.Terminal),
                 motorController(this->Hardware.MotorX,
                                 this->Hardware.MotorY,
                                 this->Hardware.MotorZ){}
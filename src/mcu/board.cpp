#include "mcu/board.hpp"

BOARD::BOARD() : Hardware(),
                 terminal(this->Hardware.Terminal){}
/******************************************************************************\
 * 								Includes
\******************************************************************************/
#include "board_access.hpp"
#include "mcu/board.hpp"

/******************************************************************************\
 * 								 Code
\******************************************************************************/

devices::terminal::Terminal& GetTerminal()
{
    return Main.terminal;
}

// devices::motorController::MotorController& GetMotorController()
// {
//     return Main.motorController;
// }
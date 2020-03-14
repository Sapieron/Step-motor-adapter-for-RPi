/**
 * @file board.hpp
 * @author https://github.com/Sapieron
 * @brief  Contains global BOARD object, that describes
 *         drivers and state of the board
 * 
 * @version 0.1
 * @date 2020-02-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "hardware.hpp"

/**
 * @brief Object describing global BOARD state and drivers
 */
struct BOARD
{
    public:
        BOARD();

    /** @brief OBC hardware */
    board::BOARDHardware Hardware;
};

/**
 * @brief Global OBC object
 * 
 */
extern BOARD Main;
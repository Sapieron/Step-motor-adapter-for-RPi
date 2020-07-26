/**
 * @file ConfigDefine.hpp
 * @author Pawel Klisz (pawelochojec@gmail.com)
 * @brief This file contatins common includes for all modules, depending on used target configuration
 * @version 0.1
 * @date 2020-07-25
 * 
 * @copyright Copyright (c) 2020 by Pawel Klisz. All rights reserved
 * 
 * Released under the terms of the GNU General Public License version 3 or later.
 * For full license please refer to LICENSE.txt
 * 
 * This project can be found on https://github.com/Sapieron/Step-motor-adapter-for-RPi
 * 
 */


#ifndef TARGETS_DEFINES_HPP
#define TARGETS_DEFINES_HPP

#include "stm32f1xx_hal.h"

#ifdef STM32F103xG
    #include "stm32f103xg.h"
#endif /* STM32F103xG */

#ifdef STM32F103xB
#include "stm32f103xb.h"
#endif /* STM32F103xB */


#endif /* TARGETS_DEFINES_HPP */
/**
 * @file command_factory.hpp
 * @author Pawel Klisz (pawelochojec@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-05-09
 * 
 * @copyright Copyright (c) 2020 by Pawel Klisz. All rights reserved
 * 
 * Released under the terms of the GNU General Public License version 3 or later.
 * For full license please refer to LICENSE.txt
 * 
 * This project can be found on https://github.com/Sapieron/Step-motor-adapter-for-RPi
 * 
 */


#ifndef MOTORCONTROLLER_COMMAND_FACTORY_HPP
#define MOTORCONTROLLER_COMMAND_FACTORY_HPP

#pragma once



/******************************************************************************\
 *                                Includes
\******************************************************************************/
#include <array>

#include "types.hpp"

/******************************************************************************\
 *                                 Code
\******************************************************************************/
namespace devices
{
    namespace motorController
    {
        /**
         * @addtogroup motor_controller
         * @{
         */

        /**
         * @brief CommandFactory responsible for creating frames
         * for motorController
         * 
         */
        class CommandFactory
        {
        public:
            /**
             * @brief Frame type describing type of command frame
             * 
             */
            using Frame = std::array<uint8_t, CommandFrameSize>;

            /**
             * @brief Builds SayHelloWorld command frame on given buffer
             * @param buffer 
             */
            void BuildSayHelloWorld(Frame buffer);
        };

        /** @} */
    } // namespace motorController
    
} // namespace devices


/******************************************************************************\
 *                            End of file
\******************************************************************************/
#endif /* MOTORCONTROLLER_COMMAND_FACTORY_HPP */
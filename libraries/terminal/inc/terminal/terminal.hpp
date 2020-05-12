/**
 * @file driver.hpp
 * @author Pawel Klisz (pawelochojec@gmail.com)
 * @brief  Terminal functions definitions
 * @version 0.1
 * @date 2020-04-06
 * 
 * @copyright Copyright (c) 2020 by Pawel Klisz. All rights reserved
 * 
 * Released under the terms of the GNU General Public License version 3 or later.
 * For full license please refer to LICENSE.txt
 * 
 * This project can be found on https://github.com/Sapieron/Step-motor-adapter-for-RPi
 * 
 */

#ifndef TERMINAL_DRIVER_HPP
#define TERMINAL_DRIVER_HPP

#pragma once

#include "line_io.hpp"

namespace devices
{
    namespace terminal
    {
        class Terminal : public ILineIO
        {
        public:
            Terminal(ILineIO& stdio);
            ~Terminal() = default;

            void Initialize();

            // void SetCommandList(commands);

            virtual void Puts(const char* text) override; //FIXME has to be inline, as definition can't be contained in .cpp file - bug to fix

            // void Read();
        private:
            ILineIO& _stdio;
        };
    } // namespace terminal
} // namespace devices


#endif /* TERMINAL_DRIVER_HPP */

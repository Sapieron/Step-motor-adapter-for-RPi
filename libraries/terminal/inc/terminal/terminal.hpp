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

            /**
             * @brief Puts desired text to output
             * 
             * @param text - const char* text to be outputted
             */
            virtual void Puts(const char* text) override;

            /**
             * @brief Returns data contained in rx buffer
             * 
             * @return const char* Data
             */
            virtual const char* GetRxBuffer() override;

        private:
            ILineIO& _stdio;
        };
    } // namespace terminal
} // namespace devices


#endif /* TERMINAL_DRIVER_HPP */

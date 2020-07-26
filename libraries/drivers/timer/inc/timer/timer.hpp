/**
 * @file timer.hpp
 * @author Pawel Klisz (pawelochojec@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-04-25
 * 
 * @copyright Copyright (c) 2020 by Pawel Klisz. All rights reserved
 * 
 * Released under the terms of the GNU General Public License version 3 or later.
 * For full license please refer to LICENSE.txt
 * 
 * This project can be found on https://github.com/Sapieron/Step-motor-adapter-for-RPi
 * 
 */

#include "TargetsDefines.hpp"

#include <cstdint>

using std::uint32_t;

namespace drivers
{
    namespace timer
    {
        class Timer final
        {
        public:
            Timer();

            void Initialize();

            void GeneratePulses(uint32_t count, uint32_t duration);
        };

        void Timer::Initialize()
        {
            //
        }

        void Timer::GeneratePulses(uint32_t count)
        {
            UNUSED(count);
        }
    } // namespace timer
} // namespace drivers

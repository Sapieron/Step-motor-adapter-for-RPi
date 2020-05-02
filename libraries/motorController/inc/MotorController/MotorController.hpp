/**
 * @file MotorController.hpp
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

#include "A4988/driver.hpp"

namespace devices
{
    namespace MotorController
    {
        template<typename MotorPort>
        class MotorController
        {
        public:
            MotorController();

            void Initialize() const;
        };

        template<typename MotorPort>
        MotorController<MotorPort>::MotorController()
        {
            //TODO
        }

        template<typename MotorPort>
        void MotorController<MotorPort>::Initialize() const
        {
            //TODO
        }
    } // namespace MotorController
    
} // namespace devices

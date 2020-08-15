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


/******************************************************************************\
 *                            Includes
\******************************************************************************/
#include "A4988/A4988.hpp"
#include "types.hpp"

#include "motorControl_io.hpp"


/******************************************************************************\
 *                             Code
\******************************************************************************/
namespace devices
{
    namespace motorController
    {
        using std::int32_t;

        /**
         * @defgroup motor_controller Motor Controller
         * @ingroup devices
         * 
         * @{
         */

        /**
         * @brief MotorController driver class for motor controlling
         * 
         */
        class MotorController : public IMotorControlIO
        {
        public:
            /**
             * @brief Default ctor
             * 
             * @param MotorX reference to motor X
             * @param MotorY reference to motor Y
             * @param MotorZ reference to motor Z
             */
            MotorController(IMotorControlIO& MotorX,
                            IMotorControlIO& MotorY,
                            IMotorControlIO& MotorZ);

            /**
             * @brief Moves various motors to desired coordinate
             * 
             * @param args Each argument tells how much should each axis be
             * moved, f.e. passing arguments (1,2,3) will make axis' X, Y and Z
             * move X by 1mm, Y by 2mm and Z by 3mm
             */
            void MoveToCoordinate(int32_t args...) override;

            /**
             * @brief 
             * 
             * @param args Each argument tells how many rotations should each
             * motor do, f.e. passing arguments (1,2,3) will make motors X, Y
             * and Z move respectively X by 1 rotation, Y by 2 rotations and
             * Z by 3 rotations
             */
            void Rotate(int32_t args...) override;

            /**
             * @brief Sets current position of all axis' to 0
             * 
             */
            void SetCurrentPositionAsZero() override;

            /**
             * @brief Handles reception
             * 
             * @param data data to be handled
             */
            void OnReception(const char* data);

        private:
            /**
             * @brief _MotorX private class member, provides control over
             * connected stepper
             */
            IMotorControlIO& _MotorX;

            /**
             * @brief _MotorY private class member, provides control over
             * connected stepper
             */
            IMotorControlIO& _MotorY;

            /**
             * @brief _MotorZ private class member, provides control over
             * connected stepper
             */
            IMotorControlIO& _MotorZ;
        };

        /** @} */
        
    } // namespace MotorController
    
} // namespace devices


/******************************************************************************\
 *                            End of file
\******************************************************************************/
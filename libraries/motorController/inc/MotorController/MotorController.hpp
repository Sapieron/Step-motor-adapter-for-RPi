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

#include "A4988/A4988.hpp"

namespace devices
{
    namespace motorController
    {
        using std::int32_t;

        template<typename MotorPortX,
                 typename MotorPortY,
                 typename MotorPortZ>
        class MotorController
        {
        public:
            MotorController();

            void Initialize();

            void MoveToCoordinate(int32_t X,
                                  int32_t Y,
                                  int32_t Z);

            void Rotate(int32_t X,
                        int32_t Y,
                        int32_t Z);
        private:
            devices::a4988::A4988<MotorPortX> _MotorX;
            devices::a4988::A4988<MotorPortY> _MotorY;
            // devices::a4988::A4988<MotorPortZ> _MotorZ;
        };

        template<typename MotorPortX,
                 typename MotorPortY,
                 typename MotorPortZ>
        MotorController<MotorPortX, MotorPortY, MotorPortZ>::MotorController()
        {
            //TODO
        }

        template<typename MotorPortX,
                 typename MotorPortY,
                 typename MotorPortZ>
        void MotorController<MotorPortX, MotorPortY, MotorPortZ>::Initialize()
        {
            _MotorX.Initialize();
            _MotorY.Initialize();
            // _MotorZ.Initialize();
        }

        template<typename MotorPortX,
                 typename MotorPortY,
                 typename MotorPortZ>
        void MotorController<MotorPortX, MotorPortY, MotorPortZ>::MoveToCoordinate(int32_t X,
                                                                                   int32_t Y,
                                                                                   int32_t Z)
        {
            _MotorX.MoveToCoordinate(X);
            _MotorY.MoveToCoordinate(Y);
            // _MotorZ.MoveToCoordinate(Z);
            // UNUSED(X);
            UNUSED(Z);
        }

        template <typename MotorPortX,
                  typename MotorPortY,
                  typename MotorPortZ>
        void MotorController<MotorPortX, MotorPortY, MotorPortZ>::Rotate(int32_t X,
                                                                         int32_t Y,
                                                                         int32_t Z)
        {
            _MotorX.Rotate(X);
            // UNUSED(X);
            _MotorY.Rotate(Y);
            UNUSED(Z);
        }
    } // namespace MotorController
    
} // namespace devices

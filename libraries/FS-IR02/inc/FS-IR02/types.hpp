/**
 * @file types.hpp
 * @author Pawel Klisz (pawelochojec@gmail.com)
 * @brief Contains FS-IR02 specific types
 * @version 0.1
 * @date 2020-10-11
 * 
 * @copyright Copyright (c) 2020 by Pawel Klisz. All rights reserved
 * 
 * Released under the terms of the GNU General Public License version 3 or later.
 * For full license please refer to LICENSE.txt
 * 
 * This project can be found on https://github.com/Sapieron/Step-motor-adapter-for-RPi
 * 
 */

#ifndef FS_IR02_TYPES_HPP
#define FS_IR02_TYPES_HPP

/******************************************************************************\
 *                                 Includes
\******************************************************************************/


/******************************************************************************\
 *                                   Code
\******************************************************************************/
namespace drivers
{
    namespace fs_ir02
    {
        /**
         * @addtogroup fs_ir02_driver
         * @{
         */

        /** @brief Enumeration class describing possible states for FS-IR02 */
        enum class SensorState_t
        {
            TankEmpty = false,
            TankFull  = true
        };

        /** @} */
    } // namespace fs_ir02
} // namespace drivers



/******************************************************************************\
 *                               End of file
\******************************************************************************/
#endif /* FS_IR02_TYPES_HPP */
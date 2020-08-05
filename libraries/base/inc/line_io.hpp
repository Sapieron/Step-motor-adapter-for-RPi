/**
 * @file line_io.hpp
 * @author Pawel Klisz (pawelochojec@gmail.com)
 * @brief Line based interface
 * @version 0.1
 * @date 2020-05-10
 * 
 * @copyright Copyright (c) 2020 by Pawel Klisz. All rights reserved
 * 
 * Released under the terms of the GNU General Public License version 3 or later.
 * For full license please refer to LICENSE.txt
 * 
 * This project can be found on https://github.com/Sapieron/Step-motor-adapter-for-RPi
 * 
 */

#ifndef LINE_IO_BASE_HPP
#define LINE_IO_BASE_HPP


class ILineIO
{
public:
    ILineIO() = default;
    ~ILineIO() = default;
    
    virtual void Puts(const char* text) = 0;

    virtual const char *GetRxBuffer() = 0;
};


#endif /* LINE_IO_BASE_HPP */
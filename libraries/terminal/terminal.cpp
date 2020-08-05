/**
 * @file driver.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-03-17
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "terminal.hpp"


using devices::terminal::Terminal;

Terminal::Terminal(ILineIO& stdio) : _stdio(stdio)
{
}


void Terminal::Puts(const char *text)
{
    this->_stdio.Puts(text);
}

const char* Terminal::GetRxBuffer()
{
    return this->_stdio.GetRxBuffer();
}

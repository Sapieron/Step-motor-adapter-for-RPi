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

/**
 * @brief Puts desired text to output
 * 
 * @param text 
 */
void Terminal::Puts(const char *text)
{
    this->_stdio.Puts(text);
}

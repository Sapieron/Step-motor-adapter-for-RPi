#include "hardware.hpp"

using namespace board;

void BOARDHardware::Initialize()
{
    this->Pins.Initialize();
    this->Terminal.Initialize();
}
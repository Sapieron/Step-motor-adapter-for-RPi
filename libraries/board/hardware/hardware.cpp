#include "hardware.hpp"

using namespace board;

void BOARDHardware::Initialize()
{
    this->ClockHandler.Initialize();
    this->Pins.Initialize();
    this->Terminal.Initialize();
    this->MotorX.Initialize();
    this->MotorY.Initialize();
    this->MotorZ.Initialize();
    this->WaterSensor1.Initialize(); //FIXME call Water pump controller to handle it
}
#include "motor_controller.hpp"

#include <cstdarg>

using devices::motorController::MotorController;

MotorController::MotorController(IMotorControlIO& MotorX,
                                 IMotorControlIO& MotorY,
                                 IMotorControlIO& MotorZ) : 
                                                            _MotorX(MotorX),
                                                            _MotorY(MotorY),
                                                            _MotorZ(MotorZ) {}




void MotorController::MoveToCoordinate(std::int32_t args...)
{
    va_list list;
    va_start(list, args);

    std::int32_t i = args;

    std::int32_t X = 0;
    std::int32_t Y = 0;
    std::int32_t Z = 0;

    while (i--)
    {
        if(i == 2)
        {
            X = va_arg(list, std::int32_t);
        }
        if(i == 1)
        {
            Y = va_arg(list, std::int32_t);
        }
        if(i == 0)
        {
            Z = va_arg(list, std::int32_t);
        }
        ++args;
    }
    va_end(list);

    this->_MotorX.MoveToCoordinate(X);
    this->_MotorY.MoveToCoordinate(Y);
    this->_MotorZ.MoveToCoordinate(Z);
}

void MotorController::Rotate(std::int32_t args...)
{
    va_list list;
    va_start(list, args);

    std::int32_t i = args;

    std::int32_t X = 0;
    std::int32_t Y = 0;
    std::int32_t Z = 0;

    while (i--)
    {
        if(i == 2)
        {
            X = va_arg(list, std::int32_t);
        }
        if(i == 1)
        {
            Y = va_arg(list, std::int32_t);
        }
        if(i == 0)
        {
            Z = va_arg(list, std::int32_t);
        }
        ++args;
    }
    va_end(list);

    this->_MotorX.Rotate(X);
    this->_MotorY.Rotate(Y);
    this->_MotorZ.Rotate(Z);
}

void MotorController::SetCurrentPositionAsZero()
{
    this->_MotorX.SetCurrentPositionAsZero();
    this->_MotorY.SetCurrentPositionAsZero();
    this->_MotorZ.SetCurrentPositionAsZero();
}


void MotorController::OnReception(const char* data)
{
    auto _cmd = static_cast<MotorControllerCmd>(data[0]);

    std::int32_t X = 0;
    std::int32_t Y = 0;
    std::int32_t Z = 0;

    switch (_cmd)
    {
    case MotorControllerCmd::SayHelloWorld:
        //TODO
        break;
    case MotorControllerCmd::MoveToCoordinate:
        //TODO
        break;
    case MotorControllerCmd::RotateStepper:
        X += 1000 * static_cast<std::int32_t>(data[3]  - 0x30);
        X += 100 *  static_cast<std::int32_t>(data[4]  - 0x30);
        X += 10 *   static_cast<std::int32_t>(data[5]  - 0x30);
        X +=        static_cast<std::int32_t>(data[6]  - 0x30);
        if (data[2] == '-')
        {
            X = -X;
        }

        Y += 1000 * static_cast<std::int32_t>(data[9]  - 0x30);
        Y += 100 *  static_cast<std::int32_t>(data[10] - 0x30);
        Y += 10 *   static_cast<std::int32_t>(data[11] - 0x30);
        Y +=        static_cast<std::int32_t>(data[12] - 0x30);
        if (data[8] == '-')
        {
            Y = -Y;
        }

        Z += 1000 * static_cast<std::int32_t>(data[15] - 0x30);
        Z += 100 *  static_cast<std::int32_t>(data[16] - 0x30);
        Z += 10 *   static_cast<std::int32_t>(data[17] - 0x30);
        Z +=        static_cast<std::int32_t>(data[18] - 0x30);
        if (data[14] == '-')
        {
            Z = -Z;
        }
        this->Rotate(3U, X, Y, Z);  //FIXME instead of 3 make it calculate number of arguments
        break;
    case MotorControllerCmd::SetCurrentPositionAsZero:
        //TODO
        break;
    case MotorControllerCmd::ForceStopMovement:
        //TODO
        break;
    case MotorControllerCmd::ForceStopAll:
        //TODO
        break;
    case MotorControllerCmd::RotateFoodDispenser:
        //TODO
        break;
    case MotorControllerCmd::RotateWaterPump:
        //TODO
        break;
    case MotorControllerCmd::FeedWater:
        //TODO
        break;
    default:
        break;
    }
}
#include "motor_controller.hpp"
#include "command_factory.hpp"

using namespace devices::motorController;

void CommandFactory::BuildSayHelloWorld(Frame buffer)
{
    buffer[0]  = static_cast<uint8_t>(MotorControllerCmd::SayHelloWorld);
    buffer[1]  = static_cast<uint8_t>('H');
    buffer[2]  = static_cast<uint8_t>('e');
    buffer[3]  = static_cast<uint8_t>('l');
    buffer[4]  = static_cast<uint8_t>('l');
    buffer[5]  = static_cast<uint8_t>('o');
    buffer[6]  = static_cast<uint8_t>('_');
    buffer[7]  = static_cast<uint8_t>('W');
    buffer[8]  = static_cast<uint8_t>('o');
    buffer[9]  = static_cast<uint8_t>('r');
    buffer[10] = static_cast<uint8_t>('l');
    buffer[11] = static_cast<uint8_t>('d');
    buffer[12] = static_cast<uint8_t>('\n');
    buffer[13] = static_cast<uint8_t>('\r');
    buffer[14] = 0xFF;
    buffer[15] = 0xFF;
    buffer[16] = 0xFF;
    buffer[17] = 0xFF;
    buffer[18] = 0xFF;
    buffer[19] = 0xFF;
    buffer[20] = 0xFF;
}
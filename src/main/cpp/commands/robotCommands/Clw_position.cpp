#include "commands/robotCommands/Clw_position.h"

Clw_position::Clw_position(Training* train, double position): drive{train} , position{position}
{
    AddRequirements({drive});

}

void Clw_position::Initialize()
{
    finish = false;
}

void Clw_position::Execute()
{
    drive->SetClw_servoServoAngle(position);
    finish = true;
}

void Clw_position::End(bool interrupted)
{

}

bool Clw_position::IsFinished()
{
    return finish;
}
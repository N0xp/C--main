#include "commands/robotCommands/Arm_position.h"

Arm_position::Arm_position(Training* train, double position): drive{train},position{position}
{
    AddRequirements({drive});

}

void Arm_position::Initialize()
{
    finish = false;
}

void Arm_position::Execute()
{
    drive->SetArm_servoServoAngle(position);
    finish = true;
}
void Arm_position::End(bool interrupted)
{

}
bool Arm_position::IsFinished()
{
    return finish;
}
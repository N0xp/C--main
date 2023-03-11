#include "commands/robotCommands/Mag_position.h"

Mag_position :: Mag_position(Training* train, double position): drive{train},position{position}
{
    AddRequirements({drive});

}

void Mag_position::Initialize()
{
    finish = false;
}

void Mag_position::Execute()
{
    drive->SetMag_servoServoAngle(position);
    finish = true;
}
void Mag_position::End(bool interrupted)
{
    drive -> SetMag_servoServoAngle(0);
}
bool Mag_position::IsFinished()
{
    return finish;
}
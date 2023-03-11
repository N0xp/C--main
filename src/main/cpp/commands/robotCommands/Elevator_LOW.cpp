#include "commands/robotCommands/Elevator_LOW.h"

Elevator_LOW::Elevator_LOW(Elevator* elevator) : elev{elevator}
{
    AddRequirements({elevator});
}

void Elevator_LOW::Initialize()
{
}

void Elevator_LOW::Execute()
{
    elev->SetMotorSpeed(-0.2);
}

void Elevator_LOW:: End(bool interrupted)
{
    elev -> SetMotorSpeed(0);
    elev -> resetEncoder();
}
bool Elevator_LOW::IsFinished()
{
    return(elev->getElevatorLimitLow() == 0);
}
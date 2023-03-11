#include "commands/robotCommands/Elevator_TOP.h"

Elevator_TOP::Elevator_TOP(Elevator* elevator) : elev{elevator}
{
    AddRequirements({elevator});
}

void Elevator_TOP::Initialize()
{
}

void Elevator_TOP::Execute()
{
    elev->SetMotorSpeed(0.6);
}

void Elevator_TOP:: End(bool interrupted)
{
    elev -> SetMotorSpeed(0);
    elev -> resetEncoder();
}
bool Elevator_TOP::IsFinished()
{
    return(elev->getElevatorLimitHigh() == 0);
}
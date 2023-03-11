#include "commands/robotCommands/Elevator_DIS.h"

Elevator_DIS::Elevator_DIS(Elevator* elevator,char direction, double distance) : elev{elevator},direction{direction},distance{distance}
{
    AddRequirements({elevator});
    pid.SetTolerance(1);
}

void Elevator_DIS::Initialize()
{
    if(distance==0)
    {
        elev->resetEncoder();
        pid.Reset();
    }
    if(direction=='d')
    {
        goal=-distance;
        minSpeed=-0.15;
    }
    else 
    {
        goal=distance;
        minSpeed=0.15;
    }

}

void Elevator_DIS::Execute()
{
    pid.Calculate(elev->GetDistance(), goal);
    elev->SetMotorSpeed(std::clamp(pid.Calculate(elev->GetDistance(), goal), -0.2, 0.3)+minSpeed);
}
void Elevator_DIS:: End(bool interrupted)
{
    elev -> SetMotorSpeed(0);
    
}
bool Elevator_DIS::IsFinished()
{
    return pid.AtSetpoint();
}
#include "commands/robotCommands/Rotate720.h"

Rotate720::Rotate720(Training* train,double degree) : drive{train} , degree{degree}
{
    AddRequirements({train});
}

/**
 * Runs once when command is started
 */
void Rotate720::Initialize()
{
    pid.SetTolerance(1.0);
    drive->ResetEncoders();
    drive->ResetYaw();
    pid.Reset();
    
}

/**
 * Called continously until command is ended
 */
void Rotate720::Execute()
{
    drive->HolonomicDrive(00.,
    0.0,
    std::clamp(pid.Calculate(drive->GetAngle(), degree), -0.2, 0.2));
}

/**
 * Called when the command is told to end or is interrupted
 */
void Rotate720::End(bool interrupted)
{
    drive->resetspeed();
    
    
}

/**
 * Creates an isFinished condition if needed
 */
bool Rotate720::IsFinished()
{
    return pid.AtSetpoint();
}
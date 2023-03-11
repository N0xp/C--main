#include "commands/robotCommands/driveForward.h"

driveForward::driveForward(Training* train, double distacne) : drive{train},distacne{distacne} 
{
    AddRequirements({train});

    
}

/**
 * Runs once when command is started
 */
void driveForward::Initialize()
{
  
    pidY.SetTolerance(2);
    pidZ.SetTolerance(0.1);
    pidY.Reset();
    pidZ.Reset();
    drive->ResetEncoders();
    drive->ResetYaw();
    if(Ygoal<0)
        minYSpeed=-0.12;
    else
        minYSpeed=0.12;

    if(Xgoal<0)
        minXSpeed=-0.21;
    else
        minXSpeed=0.21;


    
}

/**
 * Called continously until command is ended
 */
void driveForward::Execute()
{
    pidY.Calculate(drive->GetAverageForwardEncoder(),distacne);
    drive->HolonomicDrive(
    0.0,
    std::clamp(pidY.Calculate(drive->GetAverageForwardEncoder(), distacne), -0.25,0.25) +minYSpeed ,//Y
    std::clamp(pidZ.Calculate(drive->GetYaw(), 0), -0.005 , 0.005)
    );//Z
    frc::SmartDashboard::PutBoolean("Ygol",Yatgool);
    frc::SmartDashboard::PutBoolean("Xgol",Xatgool);
}

/**
 * Called when the command is told to end or is interrupted
 */
void driveForward::End(bool interrupted)
{
    drive->resetspeed();
}

/**
 * Creates an isFinished condition if needed
 */
bool driveForward::IsFinished()
{
    if(pidY.AtSetpoint())
        return true;
   
                                                                                           
}
  
  

#include "commands/robotCommands/DriveUS.h"

DriveUS :: DriveUS(Training* train,char sensor, double distToWall ) : drive{train}, sensor{sensor},distToWall{distToWall}
{
    AddRequirements({train});
    pidX.SetTolerance(3);
    pidY.SetTolerance(3);
    pidZ.SetTolerance(0.5);
    
}

/**
 * Runs once when command is started
 */
void DriveUS::Initialize()
{

    frc2::WaitCommand(1_s);
    drive->ResetEncoders();
    drive->ResetYaw();
        switch(sensor)
        {
             case 'l':
                prevDist += (drive->GetSonic_LEFT_Distance(true));
                goal=prevDist-distToWall;
            break;
            case 'r':
        
                 prevDist += (drive->GetSonic_RIGHT_Distance(true));
                goal=prevDist-distToWall;
            break;
        }
        if(goal>0)minSpeed=0.13;
        else minSpeed=-0.13;
}

/**
 * Called continously until command is ended
 */
void DriveUS::Execute()
{
    switch(sensor){
            case 'l':

                pidX.Calculate((drive->GetBackEncoder()), goal);
                drive->HolonomicDrive(
                    -(std::clamp(pidX.Calculate((drive->GetBackEncoder()), goal), -0.2, 0.2)+minSpeed),
                    0.0,
                    std::clamp(pidZ.Calculate(drive->GetYaw(), 0), -0.05, 0.05));
            break;
            case 'r': 
            pidX.Calculate((drive->GetBackEncoder()), goal);
            drive->HolonomicDrive(
                (std::clamp(pidX.Calculate((drive->GetBackEncoder()), goal), -0.2, 0.2)+minSpeed),
                0.0,
                std::clamp(pidZ.Calculate(drive->GetYaw(), 0), -0.05, 0.05));
            break;           
    }
    frc::SmartDashboard::PutNumber("the goole", goal);
    frc::SmartDashboard::PutNumber("the preDist", prevDist);
    frc::SmartDashboard::PutNumber("the wall", distToWall);
    
}
/**
 * Called when the command is told to end or is interrupted
 */
void DriveUS::End(bool interrupted)
{
    drive->HolonomicDrive(0.0, 0.0, 0.0);
}

/**
 * Creates an isFinished condition if needed
 */
bool DriveUS::IsFinished()
{
        return pidX.AtSetpoint();
}
  
  

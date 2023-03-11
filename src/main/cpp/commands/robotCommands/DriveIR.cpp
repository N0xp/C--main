#include "commands/robotCommands/DriveIR.h"

DriveIR :: DriveIR(Training* train,char sensor, double distToWall ) : drive{train}, sensor{sensor},distToWall{distToWall}
{
    AddRequirements({train});
    pidX.SetTolerance(3);
    pidY.SetTolerance(3);
    pidZ.SetTolerance(0.5);
    
}

/**
 * Runs once when command is started
 */
void DriveIR::Initialize()
{

    pidY.SetTolerance(3);
    drive->ResetEncoders();
    drive->ResetYaw();
    switch(sensor)
        {
            case 'r':
                for (int x=0; x<50; x++)
                {
                    prevSideDist += (drive->GetIR_rightB_Distance());
                }
                prevSideDist = prevSideDist/50;
              
            break;

            case 'l':
                for (int x=0; x<50; x++)
                {
                    prevSideDist += (drive->GetIR_leftB_Distance());
                }
                prevSideDist = prevSideDist/50;
            break;
        }  
    goal=prevSideDist-distToWall;
    
    if(goal>0)minSpeed=0.1;
    else minSpeed=-0.1;

    
}

/**
 * Called continously until command is ended
 */
void DriveIR::Execute()
{   
    prevSideDist = drive->GetIR_rightB_Distance();
    goal=prevSideDist-distToWall;
    pidY.Calculate(drive->GetAverageForwardEncoder(),goal);
    drive->HolonomicDrive(
        0.0,
        std::clamp(pidY.Calculate(drive->GetAverageForwardEncoder(), goal), -0.2 , 0.2)+minSpeed,
        std::clamp(pidZ.Calculate(drive->GetYaw(),0),-0.05,0.05)+minSpeed);

}

/**
 * Called when the command is told to end or is interrupted
 */
void DriveIR::End(bool interrupted)
{
    drive->HolonomicDrive(0.0, 0.0, 0.0);
}

/**
 * Creates an isFinished condition if needed
 */
bool DriveIR::IsFinished(){

    return pidY.AtSetpoint();

}
  
  

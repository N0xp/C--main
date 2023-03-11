#include "commands/robotCommands/DriveALIGN.h"

DriveALIGN:: DriveALIGN(Training* train): drive{train}
{
    AddRequirements({train});
    pidX.SetTolerance(3);
    pidY.SetTolerance(3);
    pidZ.SetTolerance(0.5);
    
}

/**
 * Runs once when command is started
 */
void DriveALIGN::Initialize()
{
    drive->ResetEncoders();
    drive->ResetYaw();
    acc=0.0022;
    speed=0;
    Lsensor = drive->GetIR_leftB_Distance();
    Rsensor = drive -> GetIR_rightB_Distance();

}

/**
 * Called continously until command is ended
 */
void DriveALIGN::Execute()
{

        Lsensor = drive->GetIR_leftB_Distance();
        Rsensor = drive -> GetIR_rightB_Distance();
        if((Rsensor-Lsensor)>error ){
            drive->HolonomicDrive(0, 0, speed+=acc);
           /* if ((Rsensor-Lsensor)<error)
            {
                drive->HolonomicDrive(0, 0, 0);
                flag_test = 1;
            }*/
            
        }
        else if((Rsensor-Lsensor)<-error) {
            drive->HolonomicDrive(0, 0, -(speed+=acc));
           /* if ((Rsensor-Lsensor)>-error)
            {
                drive->HolonomicDrive(0, 0, 0);
                flag_test = 2;
            }*/
        }
}

/**
 * Called when the command is told to end or is interrupted
 */
void DriveALIGN::End(bool interrupted)
{
    drive->HolonomicDrive(0.0, 0.0, 0.0);
}

/**
 * Creates an isFinished condition if needed
 */
bool DriveALIGN::IsFinished()
{
    if(abs(Rsensor-Lsensor)<error)
        return true;
    else
        return false;
    
}
  
  

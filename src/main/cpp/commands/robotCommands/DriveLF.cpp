#include "commands/robotCommands/DriveLF.h"

DriveLF :: DriveLF(Training* train, int numOfLines, char direction) : drive{train}, numOfLines{numOfLines},direction{direction}
{
    AddRequirements({train});
    pidX.SetTolerance(3);
    pidY.SetTolerance(3);
    pidZ.SetTolerance(0.5);
    
}

/**
 * Runs once when command is started
 */
void DriveLF::Initialize()
{
    linesCounted = 0;

    drive->ResetEncoders();
    drive->ResetYaw();
        switch(direction)
        {
            case 'l':
                goal = -1500;
                sens1=0;
                sens2=1;
            break;
            case 'r':
                goal = 1500;
                sens1=2;
                sens2=3;
            break;
        }
}

/**
 * Called continously until command is ended
 */
void DriveLF::Execute()
{
    drive->HolonomicDrive(
        std::clamp(pidX.Calculate(drive->GetBackEncoder(),goal), -0.5+(linesCounted/10.0), 0.5-(linesCounted/10.0)),
        0.0,
        std::clamp(pidZ.Calculate(drive->GetYaw(),0),-0.5,0.5)
    );
    cobraCH2 = drive->GetCobraVoltage(sens2);
    cobraCH1 = drive->GetCobraVoltage(sens1);

    if (abs(drive->GetBackEncoder())>50 && cobraCH2 > 2.7 && cobraCH1 > 2.7 && !set){//trying 3.5V as reference
        set=true;
        linesCounted++;
    }
    else if (cobraCH2 < 1.0 && cobraCH1 < 1.0)set=false;

}

/**
 * Called when the command is told to end or is interrupted
 */
void DriveLF::End(bool interrupted)
{
    drive->HolonomicDrive(0.0, 0.0, 0.0);
}

/**
 * Creates an isFinished condition if needed
 */
bool DriveLF::IsFinished()
{
        if (linesCounted == numOfLines) return true;
        else return false;
}
  
  

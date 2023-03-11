#include "commands/robotCommands/DriveWithPID.h"

DriveWithPID::DriveWithPID(Training* train, double setPointX, double setPointY, double setPointZ, double epsilonX, double epsilonY, double epsilonZ,bool falgF) : drive{train}, setPointX{setPointX}, setPointY{setPointY}, setPointZ{setPointZ}, epsilonX{epsilonX}, epsilonY{epsilonY}, epsilonZ{epsilonZ} ,falgF{falgF}
{
    AddRequirements({train});
    Ygoal = setPointY;
    Xgoal = setPointX;
    
}

/**
 * Runs once when command is started
 */
void DriveWithPID::Initialize()
{

    pidX.SetTolerance(epsilonX);// the acceptable error 
    pidY.SetTolerance(epsilonY);// the acceptable error 
    pidZ.SetTolerance(epsilonZ);// the acceptable error 
    //frc2::WaitCommand(0.05_s);
    //pidX.Reset();
    //frc2::WaitCommand(0.05_s);
    //pidY.Reset();
    //frc2::WaitCommand(0.05_s);
   // pidZ.Reset();
    //frc2::WaitCommand(0.05_s);
    drive->ResetEncoders();
    //frc2::WaitCommand(0.05_s);
    drive->ResetYaw();
    //frc2::WaitCommand(0.05_s);
    if(Ygoal<0)
        minYSpeed=-0.09;
    else
        minYSpeed=0.09;

    if(Xgoal<0)
        minXSpeed=-0.12;
    else
        minXSpeed=0.12;

    if (falgF == true)
        flag = 1;
    else 
        flag = 0;
}

/**
 * Called continously until command is ended
 */
void DriveWithPID::Execute()
{

    pidY.Calculate(drive->GetAverageForwardEncoder(),setPointY);
    pidX.Calculate(drive->GetBackEncoder(),setPointX);
    drive->HolonomicDrive(
    std::clamp(pidX.Calculate(drive->GetBackEncoder(), setPointX), (-0.2+(-0.3*flag)) ,0.2+(0.3*flag))+ minXSpeed  ,//X
    std::clamp(pidY.Calculate(drive->GetAverageForwardEncoder(), setPointY), -0.15+(-0.25*flag),0.15+(0.25*flag))+minYSpeed  ,//Y
    std::clamp(pidZ.Calculate(drive->GetYaw(), setPointZ), -0.05+(0.04*flag) , 0.05+(-0.04*flag))
    );//Z
    frc::SmartDashboard::PutBoolean("ygool",Yatgool);
    frc::SmartDashboard::PutBoolean("Xgool",Xatgool);
}

/**
 * Called when the command is told to end or is interrupted
 */
void DriveWithPID::End(bool interrupted)
{
    drive->HolonomicDrive(0.0, 0.0, 0.0);
    drive->ResetEncoders();
    drive->ResetYaw();

}

/**
 * Creates an isFinished condition if needed
 */
bool DriveWithPID::IsFinished()
{
        if((pidY.AtSetpoint()))
        {
            minYSpeed=0;
            Yatgool=true;
        }
        if((pidX.AtSetpoint()))
        {
            minXSpeed=0;
            Xatgool=true;
            
        }
        if(Yatgool || Xatgool )
            return true;
        else 
            return false;
}
  
  

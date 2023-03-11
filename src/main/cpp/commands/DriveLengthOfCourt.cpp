#include "commands/DriveLengthOfCourt.h"
#include "commands/Initial_position.h"
#include "commands/robotCommands/DriveWithPID.h"
#include "commands/robotCommands/Elevator_DIS.h"
#include "commands/robotCommands/DriveLF.h"
#include "commands/robotCommands/Rotate720.h"
#include "commands/robotCommands/driveForward.h"
#include "commands/robotCommands/DriveUS.h"
#include "commands/robotCommands/DriveIR.h"
#include "commands/robotCommands/Elevator_TOP.h"
#include "commands/robotCommands/Elevator_LOW.h"
#include <frc2/command/ParallelRaceGroup.h>

DriveLengthOfCourt::DriveLengthOfCourt(Training* drive, Elevator* elevator)
{
    AddCommands
    (  
        Initial_position(drive, elevator)
  
        //Rotate720(drive,0),
        //DriveWithPID(drive,0, 700.0, 0.0, 0.0, 1.0, 0.1,true).WithTimeout(5_s),
        //DriveWithPID(drive,-600, 0.0, 0.0, 2.0, 0.0, 0.1,false).WithTimeout(5_s),
       //DriveUS(drive,'l',100).WithTimeout(6_s)
        //frc2::WaitCommand(3_s),
        //DriveIR(drive,'r',20)
        //deRotate720(drive,0),
        //frc2::WaitCommand(3_s),
       // Rotate720(drive,90)
     
    );
}

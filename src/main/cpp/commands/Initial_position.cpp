#include "commands/Initial_position.h"
#include "commands/robotCommands/Rotate720.h"
#include "commands/robotCommands/DriveWithPID.h"
#include <frc2/command/ParallelRaceGroup.h>
#include "commands/robotCommands/DriveWithPID.h"
#include "commands/robotCommands/Elevator_DIS.h"
#include "commands/robotCommands/DriveLF.h"
#include "commands/robotCommands/Rotate720.h"
#include "commands/robotCommands/driveForward.h"
#include "commands/robotCommands/DriveUS.h"
#include "commands/robotCommands/DriveIR.h"
#include "commands/robotCommands/Elevator_TOP.h"
#include "commands/robotCommands/Elevator_LOW.h"
#include "commands/robotCommands/Mag_position.h"
#include"commands/robotCommands/Arm_position.h"
#include <frc2/command/ParallelRaceGroup.h>

Initial_position::Initial_position(Training* drive,Elevator* elevator)
{
    AddCommands
    (
        Rotate720(drive,0),
        Mag_position(drive,100),
        Arm_position(drive,222),
        Elevator_TOP(elevator).WithTimeout(2_s),
        Elevator_LOW(elevator).WithTimeout(2_s),
        Elevator_DIS(elevator,'u',30),
        
        Arm_position(drive,120)

        
    );
}
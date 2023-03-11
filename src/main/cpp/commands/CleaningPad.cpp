#include "commands/CleaningPad.h"

#include "commands/robotCommands/Rotate720.h"
#include "commands/robotCommands/DriveWithPID.h"

#include <frc2/command/ParallelRaceGroup.h>
CleaningPad::CleaningPad(Training* drive)
{
    AddCommands
    (
        Rotate720(drive,90),
        frc2::WaitCommand(3_s)
        
    );
}
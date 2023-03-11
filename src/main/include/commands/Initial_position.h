#pragma once

#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Training.h"
#include "subsystems/Elevator.h"

class Initial_position : public frc2::CommandHelper<frc2::SequentialCommandGroup, Initial_position>
{
    public:
        Initial_position(Training* drive,Elevator* elevator);
};
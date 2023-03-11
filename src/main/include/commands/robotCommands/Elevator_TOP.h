#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc/controller/PIDController.h>

#include "subsystems/Elevator.h"
#include "RobotContainer.h"

class Elevator_TOP : public frc2::CommandHelper<frc2::CommandBase, Elevator_TOP>
{
    public:
        Elevator_TOP(Elevator* elevator);
        void Initialize() override;
        void Execute() override;
        void End(bool interrupted) override;
        bool IsFinished() override;
    
    private:   
        Elevator* elev; 

};
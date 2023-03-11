#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc/controller/PIDController.h>

#include "subsystems/Elevator.h"
#include "RobotContainer.h"

class Elevator_LOW : public frc2::CommandHelper<frc2::CommandBase, Elevator_LOW>
{
    public:
        Elevator_LOW(Elevator* elevator);
        void Initialize() override;
        void Execute() override;
        void End(bool interrupted) override;
        bool IsFinished() override;
    
    private:   
        Elevator* elev; 

};
#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc/controller/PIDController.h>

#include "subsystems/Elevator.h"
#include "RobotContainer.h"

class Elevator_DIS : public frc2::CommandHelper<frc2::CommandBase, Elevator_DIS>
{
    public:
        Elevator_DIS(Elevator* elevator, char direction , double distance);
        void Initialize() override;
        void Execute() override;
        void End(bool interrupted) override;
        bool IsFinished() override;
    
    private:   
        Elevator* elev; 
        double distance;
        double goal;
        double minSpeed;
        char direction;
        double kP = 1;
        double kI = 0;
        double kD = 0;
        frc2::PIDController pid{kP, kI, kD};
        
};
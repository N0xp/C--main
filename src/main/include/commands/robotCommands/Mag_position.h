#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc/controller/PIDController.h>

#include "subsystems/Training.h"
#include "RobotContainer.h"

class Mag_position : public frc2::CommandHelper<frc2::CommandBase,Mag_position>
{
    public:
        Mag_position(Training* train, double position);
        void Initialize() override;
        void Execute() override;
        void End(bool interrupted) override;
        bool IsFinished() override;
    private:
        Training* drive;
        double position;
        bool finish;
};
#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc/controller/PIDController.h>

#include "subsystems/Training.h"
#include "RobotContainer.h"

class DriveALIGN : public frc2::CommandHelper<frc2::CommandBase, DriveALIGN>
{
    public:
        DriveALIGN(Training* train);
        void Initialize() override;
        void Execute() override;
        void End(bool interrupted) override;
        bool IsFinished() override;
    
    private: 
        Training* drive;
        double Lsensor;
        double Rsensor;
        double error = 1; 
        double speed , acc;

        double kPx = 0.05;
        double kIx = 0;
        double kDx = 0; //10

        double kPy = 0.02;
        double kIy = 0;
        double kDy = 0;

        double kPz = 0.05;
        double kIz = 0;
        double kDz = 0;

        frc2::PIDController pidX{kPx, kIx, kDx};
        frc2::PIDController pidY{kPy, kIy, kDy};
        frc2::PIDController pidZ{kPz, kIz, kDz};
};
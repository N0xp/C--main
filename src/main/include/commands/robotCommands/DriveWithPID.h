#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc/controller/PIDController.h>
#include <frc2/command/PIDSubsystem.h>
#include "subsystems/Training.h"
#include "RobotContainer.h"

class DriveWithPID : public frc2::CommandHelper<frc2::CommandBase, DriveWithPID>
{
    public:
        DriveWithPID(Training* train, double setPointX, double setPointY, double setPointZ, double epsilonX, double epsilonY, double epsilonZ, bool falgF);
        void Initialize() override;
        void Execute() override;
        void End(bool interrupted) override;
        bool IsFinished() override;

    private: 
        Training* drive;
     
        double setPointX, setPointY, setPointZ;
        double epsilonX, epsilonY, epsilonZ;
        bool falgF;
        int flag;
        bool    Yatgool = false;
        bool    Xatgool = false;
        double minYSpeed;
        double minXSpeed;
        double Ygoal;
        double Xgoal;

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
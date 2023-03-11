#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc/controller/PIDController.h>

#include "subsystems/Training.h"
#include "RobotContainer.h"

class DriveLF : public frc2::CommandHelper<frc2::CommandBase, DriveLF>
{
    public:
        DriveLF(Training* train, int numOfLines, char direction );
        void Initialize() override;
        void Execute() override;
        void End(bool interrupted) override;
        bool IsFinished() override;
    
    private: 
        Training* drive;
        int linesCounted;
        int numOfLines;
        char direction;
        double goal;
        double cobraCH2, cobraCH1;
        bool set;
        int sens1=0;
        int sens2=0;

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
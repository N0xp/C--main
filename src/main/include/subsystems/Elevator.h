#pragma once
#include <frc2/command/SubsystemBase.h>
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/DigitalInput.h>


#include "Constants.h"
#include "studica/TitanQuad.h"
#include "studica/TitanQuadEncoder.h"
#include <frc/controller/PIDController.h>

class Elevator : public frc2::SubsystemBase
{
    public:
        Elevator();
        void Periodic() override;
        void resetEncoder();
        void SetMotorSpeed(double speed);
        double GetDistance(void);
        bool getElevatorLimitLow(void);
        bool getElevatorLimitHigh(void);
        bool limitLOWva;
        frc::DigitalInput high_limit_eleviator{9};
        frc::DigitalInput low_limit_eleviator{5};
    private:
        bool lowResult = true;
        bool highResult = false;



        
        studica::TitanQuad Elevator_motor{constant::TITAN_ID, 15600, constant::Elevator_motor};
        studica::TitanQuadEncoder encoder{Elevator_motor, constant::ENCODER_NUM_EL, constant::DIST_PER_TICK_EL};
        double kP = 1;
        double kI = 0;
        double kD = 0;

        frc2::PIDController pid{kP, kI, kD,};
};
#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include <frc/controller/PIDController.h>
#include <frc2/command/PIDSubsystem.h>
#include "subsystems/Training.h"
#include "gamepad/OI.h"
#include "subsystems/Elevator.h"
#include "commands/robotCommands/Elevator_DIS.h"

class ManualDrive : public frc2::CommandHelper<frc2::CommandBase, ManualDrive> 
{
    public:
        explicit ManualDrive(Training* training, OI* oi,Elevator* elevator);

        void Initialize() override;
        void Execute() override;
        void End(bool interrupted) override;
        bool IsFinished() override;
    
    private:
        //motor mvment 
        double inputLeftY = 0;
        double inputLeftX = 0;
        double inputRightY = 0;
        double inputRightX = 0;

      

        double deltaLeftY = 0;
        double deltaLeftX = 0;
        double deltaRightX = 0;
        double deltaRightY = 0;
        double prevRightX = 0;
        double prevRightY = 0;
        double prevLeftX = 0;
        double prevLeftY = 0;

        // elevator mevment
        double dpad_Y;
        bool inputRightTriger = 0;
        bool inputLeftTriger = 0; 
        double init_speedUP = 0.5;
        double init_speedDown = 0.6;
        double distance;
        double goal = 0;
        double minSpeedup = 0.15;
        double minSpeeddown = -0.15;
        double kP = 1;
        double kI = 0;
        double kD = 0;
        frc2::PIDController pid{kP, kI, kD};
        //Servo movment
        bool servo_forward = 0;
        bool servo_back = 0;
        bool servo_CLW = 0;
        double angleMG = 0;
        double angleARM = 5;
        double angleCLW = 0;
        double ctr;

        static constexpr double RAMP_UP = 0.05;

        static constexpr double RAMP_DOWN = 0.05;

        static constexpr double DELTA_LIMIT = 0.075;

        Training* train;
        OI* oi;
        Elevator* elevator;

        
};
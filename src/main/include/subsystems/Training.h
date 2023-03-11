#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/DigitalInput.h>
#include <frc/DigitalOutput.h>
#include <frc/Ultrasonic.h>
#include <frc/shuffleboard/Shuffleboard.h>

#include "frc/AnalogInput.h"
#include "Constants.h"
#include "studica/TitanQuad.h"
#include "studica/TitanQuadEncoder.h"
#include "studica/Cobra.h"
#include "studica/Servo.h"
#include "studica/ServoContinuous.h"
#include <frc2/command/WaitCommand.h>

#include "AHRS.h"
#include <math.h>



class Training : public frc2::SubsystemBase
{
    public:
        Training();

        void Periodic() override;
        double GetLeftEncoder(void);
        double GetBackEncoder(void);
        double GetRightEncoder(void);
        double GetAverageEncoderY(void);
        double GetAverageForwardEncoder(void);
        void SetMotorSpeed(double speed);
        double GetYaw(void);
        double GetAngle(void);
        void ResetYaw(void);
        void resetspeed(void);
        void ResetEncoders(void);
        void HolonomicDrive(double x, double y, double z);
        void SetRunningLED(bool on);
        void SetStoppedLED(bool on);

        //sensor setup 
        int GetCobraRawValue(int channel);
        double GetCobraVoltage(int channel);
        int getAvarageCobraValue();
        int getAvarageVoltageValue();
 
        double GetIR_rightB_Distance(void);
        double GetIR_leftB_Distance(void);
        double GetSonic_RIGHT_Distance(bool metric);
        double GetSonic_LEFT_Distance(bool metric);
      

        // servos setup 
        void SetArm_servoServoAngle(double degrees);
        void SetMag_servoServoAngle(double degrees);
        void SetClw_servoServoAngle(double degrees);
        double getMag_servoServoAngle();

        //servo switch 
        bool MagForwardLimit();
        bool MagBackLimit();
        double value;
        
        nt::NetworkTableEntry val;
    private:
        // Motors and Encoders 
        studica::TitanQuad RIGHT{constant::TITAN_ID, 15600, constant::RIGHT};
        studica::TitanQuad LEFT{constant::TITAN_ID, 15600, constant::LEFT};
        studica::TitanQuad BACK{constant::TITAN_ID, 15600, constant::BACK};
        studica::TitanQuadEncoder LeftEncoder{LEFT, constant::LEFT, constant::DIST_PER_TICK};
        studica::TitanQuadEncoder backEncoder{BACK, constant::BACK, constant::DIST_PER_TICK};
        studica::TitanQuadEncoder RightEncoder{RIGHT, constant::RIGHT, constant::DIST_PER_TICK};
        AHRS navX{frc::SPI::Port::kMXP};
        //Sensors 
        studica::Cobra cobra{};
        frc::Ultrasonic sonicR{constant::SONIC_TRIGGR, constant::SONIC_ECHOR};
        frc::Ultrasonic sonicL{constant::SONIC_TRIGGL, constant::SONIC_ECHOL};
        frc::AnalogInput sharp_left{constant::SHARP1};
        frc::AnalogInput sharp_right{constant::SHARP2};

        AHRS *gyro;
        //LEDs
        frc::DigitalInput startButton{constant::START_BUTTON};
        frc::DigitalInput stopButton{constant::STOP_BUTTON};
        frc::DigitalOutput runningLED{constant::RUNNING_LED};
        frc::DigitalOutput stoppedLED{constant::STOPPED_LED};
        // servos 

        studica::Servo Arm_servo{constant::Arm_servo};
        studica::Servo Clw_servo{constant::Clw_servo};
        studica::Servo Mag_servo{constant::Mag_servo};
        // Holonomic speed variables 
        double RightSpeed;
        double LeftSpeed;
        double BackSpeed;
        double max;
        //Holonomic Variables
        double front_left = 0;
        double back_left = 0;
        double front_right = 0;
        double back_right = 0;
        double denomonator = 0;
};
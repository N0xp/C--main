#include "subsystems/Training.h"

#define DEBUG true

Training::Training()
{
    // mOTORS SET
    ResetEncoders();
    ResetYaw();

    //Motor Invert Flags comment out when needed
    //LEFT.SetInverted(true);
    LEFT.InvertRPM();
    //LeftEncoder.SetReverseDirection();

    //BACK.SetInverted(true);
    BACK.InvertRPM();
    backEncoder.SetReverseDirection();

    //RIGHT.SetInverted(true);
    RIGHT.InvertRPM();
    //RightEncoder.SetReverseDirection();

    //sensors SET
    sonicR.SetAutomaticMode(true);
    sonicL.SetAutomaticMode(true);
    // gyro = new AHRS(frc::SPI::Port::kMXP);
    // val = frc::Shuffleboard::GetTab("Servo Controller")
    //                                 .Add("Mag servo",1)
    //                                 .WithWidget(frc::BuiltInWidgets::kNumberSlider)
    //                                 .WithProperties({
    //                                     {"min",nt::Value::MakeDouble(-180)},
    //                                     {"max",nt::Value::MakeDouble(180)}
    //                                 })
    //                                 .GetEntry();
}

void Training::Periodic()
{
    //Only want this data for testing. Using during robot runtime would be extra overhead not needed.
    #if DEBUG

        //frc::SmartDashboard::PutNumber("Cobra Raw Value", GetCobraRawValue(constant::COBRA_CHANNEL));

        frc::SmartDashboard::PutNumber("Cobra Raw Voltage1", GetCobraVoltage(constant::COBRA_CHANNEL1));
        frc::SmartDashboard::PutNumber("Cobra Raw Voltage2", GetCobraVoltage(constant::COBRA_CHANNEL2));
        frc::SmartDashboard::PutNumber("Cobra Raw Voltage3", GetCobraVoltage(constant::COBRA_CHANNEL3));
        frc::SmartDashboard::PutNumber("Cobra Raw Voltage0", GetCobraVoltage(constant::COBRA_CHANNEL0));

        frc::SmartDashboard::PutNumber("IR back left Distance", GetIR_leftB_Distance());
        frc::SmartDashboard::PutNumber("IR back right Distance", GetIR_rightB_Distance());

        frc::SmartDashboard::PutNumber("UltraSonic RIGHT Distance", GetSonic_RIGHT_Distance(true));
        frc::SmartDashboard::PutNumber("UltraSonic LEFT Distance", GetSonic_LEFT_Distance(true));
        frc::SmartDashboard::PutNumber("Yaw", GetYaw());
        frc::SmartDashboard::PutNumber("Angle", GetAngle());
        frc::SmartDashboard::PutNumber("Left Encoder", GetLeftEncoder());
        frc::SmartDashboard::PutNumber("Back  Encoder", GetBackEncoder());
        frc::SmartDashboard::PutNumber("rigt  Encoder", GetRightEncoder());
        frc::SmartDashboard::PutNumber("Left RPM", LEFT.GetRPM());
        frc::SmartDashboard::PutNumber("Back  RPM", BACK.GetRPM());
        frc::SmartDashboard::PutNumber(" Right RPM", RIGHT.GetRPM());
        frc::SmartDashboard::PutNumber("forward avarage ", GetAverageForwardEncoder());
        frc::SmartDashboard::PutNumber("bach encoder ", GetBackEncoder());
           frc::SmartDashboard::PutNumber("mag position ", getMag_servoServoAngle());


        // val = frc::Shuffleboard::GetTab("Servo Controller")
        //                             .Add("Mag servo",1)
        //                             .WithWidget(frc::BuiltInWidgets::kNumberSlider)
        //                             .WithProperties({
        //                                 {"min",nt::Value::MakeDouble(-180)},
        //                                 {"max",nt::Value::MakeDouble(180)}
        //                             })
        //                             .GetEntry();
        
        
                                
    
    #endif

    
    //Mag_servo.SetAngle(val.GetDouble(0));
}

void Training::ResetEncoders()
{
    LeftEncoder.Reset();
    frc2::WaitCommand(0.003_s);
    backEncoder.Reset();
    frc2::WaitCommand(0.003_s);
    RightEncoder.Reset();
    frc2::WaitCommand(0.003_s);
}

void Training::ResetYaw()
{
    navX.ZeroYaw();
}

void Training::HolonomicDrive(double x, double y, double z)
{
    denomonator = fmax(fabs(y) + fabs(x) + fabs(z), 1.0);
    LeftSpeed = (((x / 3) + (y / sqrt(3)) + z) * sqrt(3));
    RightSpeed = (((x / 3) - (y / sqrt(3)) + z) * sqrt(3));
    BackSpeed = (((-2 * x / 3) + z) * sqrt(3));//
   
   max = fabs(RightSpeed);
   if (fabs(LeftSpeed)> max) max = fabs(LeftSpeed);
   if (fabs(BackSpeed) > max) max = fabs(BackSpeed);

   if( max > 1)
   {
        RightSpeed /= max;
        LeftSpeed /= max;
        BackSpeed /= max;
   }

   LEFT.Set(LeftSpeed);
   frc2::WaitCommand(0.003_s);
   RIGHT.Set(RightSpeed);
   frc2::WaitCommand(0.003_s);
   BACK.Set(BackSpeed);
   frc2::WaitCommand(0.003_s);

}
void Training::resetspeed(void)
{
    LEFT.Set(0);
    frc2::WaitCommand(0.005_s);
    RIGHT.Set(0);
    frc2::WaitCommand(0.005_s);
    BACK.Set(0);
    
}

void Training::SetRunningLED(bool on)
{
    runningLED.Set(on);
}

void Training::SetStoppedLED(bool on)
{
    stoppedLED.Set(on);
}

double Training::GetLeftEncoder()
{
    return LeftEncoder.GetEncoderDistance()  ;
}
double Training::GetAverageForwardEncoder()
{
    return (((GetLeftEncoder()) + (GetRightEncoder())) / 2)*1.134;
}

double Training::GetBackEncoder()
{
    return backEncoder.GetEncoderDistance();
}

double Training::GetRightEncoder()
{
    return RightEncoder.GetEncoderDistance() * -1 ;
}

double Training::GetYaw()
{
    return navX.GetYaw();
}

double Training::GetAngle()
{
    return navX.GetAngle();
}

// Sensors values 

// cobra vaulues 
int Training::GetCobraRawValue(int channel)
{
    return cobra.GetRawValue(channel);
}

double Training::GetCobraVoltage(int channel)
{
    return cobra.GetVoltage(channel);
}

int Training::getAvarageCobraValue()
{
    return(((GetCobraRawValue(0)*-1) + GetCobraRawValue(3))/2);
}

int Training::getAvarageVoltageValue()
{
    return(((GetCobraVoltage(0)*-1) + GetCobraVoltage(3))/2);
}
// IR sensor 

double Training::GetIR_leftB_Distance(void)
{
    return(pow(sharp_left.GetAverageVoltage(), -1.2045)) * 27.726;
}


double Training::GetIR_rightB_Distance(void)
{
    return(pow(sharp_right.GetAverageVoltage(), -1.2045)) * 27.726;
}

// sonic distance 
double Training::GetSonic_RIGHT_Distance(bool metric)
{
    sonicR.Ping();
    frc2::WaitCommand(0.03_s);
    return metric ? sonicR.GetRangeMM() : sonicR.GetRangeInches();
}

double Training::GetSonic_LEFT_Distance(bool metric)

{
    sonicL.Ping();
    frc2::WaitCommand(0.03_s);
    return metric ? sonicL.GetRangeMM() : sonicL.GetRangeInches();
}



// servo 

void Training::SetArm_servoServoAngle(double degree)
{
    Arm_servo.SetAngle(degree);
}

void Training::SetClw_servoServoAngle(double degree)
{
    Clw_servo.SetAngle(degree);
}

void Training::SetMag_servoServoAngle(double degree)
{
    Mag_servo.SetAngle(degree);
}

double Training::getMag_servoServoAngle()
{
    Mag_servo.GetAngle();
}
#include "subsystems/Elevator.h"

/**
 * Constructor
 */ 
Elevator::Elevator()
{
    encoder.Reset();
}
void Elevator::resetEncoder()
{
    encoder.Reset();
}
/**
 * Periodic loop
 * 
 * Good place to put sensor outputs for user to view
 */
void Elevator::Periodic()
{
    frc::SmartDashboard::PutNumber("Encoder Distance (mm)", GetDistance());
     frc::SmartDashboard::PutBoolean("high limit", getElevatorLimitHigh());
     frc::SmartDashboard::PutBoolean("low limit", getElevatorLimitLow());
}

/**
 * Sets the motor speed
 * 
 * @param speed -1 to 1 (0 stop)
 */ 
void Elevator::SetMotorSpeed(double speed)
{
    Elevator_motor.Set(speed);
    //Elevator_motor.GetLimitSwitch(ture); //  ture high for flase for low  
}

/**
 * Get distance elevator has traveled
 * 
 * @return encoder distance
 * 
 * This will return distance in mm as the PULLEY_RADIUS in Constants.h is in mm.
 */ 
double Elevator::GetDistance()
{
   return encoder.GetEncoderDistance();
}

bool Elevator::getElevatorLimitLow()
{
   return Elevator_motor.GetLimitSwitch(true);
}

bool Elevator::getElevatorLimitHigh()
{
    return Elevator_motor.GetLimitSwitch(true);
}

#include "gamepad/OI.h"
#include "frc/Joystick.h"

#include <cmath>
#define DEBUG true

frc::Joystick drivePad(DRIVE_USB_PORT);

/**
 * @return the y-axis value from the drivePad right joystick
 */
double OI::GetRightDriveY(void)
{
    double joy = drivePad.GetRawAxis(RIGHT_ANALOG_Y);
    if(fabs(joy) < 0.05)
        return 0.0;
    else
        return joy;
}

/**
 * @return the x-axis value from the drivePad right joystick
 */
double OI::GetRightDriveX(void)
{
    double joy = drivePad.GetRawAxis(RIGHT_ANALOG_X);
    if(fabs(joy) < 0.05)
        return 0.0;
    else
        return joy;
}



/**
 * @return the y-axis value from the drivePad left joystick
 */
double OI::GetLeftDriveY(void)
{
    double joy = drivePad.GetRawAxis(LEFT_ANALOG_Y);
    if(fabs(joy) < 0.05)
        return 0.0;
    else
        return joy;
}

/**
 * @return the x-axis value from the drivePad left joystick
 */
double OI::GetLeftDriveX(void)
{
    double joy = drivePad.GetRawAxis(LEFT_ANALOG_X);
    if(fabs(joy) < 0.05)
        return 0.0;
    else
        return joy;
}

/**
 * @return a true or false depending on the input
 */
bool OI::GetDriveRightTrigger(void)
{
    return drivePad.GetRawButton(RIGHT_TRIGGER);
}

/**
 * @return a true or false depending on the input
 */
bool OI::GetDriveRightBumper(void)
{
    return drivePad.GetRawAxis(RIGHT_BUMPER);
}

/**
 * @return a true or false depending on the input
 */
bool OI::getDriveLeftTrigger(void)
{
    return drivePad.GetRawButton(LEFT_TRIGGER);
}

/**
 * @return a true or false depending on the input
 */
bool OI::GetDriveLeftBumper(void)
{
    return drivePad.GetRawAxis(LEFT_BUMPER);
}

/**
 * @return a true or false depending on the input
 */
bool OI::GetDriveXButton(void)
{
    return drivePad.GetRawButtonPressed(X_BUTTON);
}

/**
 * @return a true or false depending on the input
 */
bool OI::GetDriveSquareButton(void)
{
    return drivePad.GetRawButton(SQUARE_BUTTON);
}

/**
 * @return a true or false depending on the input
 */
bool OI::GetDriveCircleButton(void)
{
    return drivePad.GetRawButton(CIRCLE_BUTTON);
}

/**
 * @return a true or false depending on the input
 */
bool OI::GetDriveTriangleButton(void)
{
    return drivePad.GetRawButton(TRIANGLE_BUTTON);
}

/**
 * @return a true or false depending on the input
 */
bool OI::GetDriveOptionsButton(void)
{
    return drivePad.GetRawButton(OPTIONS_BUTTON);
}

/**
 * @return a true or false depending on the input
 */
bool OI::GetDriveShareButton(void)
{
    return drivePad.GetRawButton(SHARE_BUTTON);
}

/**
 * @return a true or false depending on the input
 */
bool OI::GetDriveRightAnalogButton(void)
{
    return drivePad.GetRawButton(RIGHT_ANALOG_BUTTON);
}

/**
 * @return a true or false depending on the input
 */
bool OI::GetDriveLeftAnalogButton(void)
{
    return drivePad.GetRawButton(LEFT_ANALOG_BUTTON);
}

/**
 * @return a true or false depending on the input
 */
bool OI::GetDrivePS4Button(void)
{
    return drivePad.GetRawButton(PS4_BUTTON);
}

/**
 * @return a true or false depending on the input
 */
bool OI::GetDriveTouchpadButton(void)
{
    return drivePad.GetRawButton(TOUCHPAD_BUTTON);
}

void OI::Periodic()
{
    #if DEBUG
        //frc::SmartDashboard::PutNumber("right bumper", GetDriveRightBumper());
        //frc::SmartDashboard::PutNumber("left bumper",GetDriveLeftBumper());

        //frc::SmartDashboard::PutBoolean("right triger", GetDriveRightTrigger());
        //frc::SmartDashboard::PutBoolean("left triger ",getDriveLeftTrigger());

        frc::SmartDashboard::PutBoolean("A ", GetDriveXButton());

        frc::SmartDashboard::PutBoolean("X ",GetDriveSquareButton());

        frc::SmartDashboard::PutBoolean("B", GetDriveCircleButton());

        frc::SmartDashboard::PutBoolean("Y ",GetDriveTriangleButton());

        //frc::SmartDashboard::PutBoolean("Option", GetDriveOptionsButton());

        //frc::SmartDashboard::PutBoolean("share",GetDriveShareButton());
    #endif
}
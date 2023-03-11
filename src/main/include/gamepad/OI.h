#pragma once
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/SubsystemBase.h>

class OI : public frc2::SubsystemBase
{
    public: 
        void Periodic() override;
        double GetRightDriveY(void);
        double GetRightDriveX(void);
        double GetLeftDriveY(void);
        double GetLeftDriveX(void);
        bool GetDriveRightTrigger(void);
        bool GetDriveRightBumper(void);
        bool getDriveLeftTrigger(void);
        bool GetDriveLeftBumper(void);
        bool GetDriveXButton(void);
        bool GetDriveSquareButton(void);
        bool GetDriveCircleButton(void);
        bool GetDriveTriangleButton(void);
        bool GetDriveOptionsButton(void);
        bool GetDriveShareButton(void);
        bool GetDriveRightAnalogButton(void);
        bool GetDriveLeftAnalogButton(void);
        bool GetDrivePS4Button(void);
        bool GetDriveTouchpadButton(void);
    
    private:
        //Controller Port
        #define DRIVE_USB_PORT              0

        //Button Map
        #define X_BUTTON                    1// A
        #define SQUARE_BUTTON               3// X
        #define CIRCLE_BUTTON               2// B
        #define TRIANGLE_BUTTON             4// Y

        #define LEFT_TRIGGER                5
        #define RIGHT_TRIGGER               6

        #define SHARE_BUTTON                7
        #define OPTIONS_BUTTON              8
        #define LEFT_ANALOG_BUTTON          9
        #define RIGHT_ANALOG_BUTTON         10
        #define PS4_BUTTON                  13
        #define TOUCHPAD_BUTTON             14
        

        #define LEFT_BUMPER                 2
        #define RIGHT_BUMPER                5



        //Joystick Map
        #define LEFT_ANALOG_X               0
        #define LEFT_ANALOG_Y               1
        #define RIGHT_ANALOG_X              3
        #define RIGHT_ANALOG_Y              4

        // DPAD
        
        #define DPAD_X                      4
        #define DPAD_Y                      5

};
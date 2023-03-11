#include "commands/ManualDrive.h"

ManualDrive::ManualDrive(Training* training, OI* oi, Elevator* elevator)
{
    AddRequirements({training, oi,elevator});
    this ->train = training;
    this->oi = oi;
    this->elevator = elevator;
    //pid.SetTolerance(2);
}

void ManualDrive::Initialize(){   
    // angleMG = 0;
    // angleARM = 5;
    // ctr = 0;
    // train->SetClw_servoServoAngle(angleCLW);
    // train->SetMag_servoServoAngle(angleMG);
    // train->SetArm_servoServoAngle(angleARM);
    // train->ResetEncoders();
    // elevator->resetEncoder();
    

}

void ManualDrive::Execute()
{
    /**
     * Get Joystick Data
     */
    inputLeftY = oi->GetLeftDriveY();
    inputLeftX = oi->GetLeftDriveX();
    inputRightY = oi->GetRightDriveY();
    inputRightX = oi->GetRightDriveX();
    inputRightTriger = oi->GetDriveRightTrigger();
    inputLeftTriger = oi->getDriveLeftTrigger();
    servo_forward = oi->GetDriveSquareButton();
    servo_back = oi->GetDriveCircleButton();
    servo_CLW = oi->GetDriveTriangleButton();
    dpad_Y = oi->GetDriveTouchpadButton();
    frc::SmartDashboard::PutNumber("dpad",dpad_Y);
    frc::SmartDashboard::PutNumber("mag position",angleMG);
    frc::SmartDashboard::PutNumber("Arm position",angleARM);
    frc::SmartDashboard::PutNumber("clw position",angleCLW);
    /**
     * ellevator ramp
     **/
        double testvar = inputRightY;
       //deltaRightY  = inputRightY - prevRightY;
        if((inputRightY>=-0.2))
        {
            testvar=inputRightY;
        }
        else
        {
            if(inputRightY<-0.2)
                inputRightY=-0.2;
        }

        
        prevRightY = inputRightY;

    /**
     * Ramp
     */ 
        deltaLeftX = inputLeftX - prevLeftX;
        deltaLeftY = inputLeftY - prevLeftY;
        deltaRightX = inputRightX - prevRightX;
        if(deltaLeftX >= DELTA_LIMIT)
            inputLeftX += RAMP_UP;
        else if (deltaLeftX <= -DELTA_LIMIT)
            inputLeftX -= RAMP_DOWN;
        if(deltaLeftY >= DELTA_LIMIT)
            inputLeftY += RAMP_UP;
        else if (deltaLeftY <= -DELTA_LIMIT)
            inputLeftY -= RAMP_DOWN;
        if(deltaRightX >= DELTA_LIMIT)
            inputRightX += RAMP_UP;
        else if (deltaRightX <= -DELTA_LIMIT)
            inputRightX -= RAMP_DOWN;
        prevLeftY = inputLeftY;
        prevLeftX = inputLeftX;
        prevRightX = inputRightX;

        /**
         * Holonomic Conversion
         * (inputLeftX-inputRightX, -(inputLeftY+inputRightX), (-(inputLeftX-inputLeftX)+inputRightX*2))
         */

        //driveTrain.holonomicDrive(inputLeftX, inputLeftY,inputRightX ); //ORIGINAL CODEinputRightX
        train->HolonomicDrive(inputLeftX, -inputLeftY,inputRightX );


        elevator->SetMotorSpeed(inputRightY);
       

        frc::SmartDashboard::PutNumber("inputRRRR ",inputRightY);
        
    if ((inputLeftTriger == 1) && (servo_forward ==1 ))
        {
            
        train->SetMag_servoServoAngle(angleMG+=0.9);
        }
        
    else if ((inputLeftTriger == 1) && (servo_back ==1 ))
    {
        
        train->SetMag_servoServoAngle(angleMG -= 0.9);
    }


    if ((inputRightTriger == 1) && (servo_forward ==1 ))
        {
        train->SetArm_servoServoAngle(angleARM+=0.9);
        }
    else if (( inputRightTriger== 1) && (servo_back ==1 ))
    {
        
        train->SetArm_servoServoAngle(angleARM -= 0.9);
    }

    if ((inputRightTriger == 1) && (servo_CLW ==1 ))
        {
        train->SetClw_servoServoAngle(angleCLW+=0.9);
        }
    else if (( inputLeftTriger== 1) && (servo_CLW ==1 ))
    {
        
        train->SetClw_servoServoAngle(angleCLW -= 0.9);
    }

    frc::SmartDashboard::PutNumber("counter",ctr);
   

}

void ManualDrive::End(bool interrupted)
{
    train->HolonomicDrive(0, 0, 0);
    elevator->SetMotorSpeed(0);
}

bool ManualDrive::IsFinished()
{
    return false;
}
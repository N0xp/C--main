/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

namespace constant
{
    //Motors
    static constexpr int TITAN_ID       = 42;
    static constexpr int RIGHT     = 3;
    static constexpr int LEFT      = 1;
    static constexpr int BACK     = 0;
    static constexpr int Elevator_motor     = 2;
    //Elevator configuration 
    static constexpr int ENCODER_NUM_EL             = 2;
    static constexpr double PULLEY_RADIUS_EL       = 17; //mm
    static constexpr double PULSE_PER_REVOLUTION_EL    = 1440;
    static constexpr double GEAR_RATIO_EL           = 2/1;
    static constexpr double ENCODER_PULSE_RATIO_EL     = PULSE_PER_REVOLUTION_EL * GEAR_RATIO_EL;
    static constexpr double DIST_PER_TICK_EL           = (M_PI * 2 * PULLEY_RADIUS_EL) / ENCODER_PULSE_RATIO_EL;
    //motor Encoder
    static constexpr double WHEEL_RADIUS    = 51; //mm
    static constexpr double PULSE_PER_REV   = 1440;
    static constexpr double GEAR_RATIO      = 1/1;
    static constexpr double ENCODER_PULSE_RATIO = PULSE_PER_REV * GEAR_RATIO;
    static constexpr double DIST_PER_TICK   =   (M_PI * 2 * WHEEL_RADIUS) / ENCODER_PULSE_RATIO;

    //Inputs
    static constexpr int START_BUTTON   = 9;
    static constexpr int STOP_BUTTON    = 11;

    //Outputs
    static constexpr int RUNNING_LED    = 20;
    static constexpr int STOPPED_LED    = 21;
    
    //sharp sensor 
    static constexpr int SHARP1 = 0;//Analog inputs
    static constexpr int SHARP2= 1;//Analog inputs
    //sonic

    static constexpr int SONIC_TRIGGL = 3; //Digital inputs
    static constexpr int SONIC_ECHOL = 2;//Digital inputs
    static constexpr int SONIC_TRIGGR =1;//Digital inputs
    static constexpr int SONIC_ECHOR = 0;//Digital inputs

    // cobra

    static constexpr int COBRA_CHANNEL0 = 0;
    static constexpr int COBRA_CHANNEL1 = 1;
    static constexpr int COBRA_CHANNEL2 = 2;
    static constexpr int COBRA_CHANNEL3 = 3;
    // Servos 
    static constexpr int Arm_servo = 2;
    static constexpr int Clw_servo = 1;
    static constexpr int Mag_servo = 0;
}
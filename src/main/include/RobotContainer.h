/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/Command.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/shuffleboard/Shuffleboard.h>

#include "commands/ManualDrive.h"
#include "subsystems/Training.h"
#include "gamepad/OI.h"
#include "subsystems/Elevator.h"
#include "commands/DriveLengthOfCourt.h"
#include "commands/CleaningPad.h"
#include "commands/Initial_position.h"


/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();
  Elevator elevator;
  Training training;
  frc2::Command* GetAutonomousCommand();
  
 private:
  //Subsystems
  
  OI oi;

  //Commands

  Initial_position m_Initial_position{&training,&elevator};
  DriveLengthOfCourt m_lengthOfCourt{&training,&elevator};
  CleaningPad m_cleaningPad{&training};

  //Auto Chooser
  frc::SendableChooser<frc2::Command*> chooser;
};

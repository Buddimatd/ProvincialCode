#include "config.hpp"
#include "main.h"
#include "autonhelper.hpp"



void autonomous(){

  drive_pid(400,60);
  drive_pid(-400,60);

  intakeLeft.move_velocity(-200);
  intakeRight.move_velocity(-200);

  drive_pid(3300,35);
  pros::delay(400);

  intakeLeft.move_velocity(0);
  intakeRight.move_velocity(0);

  drive_pid(-2350,110);

  turn(-130);

  drive_pid(700,70);

  intakeLeft.move_velocity(100);
  intakeRight.move_velocity(100);
  pros::delay(350);
  intakeLeft.move_velocity(0);
  intakeRight.move_velocity(0);

  tray.move_velocity(-40);
  pros::delay(6000);
  tray.move_velocity(0);

  drive_pid(-2450,40);


  tray.move_velocity(140);
  intakeLeft.move_velocity(-100);
  intakeRight.move_velocity(-100);





}

#include "config.hpp"
#include "main.h"
#include "autonhelper.hpp"



void autonomous(){
  drive_pid(2700, 75);
  pros::delay(300);
  turn(30);
  drive_pid(500,50);

}

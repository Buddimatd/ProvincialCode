#include "config.hpp"
#include "main.h"
#include "autonhelper.hpp"



void autonomous(){
  // drive_pid(2000, 100);
  // pros::delay(300);
  // turn(-30);
  // pros::delay(100);
  rev_pid(300, 100);
}

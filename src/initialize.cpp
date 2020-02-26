#include "main.h"
#include "config.hpp"
#include <stdio.h>

void initialize(){

   pros::lcd::initialize();
    pros::lcd::set_text(1, "THUSHARA JUULS");
  // imu_sensor.reset();

   //
   //  int time = pros::millis();
   //  int iter = 0;
   // do {
   //    pros::lcd::print(1,"IMU calibrating... %d", iter);
   //    iter += 10;
   //   pros::delay(10);
   // } while(imu_sensor.is_calibrating());
   // // should print about 2000 ms
   // pros::lcd::print(1, "Intalization Complete took %dms", iter - time);

}

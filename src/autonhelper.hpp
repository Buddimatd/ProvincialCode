#include "config.hpp"
#include "main.h"

void drive_pid(int dist, int usr_speed){
  if (dist > 0) {
    driveleft_T.tare_position();
    driveleft_B.tare_position();
    driveright_B.tare_position();
    driveright_T.tare_position();

    double kp = .3;
    double kd = 0;
    double ki = 0;

    int prevError = 0;
    int error = 0;
    int integral = 0;
    int derivative = 0;
    int driveTarget = dist;
    while(1){
      pros::delay(20);

      int sp = driveTarget;

      //read sensors
      int ls = driveleft_B.get_position();
      int rs = driveright_B.get_position();
      int sv = (int)(ls + rs)/2;

      //speed
      error = sp-sv;
      integral = integral + error;
      derivative = error - prevError;
      prevError = error;
     int speed = error*kp + integral*ki + derivative*kd;

      pros::lcd::print(5, "Speed: %d ", speed );

      if(speed > usr_speed)
      speed = usr_speed;
      if(speed < -usr_speed)
      speed = -usr_speed;

      driveleft_T.move(speed);
      driveleft_B.move(speed);
      driveright_B.move(speed);
      driveright_T.move(speed);
      if (speed < 25){
        break;
      }
    }
  } else if (dist < 0){
      dist = -dist;

       driveleft_T.tare_position();
       driveleft_B.tare_position();
       driveright_B.tare_position();
       driveright_T.tare_position();

       double kp = .2;
       double kd = 0;
       double ki = 0;

       int prevError = 0;
       int error = 0;
       int integral = 0;
       int derivative = 0;
       int driveTarget = dist;
       while(1){
         pros::delay(20);

         int sp = driveTarget;


         //read sensors
         int ls = driveleft_T.get_position();
         int rs = driveright_T.get_position();
         int sv =  (int)(ls + rs)/2;

         //speed
          error = sp + sv;
          integral = integral + error;
          derivative = error - prevError;
         prevError = error;
         int speed = error*kp + integral*ki + derivative*kd;
         pros::lcd::print(2, "Speed: %d ", speed );
         //std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

         if(speed > usr_speed)
           speed = usr_speed;
         if(speed < -usr_speed)
           speed = -usr_speed;

          driveleft_T.move(-speed);
          driveleft_B.move(-speed);
          driveright_B.move(-speed);
          driveright_T.move(-speed);

          if (speed < 5){
            break;
          }
        }
      }
    }

 void rev_pid(int dist, int usr_speed){

   driveleft_T.tare_position();
   driveleft_B.tare_position();
   driveright_B.tare_position();
   driveright_T.tare_position();

   int prevError = 0;
   int driveTarget = dist;
   while(1){
     pros::delay(20);

     int sp = driveTarget;

     double kp = .3;
     double kd = .5;

     //read sensors
     int ls = driveleft_T.get_position();
     int rs = driveright_T.get_position();
     int sv = ls;

     //speed
     int error = sp + sv;
     int derivative = error - prevError;
     prevError = error;
     int speed = error*kp + derivative*kd;
     pros::lcd::print(2, "Speed: %d ", speed );
     //std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

     if(speed > usr_speed)
       speed = usr_speed;
     if(speed < -usr_speed)
       speed = -usr_speed;

      driveleft_T.move(-speed);
      driveleft_B.move(-speed);
      driveright_B.move(-speed);
      driveright_T.move(-speed);

      if (speed < 5){
        break;
      }
    }
 }


void turn(int deg){
  if (deg > 0){
    driveleft_T.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    driveright_T.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    driveleft_B.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    driveright_B.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    driveleft_T.move_velocity(50);
    driveright_T.move_velocity(-50);
    driveleft_B.move_velocity(50);
    driveright_B.move_velocity(-50);
    int target = deg;
    int margin = 5;
    while (imu_sensor.get_yaw() < target - margin){
      pros::delay(10);
    }
    driveleft_T.move_velocity(0);
    driveright_T.move_velocity(0);
    driveleft_B.move_velocity(0);
    driveright_B.move_velocity(0);
    pros::delay(500);
    driveleft_T.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    driveright_T.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    driveleft_B.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    driveright_B.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  } else if (deg < 0){
    driveleft_T.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    driveright_T.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    driveleft_B.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    driveright_B.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    driveleft_T.move_velocity(-50);
    driveright_T.move_velocity(50);
    driveleft_B.move_velocity(-50);
    driveright_B.move_velocity(50);
    int target = deg;
    int margin = 5;
    while (imu_sensor.get_yaw() > target + margin){
      pros::delay(10);
    }
    driveleft_T.move_velocity(0);
    driveright_T.move_velocity(0);
    driveleft_B.move_velocity(0);
    driveright_B.move_velocity(0);
    pros::delay(500);
    driveleft_T.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    driveright_T.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    driveleft_B.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    driveright_B.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  }
  imu_sensor.reset();
}

#include "main.h"


pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Motor driveleft_B(11, pros::E_MOTOR_GEARSET_18, false,
                        pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveright_B(19, pros::E_MOTOR_GEARSET_18, true,
                         pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveleft_T(5, pros::E_MOTOR_GEARSET_18, false,
                       pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveright_T(20, pros::E_MOTOR_GEARSET_18, true,
                         pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor intakeRight(7, pros::E_MOTOR_GEARSET_36, false,
                   pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor intakeLeft(13, pros::E_MOTOR_GEARSET_36, true,
                    pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor tray(16, pros::E_MOTOR_GEARSET_36, true,
                     pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor arm(2, pros::E_MOTOR_GEARSET_36, false,
                pros::E_MOTOR_ENCODER_COUNTS);
pros::Imu imu_sensor(9);
//pros::ADIUltrasonic sensor(7, 8);

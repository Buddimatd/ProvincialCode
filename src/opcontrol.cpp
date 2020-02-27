#include "main.h"
//#include "functions.hpp"
#include "okapi/api.hpp"
#include "config.hpp"
#include <sstream>
#include <stdio.h>

/**

 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

void opcontrol() {
	std::stringstream ss;
	std::string display;

	driveright_T.set_reversed(true);

	int power;
	int turn;
	int left;
	int right;
	int armpos = arm.get_position();
	int traypower;

	int armpower = 200;
	const double armult = 1;

	bool intakesystem = false;
	bool negIntake = false;
	bool slowmode = false;
	bool army = false;
	bool higharm = false;
	bool traycontrol = true;

	tray.tare_position();
	arm.tare_position();
	tray.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	arm.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);



	while(true){
		// Set up stringstream
		ss.str(std::string());

		// Movment codee
		pros::delay(2);
		power = master.get_analog(ANALOG_RIGHT_Y);
		turn = master.get_analog(ANALOG_RIGHT_X);
		traypower = master.get_analog(ANALOG_LEFT_Y);
		left = power + turn;
		right = power - turn;

		tray.move(-traypower);

		driveright_T.move(right);
		driveright_B.move(right);
		driveleft_T.move(left);
		driveleft_B.move(left);

		if (master.get_digital(DIGITAL_L2)){
			intakeRight.move(200);
			intakeLeft.move(200);
		} else if (master.get_digital(DIGITAL_R2)){
			intakeRight.move(-200);
			intakeLeft.move(-200);
		}
		else if (master.get_digital(DIGITAL_L1)){
			intakeRight.move(50);
			intakeLeft.move(50);
		} else if (master.get_digital(DIGITAL_R1)){
			intakeRight.move(-50);
			intakeLeft.move(-50);
		} else if (((master.get_digital(DIGITAL_R1)) && (master.get_digital(DIGITAL_R1)) && (master.get_digital(DIGITAL_R1)) && (master.get_digital(DIGITAL_R1))) == false ) {
			intakeRight.move(0);
			intakeLeft.move(0);
		}


		pros::lcd::print(1, "Yaw: %.2f", imu_sensor.get_yaw());
		pros::lcd::print(2, "Roll: %.2f", imu_sensor.get_roll());
		pros::lcd::print(3, "Pitch: %.2f", imu_sensor.get_pitch());

		int target = 90;
		int margin = 5;
		if (imu_sensor.get_yaw() > target - margin && imu_sensor.get_yaw() < target + margin){
			pros::lcd::print(4, "Target: Found");
		} else {
				pros::lcd::print(4, "Target: Lost");
		}

	}}
	// if (armpower){
	// 	float traypower = armpower * 1.2;
	// 	if (traypower > 127) traypower = 127;
	// 	if (traypower < -127) traypower = -127;
	// 	if ((tray.get_position() > 940)){
	// 			tray.move_absolute(930, 150);
	// 			traypower = 0;
	// 			pros::delay(200);
	// 		}
	// 		else{
	//
	// 			tray.move((int)traypower);
	// 		}
	// 		arm.move(armpower);


		// if(armpower > 0){
		// 	arm.move_velocity(0);
		// 	tray.move_velocity(0);
		// }



		//if tray.get_position()






		// Shows controller output to screen
		// pros::lcd::print(0, "X: %d Y: %d", turn, power);
		// //master.set_text(1, 0, "X: %d Y: %d", turn, power);
		// if (slowmode){
		// 	ss << "S";
		//
		// }else {
		// 	ss << "F";
		// }
		// if (intakesystem == true) {
		// 		pros::lcd::print(1, "Intake status: Active" );
		//
		// 	}
		// if (intakesystem == false){
		// 		pros::lcd::print(1, "Intake status: Inactive" );
		//
		// }
		// 	if (negIntake == true) {
		// 			pros::lcd::print(2, "Intake Negative Status: Negative" );
		// 			ss << "O";
		// 		}
		// 	if (negIntake == false){
		// 			pros::lcd::print(2, "Intake Negative Status: " );
		// 			ss << "I";
		// 		}
		// 		pros::lcd::print(3, "Gyrpo: %d", gyro.get_value());
		// 	//	master.set_text(2, 2, "G: %d", gyro.get_value());
		// 	display = ss.str();
		// 	master.set_text(2, 0,	display.c_str());
		// 	//std::cout << "Gyro: " << gyro.get_value() << std::endl;
		// }


		//master.set_text(0,0,"hey buddima");

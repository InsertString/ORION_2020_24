#include "main.h"

using namespace pros;

Controller master(E_CONTROLLER_MASTER);

// drive motors
Motor DriveLFF(1);
Motor DriveLFB(11);

Motor DriveLBF(3);
Motor DriveLBB(4);

Motor DriveRFF(6);
Motor DriveRFB(20);

Motor DriveRBF(9);
Motor DriveRBB(10);

// drive encoders
#define L_ENC_PORT1 1
#define L_ENC_PORT2 2
ADIEncoder LeftEncoder(L_ENC_PORT1, L_ENC_PORT2, true);
#define R_ENC_PORT1 7
#define R_ENC_PORT2 8
ADIEncoder RightEncoder(R_ENC_PORT1, R_ENC_PORT2, false);
#define B_ENC_PORT1 5
#define B_ENC_PORT2 6
ADIEncoder BackEncoder(B_ENC_PORT1, B_ENC_PORT2);

Imu gyro(12);

bool start_tracking = false;

void odom_task(void* param) {
	while (true) {
		CalculatePosition();
		//odomDebug();
	}
}

Task odom (odom_task, NULL, TASK_PRIORITY_DEFAULT-1, TASK_STACK_DEPTH_DEFAULT, "ODOM");

void initialize() {
	pros::lcd::initialize();
	gyro.reset();
}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {

	while (true) {
		//powerDrive(master.get_analog(ANALOG_LEFT_Y), master.get_analog(ANALOG_LEFT_X), master.get_analog(ANALOG_RIGHT_X));

		if (master.get_digital(DIGITAL_A)) {
			drive_to_point(10, 10, -180);
		}
		else if (master.get_digital(DIGITAL_B)) {
			drive_to_point(0, 0, 0);
		}
		else if (master.get_digital(DIGITAL_Y)) {
			drive_to_point(-10, -10, -90);
		}
		else {
			powerDrive(master.get_analog(ANALOG_LEFT_Y), master.get_analog(ANALOG_LEFT_X), master.get_analog(ANALOG_RIGHT_X));
		}

		delay(20);
	}
}

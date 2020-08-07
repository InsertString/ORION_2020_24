#include "main.h"
#include "odometry_stuff.cpp"

Controller master(E_CONTROLLER_MASTER);

// drive motors
Motor DriveLFF(1);
Motor DriveLFB(2);

Motor DriveLBF(3);
Motor DriveLBB(4);

Motor DriveRFF(5);
Motor DriveRFB(6);

Motor DriveRBF(7);
Motor DriveRBB(8);

// drive encoders
#define L_ENC_PORT1 1
#define L_ENC_PORT2 2
ADIEncoder LeftEncoder(L_ENC_PORT1, L_ENC_PORT2, true);
#define R_ENC_PORT1 1
#define R_ENC_PORT2 2
ADIEncoder RightEncoder(R_ENC_PORT1, R_ENC_PORT2, true);
#define B_ENC_PORT1 1
#define B_ENC_PORT2 2
ADIEncoder BackEncoder(B_ENC_PORT1, B_ENC_PORT2);

void initialize() {

}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {

	while (true) {

		pros::delay(20);
	}
}

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

void initialize() {
	pros::lcd::initialize();
	gyro.reset();
	delay(100);
}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {
	GlobalPosition.x = 0;
	GlobalPosition.y = 0;

	int pow = 0;
	int turn = 0;
	int side = 0;

	while (true) {

		pow = -master.get_analog(ANALOG_LEFT_Y);
		side = -master.get_analog(ANALOG_LEFT_X);
		turn = master.get_analog(ANALOG_RIGHT_X);

		DriveLFF = -pow - turn + side;
		DriveLFB = pow + turn - side;
		DriveLBF = -pow - turn - side;
		DriveLBB = pow + turn + side;

		DriveRFF = pow - turn + side;
		DriveRFB = -pow + turn - side;
		DriveRBF = pow - turn - side;
		DriveRBB = -pow + turn + side;
//*/
		CalculatePosition();
		//pros::delay(10);

		lcd::print(0, "[%4.0f], [%4.0f], [%4.0f] ", DistCM(0), DistCM(1), DistCM(2));
		lcd::print(1, "x:[%3.0f], y:[%3.0f]", GlobalPosition.x, GlobalPosition.y);
		lcd::print(2, "x:[%3.0f], y:[%3.0f]", localOffset.x, localOffset.y);
		lcd::print(3, "gA:[%4.0f], dA:[%4.0f]", global_angle * 180 / 3.1415, delta_angle);


		std::cout << std::setw(5) << floor(GlobalPosition.x) << std::setw(5) << floor(GlobalPosition.y) << std::setw(5) << floor(global_angle * 180 / 3.1415) << std::endl;



		if (master.get_digital(DIGITAL_B)) {
			LeftEncoder.reset();
			RightEncoder.reset();
			BackEncoder.reset();
		}
	}
}

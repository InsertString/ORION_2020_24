
#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_

#define PROS_USE_SIMPLE_NAMES

#define PROS_USE_LITERALS

#include "api.h"
#include "math.h"


using namespace pros;

#ifdef __cplusplus
extern "C" {
#endif
void autonomous(void);
void initialize(void);
void disabled(void);
void competition_initialize(void);
void opcontrol(void);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
/**
 * You can add C++-only headers here
 */
//#include <iostream>
#include "vector_class.hpp"
#include "odometry_stuff.hpp"
#endif

extern Controller master;
extern Motor DriveLFF;
extern Motor DriveLFB;
extern Motor DriveLBF;
extern Motor DriveLBB;
extern Motor DriveRFF;
extern Motor DriveRFB;
extern Motor DriveRBF;
extern Motor DriveRBB;
extern ADIEncoder LeftEncoder;
extern ADIEncoder RightEncoder;
extern ADIEncoder BackEncoder;
extern Imu gyro;

extern CVector GlobalPosition;
extern CVector pastGlobalPosition;
extern CVector localOffset;
extern CVector globalOffset;

#endif  // _PROS_MAIN_H_

#include "main.h"
#include "odometry_stuff.hpp"
#include "vector_class.cpp"

using namespace std;

// wheels are 200mm circumfrance
double DistCM(int a) {
  if (a == 0) return LeftEncoder.get_value() * 45;
  else if (a == 1) return RightEncoder.get_value() * 45;
  else return BackEncoder.get_value() * 45;
}

double sideL = 15;
double sideR = 15;
double sideB = 15;

CVector pastGlobalPosition;
CVector GlobalPosition;
CVector localOffset;
CVector globalOffset;

double delta_enc[3] = {0,0,0};
double past_enc[3] = {0,0,0};

double past_angle = 0;
double new_angle = 0;
double average_angle = 0;
double delta_angle = 0;
double past_global_angle = 0;
double global_angle = 0;

#define LEFT 0
#define RIGHT 1
#define BACK 2

void CalculatePosition() {

  // delay for values of encoders to change
  pros::delay(10);

  // calulate change in encoder values
  for (int i = 0; i < 3; i++) {
    delta_enc[i] = DistCM(i) - past_enc[i];
  }

  // calculate change in angle
  new_angle = past_angle + ((delta_enc[LEFT] - delta_enc[RIGHT]) / (sideL + sideR));

  delta_angle = new_angle - past_angle;

  // calculate localOffset
  if (delta_angle == 0) {
    localOffset.x = delta_enc[BACK];
    localOffset.y = delta_enc[RIGHT];
  }
  else {
    localOffset.x = (delta_enc[BACK] / delta_angle) + sideB;
    localOffset.y = (delta_enc[RIGHT] / delta_angle) + sideR;
    localOffset * (2 * sin((delta_angle / 2)));
  }

  // calculate global offset based on local offset
  average_angle = past_global_angle + (delta_angle / 2);

  double polar_rad;
  double polar_angle;
  polar_rad = localOffset.getLength();
  polar_angle = -average_angle;

  globalOffset.x = (acos(polar_angle) * polar_rad);
  globalOffset.y = (asin(polar_angle) * polar_rad);

  // calculate global position
  GlobalPosition = pastGlobalPosition + globalOffset;

  // setup for next reset
  past_global_angle = GlobalPosition.getAngle();
  past_angle = new_angle;
  for (int i = 0; i < 3; i++) {
    past_enc[i] = DistCM(i);
  }
  pastGlobalPosition = GlobalPosition;
}

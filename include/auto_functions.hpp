#ifndef _AUTO_FUNCTIONS_HPP_
#define _AUTO_FUNCTIONS_HPP_

#include "vector_class.hpp"

void auto_drive_to_point(double y_targ, double x_targ, double theta_targ, int &step);

#define CLOCK 0
#define COUNTER 1

void auto_drive_circle(double rad, double time, double end_theta, CVector center, int direction, int &step);

#endif

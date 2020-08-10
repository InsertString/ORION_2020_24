#ifndef _AUTO_FUNCTIONS_HPP_
#define _AUTO_FUNCTIONS_HPP_


double starting_y = 0;
double starting_x = 0;
double starting_theta = 0;


void auto_drive_to_point(double y_targ, double x_targ, double theta_targ, int &step);

void auto_drive_circle(double rad, double time, int &step);

#endif

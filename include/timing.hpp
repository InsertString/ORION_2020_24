#ifndef _TIMING_HPP_
#define _TIMING_HPP_


#define AUTO_TIMER 0
#define AUTO_STEP_TIMER 1

#define DRIVE_TEST 2


void startTimer(int slot);
int getTime(int slot);

#endif

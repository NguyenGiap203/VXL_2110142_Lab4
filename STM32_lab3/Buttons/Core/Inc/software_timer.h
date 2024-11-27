/*
 * software_timer.h
 *
 *  Created on: Nov 11, 2024
 *      Author: NGUYEN GIAP
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#define TIMER_TICK 10 // chu ky cua ngat timer

void setTimer(int index, int value);
int isTimerExpired(int index);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */

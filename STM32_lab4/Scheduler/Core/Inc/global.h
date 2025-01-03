/*
 * global.h
 *
 *  Created on: Nov 11, 2024
 *      Author: NGUYEN GIAP
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "main.h"

#define INIT		1
#define RED_GREEN	2
#define RED_YELLOW 	3
#define GREEN_RED	4
#define YELLOW_RED	5

#define NORMAL		10
#define SET_RED		11
#define SET_YELLOW	12
#define SET_GREEN	13
#define CHECK_VALID 14

extern int status;

extern const int redCountInit;
extern const int yellowCountInit;
extern const int greenCountInit;

extern int redCount;
extern int yellowCount;
extern int greenCount;

extern const int changToSecond;
extern int redTime;
extern int yellowTime;
extern int greenTime;

void changeCountToSecond();

extern int timeCounter1;
extern int timeCounter2;

//#define TIMER_TICK 	10

#endif /* INC_GLOBAL_H_ */

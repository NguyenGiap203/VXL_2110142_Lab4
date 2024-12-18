/*
 * fsm_automatic.c
 *
 *  Created on: Nov 11, 2024
 *      Author: NGUYEN GIAP
 */

#include "fsm_automatic.h"
#include "global.h"
#include "main.h"
#include "led7_segment.h"

void fsm_automatic(){
	switch(status){
	case INIT:
		clearAllLeds();

		status = RED_GREEN;
		setTimer(1, redTime);
		setTimer(2, greenTime);
		setTimer(3, 10);
		setTimer(4, 10);
		timeCounter1 = redCount;
		timeCounter2 = greenCount;
		index_led = 0;
		break;
	case RED_GREEN:
		setRed1();
		setGreen2();
		led7_segment();

		if(isButtonPressed(0) == 1){
			status = NORMAL;
		}
		if(isButtonPressed(1)); // do nothing
		if(isButtonPressed(2)); // do nothing

		// check timer expired to do something
		if(isTimerExpired(2) == 1){
			status = RED_YELLOW;
			setTimer(2, yellowTime);
			timeCounter2 = yellowCount;
		}
		if(isTimerExpired(3) == 1){
			setTimer(3, 1000);
			timeCounter1--;
			timeCounter2--;
			updateClockBuffer(timeCounter2, timeCounter1);
		}
		break;
	case RED_YELLOW:
		setRed1();
		setYellow2();
		led7_segment();

		if(isButtonPressed(0) == 1){
			status = NORMAL;
		}
		if(isButtonPressed(1)); // do nothing
		if(isButtonPressed(2)); // do nothing

		// check timer expired to do something
		if(isTimerExpired(1) == 1 && isTimerExpired(2) == 1){
			status = GREEN_RED;
			setTimer(1, greenTime);
			setTimer(2, redTime);
			timeCounter1 = greenCount;
			timeCounter2 = redCount;
		}
		if(isTimerExpired(3) == 1){
			setTimer(3, 1000);
			timeCounter1--;
			timeCounter2--;
			updateClockBuffer(timeCounter2, timeCounter1);
		}
		break;
	case GREEN_RED:
		setGreen1();
		setRed2();
		led7_segment();

		// check if any button is pressed
		if(isButtonPressed(0) == 1){
			status = NORMAL;
		}
		if(isButtonPressed(1)); // do nothing
		if(isButtonPressed(2)); // do nothing

		// check timer expired to do something
		if(isTimerExpired(1) == 1){
			status = YELLOW_RED;
			setTimer(1, yellowTime);
			timeCounter1 = yellowCount;
		}
		if(isTimerExpired(3) == 1){
			setTimer(3, 1000);
			timeCounter1--;
			timeCounter2--;
			updateClockBuffer(timeCounter2, timeCounter1);
		}
		break;
	case YELLOW_RED:
		setYellow1();
		setRed2();
		led7_segment();

		// check if any button is pressed
		if(isButtonPressed(0) == 1){
			status = NORMAL;
		}
		if(isButtonPressed(1)); // do nothing
		if(isButtonPressed(2)); // do nothing

		// check timer expired to do something
		if(isTimerExpired(1) == 1 && isTimerExpired(2) == 1){
			status = RED_GREEN;
			setTimer(1, redTime);
			setTimer(2, greenTime);
			timeCounter1 = redCount;
			timeCounter2 = greenCount;
		}
		if(isTimerExpired(3) == 1){
			setTimer(3, 1000);
			timeCounter1--;
			timeCounter2--;
			updateClockBuffer(timeCounter2, timeCounter1);
		}
		break;
	default:
		break;
	}
}

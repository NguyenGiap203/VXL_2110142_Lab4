/*
 * fsm_setting.c
 *
 *  Created on: Nov 11, 2024
 *      Author: NGUYEN GIAP
 */

#include "fsm_setting.h"
#include "global.h"
#include "traffic_light.h"
#include "software_timer.h"
#include "led7_segment.h"
#include "main.h"

int tmp_redCount = 1;
int tmp_yellowCount = 1;
int tmp_greenCount = 1;

int ledBlinky = 500; // 500ms

void fsm_setting(){
	switch(status){
	case NORMAL:
		clearAllLeds();
		index_led = 0; // display from led 0 to 3
		setTimer(0, 10); // use for led blink
		setTimer(4, 10);

		if(isButtonPressed(0) == 1){
			status = SET_RED;
			setRed1();
			setRed2();
		}
		if(isButtonPressed(1)); //do nothing
		if(isButtonPressed(2) == 1){
			redCount = redCountInit;
			yellowCount = yellowCountInit;
			greenCount = greenCountInit;
			changeCountToSecond();

			status = INIT;
		}
		break;
	case SET_RED:
		updateClockBuffer(1, tmp_redCount);
		led7_segment();

		if(isTimerExpired(0) == 1){
			setTimer(0, ledBlinky);
			toggleRed1();
			toggleRed2();
		}

		if(isButtonPressed(0) == 1){
			status = SET_YELLOW;
			setYellow1();
			setYellow2();
		}
		if(isButtonPressed(1) == 1){
			tmp_redCount++;
			while (tmp_redCount < 1) tmp_redCount += 99;
			while (tmp_redCount > 99) tmp_redCount -= 99;
		}
		if(isButtonPressed(2) == 1){
			status = CHECK_VALID;
		}

		break;
	case SET_YELLOW:
		updateClockBuffer(2, tmp_yellowCount);
		led7_segment();

		if(isTimerExpired(0) == 1){
			setTimer(0, ledBlinky);
			toggleYellow1();
			toggleYellow2();
		}

		if(isButtonPressed(0) == 1){
			status = SET_GREEN;
			setGreen1();
			setGreen2();
		}
		if(isButtonPressed(1) == 1){
			tmp_yellowCount++;
			while (tmp_yellowCount < 1) tmp_yellowCount += 99;
			while (tmp_yellowCount > 99) tmp_yellowCount -= 99;
		}
		if(isButtonPressed(2) == 1){
			status = CHECK_VALID;
		}
		break;
	case SET_GREEN:
		updateClockBuffer(3, tmp_greenCount);
		led7_segment();

		if(isTimerExpired(0) == 1){
			setTimer(0, ledBlinky);
			toggleGreen1();
			toggleGreen2();
		}
		if(isButtonPressed(0) == 1){
			status = NORMAL;
		}
		if(isButtonPressed(1) == 1){
			tmp_greenCount++;
			while (tmp_greenCount < 1) tmp_greenCount += 99;
			while (tmp_greenCount > 99) tmp_greenCount -= 99;
		}
		if(isButtonPressed(2) == 1){
			status = CHECK_VALID;
		}
		break;
	case CHECK_VALID:
		if (tmp_redCount == tmp_yellowCount + tmp_greenCount){
			redCount = tmp_redCount;
			yellowCount = tmp_yellowCount;
			greenCount = tmp_greenCount;
			changeCountToSecond();
		}
		tmp_redCount = 1;
		tmp_yellowCount = 1;
		tmp_greenCount = 1;
		status = INIT;
		break;
	default:
		break;
	}
}

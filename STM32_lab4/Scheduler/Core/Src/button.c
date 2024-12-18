/*
 * button.c
 *
 *  Created on: Nov 11, 2024
 *      Author: NGUYEN GIAP
 */

#include "button.h"
#include "main.h"
#include "software_timer.h" // to use TIMER_TICK

#define NO_OF_BUTTONS	3
//timer interrupt duration is TIMER_TICK
#define DURATION_FOR_AUTO_INCREASING	250/TIMER_TICK //1000ms

#define PRESSED_STATE	GPIO_PIN_RESET
#define RELEASED_STATE	GPIO_PIN_SET

// the buffer that the final result is stored after debouncing
static GPIO_PinState buttonBuffer[NO_OF_BUTTONS];
// we define three buffers for debouncing
static GPIO_PinState debounceBuffer1[NO_OF_BUTTONS];
static GPIO_PinState debounceBuffer2[NO_OF_BUTTONS];
static GPIO_PinState debounceBuffer3[NO_OF_BUTTONS];

static GPIO_TypeDef* ButtonPorts[NO_OF_BUTTONS] = {BUT1_GPIO_Port, BUT2_GPIO_Port, BUT3_GPIO_Port};
static uint16_t ButtonPins[NO_OF_BUTTONS] = {BUT1_Pin, BUT2_Pin, BUT3_Pin};

uint8_t button_flag[NO_OF_BUTTONS] = {0};

int counterAutoIncresing[NO_OF_BUTTONS] = {0};

int isButtonPressed(int index){
	if(button_flag[index] == 1){
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}

void getKeyInput(){
	for(int i = 0; i < NO_OF_BUTTONS; i++){
		debounceBuffer1[i] = debounceBuffer2[i];
		debounceBuffer2[i] = debounceBuffer3[i];
		debounceBuffer3[i] = HAL_GPIO_ReadPin(ButtonPorts[i], ButtonPins[i]);

		if((debounceBuffer1[i] == debounceBuffer2[i]) && (debounceBuffer2[i] == debounceBuffer3[i])){
			if(buttonBuffer[i] != debounceBuffer3[i]){
				buttonBuffer[i] = debounceBuffer3[i];
				if(buttonBuffer[i] == PRESSED_STATE){
					button_flag[i] = 1;
					counterAutoIncresing[i] = 0;
				}
			} else {
				counterAutoIncresing[i]++;
				if(counterAutoIncresing[i] >= DURATION_FOR_AUTO_INCREASING){
					buttonBuffer[i] = RELEASED_STATE;
					counterAutoIncresing[i] = 0;
				}
			}
		}
	}
}

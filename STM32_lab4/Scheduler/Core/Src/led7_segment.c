/*
 * led7_segment.c
 *
 *  Created on: Nov 11, 2024
 *      Author: NGUYEN GIAP
 */

#include "led7_segment.h"
#include "main.h"
#include "software_timer.h"

const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {0};

void updateClockBuffer(int value1, int value2){
	led_buffer[0] = value1 / 10;
	led_buffer[1] = value1 % 10;
	led_buffer[2] = value2 / 10;
	led_buffer[3] = value2 % 10;
}

void update7SEG(int index_led){
	switch(index_led){
	case 0:
		HAL_GPIO_WritePin(GPIOA, EN0_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, EN1_Pin|EN2_Pin|EN3_Pin, SET);
		display7SEG(led_buffer[0]);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOA, EN1_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN2_Pin|EN3_Pin, SET);
		display7SEG(led_buffer[1]);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOA, EN2_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN1_Pin|EN3_Pin, SET);
		display7SEG(led_buffer[2]);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOA, EN3_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN1_Pin|EN2_Pin, SET);
		display7SEG(led_buffer[3]);
		break;
	default:
		break;
	}
}

void display7SEG(int num){
	// Turn off all SEG
	HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin | SEG3_Pin |SEG4_Pin | SEG5_Pin | SEG6_Pin, SET);
	switch(num){
	case 0:
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin | SEG3_Pin |SEG4_Pin | SEG5_Pin, RESET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOB, SEG1_Pin | SEG2_Pin, RESET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG3_Pin |SEG4_Pin |SEG6_Pin, RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin | SEG3_Pin |SEG6_Pin, RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOB, SEG1_Pin | SEG2_Pin | SEG5_Pin |SEG6_Pin, RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG2_Pin | SEG3_Pin | SEG5_Pin |SEG6_Pin, RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG2_Pin | SEG3_Pin |SEG4_Pin | SEG5_Pin |SEG6_Pin, RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin, RESET);
		break;
	case 8:
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin | SEG3_Pin |SEG4_Pin | SEG5_Pin |SEG6_Pin, RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin | SEG3_Pin | SEG5_Pin |SEG6_Pin, RESET);
		break;
	default:
		// Present a hyphen "-" if counter < 0 or counter > 9
		HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
		break;
	}
}

void led7_segment(){
	if(isTimerExpired(4) == 1){
		setTimer(4, 250);
		update7SEG(index_led);
		index_led = (index_led + 1) % MAX_LED;
	}
}

/*
 * traffic_light.c
 *
 *  Created on: Nov 11, 2024
 *      Author: NGUYEN GIAP
 */

#include "traffic_light.h"

void setRed1(){
	HAL_GPIO_WritePin(GPIOB, RED1_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, YEL1_Pin|GRE1_Pin, RESET);
}
void setYellow1(){
	HAL_GPIO_WritePin(GPIOB, YEL1_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, RED1_Pin|GRE1_Pin, RESET);
}
void setGreen1(){
	HAL_GPIO_WritePin(GPIOB, GRE1_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, RED1_Pin|YEL1_Pin, RESET);
}



void setRed2(){
	HAL_GPIO_WritePin(GPIOB, RED2_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, YEL2_Pin|GRE2_Pin, RESET);
}
void setYellow2(){
	HAL_GPIO_WritePin(GPIOB, YEL2_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, RED2_Pin|GRE2_Pin, RESET);
}
void setGreen2(){
	HAL_GPIO_WritePin(GPIOB, GRE2_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, RED2_Pin|YEL2_Pin, RESET);
}



void toggleRed1(){
	HAL_GPIO_TogglePin(RED1_GPIO_Port, RED1_Pin);
}
void toggleYellow1(){
	HAL_GPIO_TogglePin(YEL1_GPIO_Port, YEL1_Pin);
}
void toggleGreen1(){
	HAL_GPIO_TogglePin(GRE1_GPIO_Port, GRE1_Pin);
}



void toggleRed2(){
	HAL_GPIO_TogglePin(RED2_GPIO_Port, RED2_Pin);
}
void toggleYellow2(){
	HAL_GPIO_TogglePin(YEL2_GPIO_Port, YEL2_Pin);
}
void toggleGreen2(){
	HAL_GPIO_TogglePin(GRE2_GPIO_Port, GRE2_Pin);
}



void clearAllLeds(){
	HAL_GPIO_WritePin(GPIOB, RED1_Pin|YEL1_Pin|GRE1_Pin|RED2_Pin|YEL2_Pin|GRE2_Pin, RESET);
}

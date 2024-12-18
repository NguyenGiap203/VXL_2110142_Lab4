/*
 * global.c
 *
 *  Created on: Nov 11, 2024
 *      Author: NGUYEN GIAP
 */

#include "global.h"
int status = 0;

const int redCountInit = 5;
const int yellowCountInit = 2;
const int greenCountInit = 3;

int redCount = redCountInit;
int yellowCount = yellowCountInit;
int greenCount = greenCountInit;


const int changeToSecond = 1000;
int redTime = 5000;
int yellowTime = 2000;
int greenTime = 3000;

void changeCountToSecond(){
	redTime = redCount * changeToSecond;
	yellowTime = yellowCount * changeToSecond;
	greenTime = greenCount * changeToSecond;
}

int timeCounter1 = redCountInit;
int timeCounter2 = greenCountInit;

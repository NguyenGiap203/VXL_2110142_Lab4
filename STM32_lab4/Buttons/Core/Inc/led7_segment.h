/*
 * led7_segment.h
 *
 *  Created on: Nov 11, 2024
 *      Author: NGUYEN GIAP
 */

#ifndef INC_LED7_SEGMENT_H_
#define INC_LED7_SEGMENT_H_

extern int index_led;

void updateClockBuffer(int value1, int value2);

void display7SEG(int num);
void led7_segment();

#endif /* INC_LED7_SEGMENT_H_ */

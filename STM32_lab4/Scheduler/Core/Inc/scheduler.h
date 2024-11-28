/*
 * scheduler.h
 *
 *  Created on: Nov 28, 2024
 *      Author: NGUYEN GIAP
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>

typedef struct{
	void (*pTask)(void);
	uint32_t 	Delay;
	uint32_t	Period;
	uint8_t		RunMe;

	uint32_t 	TaskID;
}sTasks;

#define SCH_MAX_TASKS 	40

void SCH_Init(void); // Khoi tao

void SCH_Add_Task(void(*pFunction),
					uint32_t DELAY,
					uint32_t PERIOD);

void SCH_Update(void); // giong timerRun

void SCH_Dispatch_Tasks(void); // giong isTimerExpired

void SCH_Delete(uint32_t ID);

#endif /* INC_SCHEDULER_H_ */

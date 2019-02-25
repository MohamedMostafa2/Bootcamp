/*H**********************************************************************
* FILENAME :Tasks.h
*
* DESCRIPTION :
*       

* PUBLIC FUNCTIONS : None
*
* NOTES :
*
*
* AUTHOR :    Mohamed AbdelKarim        START DATE :    19 Feb 19
*
* CHANGES : None
*
*
*H*/
#ifndef __TASKS_H__
#define __TASKS_H__

#include "../../../OS/Includes/Scheduler_H/Scheduler_cfg.h"
#include "../../../Includes/DataTypes.h"

#define TASKS_MAX_NUMBER ((uint8)5)

typedef enum{
	Task0_Index = 0,
	Task1_Index = 1,
	Task2_Index = 2,
}TasksIndexs_e;


	
typedef struct {
	TaskType Task_ptr;
	uint16 TaskPeriodicity;
	uint16 RemainingTicks;
	uint8 TaskPriority;
	uint8 TaskState; 	
	}Task_s;

	

extern Task_s TasksQueue[TASKS_MAX_NUMBER];

void Task0 ( void );

void Task1 ( void );

void Task2 ( void );

#endif

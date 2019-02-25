/*H**********************************************************************
* FILENAME :Schedular.h
*
* DESCRIPTION :
*       Scheduler 

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

#ifndef __SCHEDULAR_H__
#define __SCHEDULAR_H__

#include "../../../Includes/DataTypes.h"
#include "../../../APP/Includes/Tasks_H/Tasks.h"
#include "Scheduler_cfg.h"


#define NULL ((uint8)0)
#define ZERO ((uint8)0)
#define ONE ((uint8)1)

#define FALSE ((uint8)0)
#define TRUE  ((uint8)1)



extern uint8 FunctionFlag;
extern volatile TaskType Callback;

/************************************************************************
* Function Name : SchedulerAddTask
*
* Parameter
*			I/P : Task_ptr , TaskPeriodicity
*			O/P : None
*			I/O : None
*
* Return : None
*
* Description : Add Tasks To Scheduler
*
************************************************************************/
uint8 SchedulerAddTask(TaskType Task_ptr , uint16 TaskPeriodicity ,uint8 TaskPriority);


/************************************************************************
* Function Name : SchedulerInit
*
* Parameter
*			I/P : None
*			O/P : None
*			I/O : None
*
* Return : None
*
* Description : Initialize Scheduler
*               1- Initialize Timer0
*               2- Enable Timer0 Interrupt
*               3- SetCallback
*
************************************************************************/
extern void SchedulerInit(void);


/************************************************************************
* Function Name : SchedulerStart
*
* Parameter
*			I/P : None
*			O/P : None
*			I/O : None
*
* Return : None
*
* Description : Start Scheduler
*               1- Start Timer0
*               2- Call Dispatcher
*               3- Remove Task
*
************************************************************************/
extern void SchedulerStart(void);






#endif

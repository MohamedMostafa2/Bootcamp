/*H**********************************************************************
* FILENAME :Tasks.c
*
* DESCRIPTION :
*       Tasks Which handled by Scheduler
*
* PUBLIC FUNCTIONS :
*
* NOTES :
*       
*
*
* AUTHOR :    Mohamed AbdelKarim        START DATE :    19 Feb 19
*
* CHANGES : None
*
*
*H*/

#include "../../OS/Includes/Scheduler_H/Scheduler_cfg.h"
#include "../../OS/Includes/Scheduler_H/Scheduler.h"
#include "../Includes/Tasks_H/Tasks.h"
#include "../../ECUAL/Includes/LEDS_H/LEDS.h"

#include "../../Includes/BitwiseOperations.h"

Task_s TasksQueue[TASKS_MAX_NUMBER]; 





void Task0 (void)
{
	
  TurnLED(Led0,Led_Toggle);
 
	
}

void Task1 (void)
{
	TurnLED(Led1,Led_Toggle);
}

void Task2 (void)
{
	TurnLED(Led2,Led_Toggle);

}
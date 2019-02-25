/*
 * TTC_Scheduler.c
 *
 * Created: 2/24/2019 4:31:24 PM
 * Author : AVE-LAP-049
 */ 

#include "OS/Includes/Scheduler_H/Scheduler.h"
#include "APP/Includes/Tasks_H/Tasks.h"
#include "ECUAL/Includes/LEDS_H/LEDS.h"
#include "MCAL/Includes/DIO_H/DIO.h"

int main(void)
{

	/* Set Leds Pins to Output */
	DIO_SetPinDirection(Pin10,INPUT);
	DIO_SetPinDirection(Pin12,OUTPUT);
    DIO_SetPinDirection(Pin13,OUTPUT);
    DIO_SetPinDirection(Pin14,OUTPUT);
	DIO_SetPinDirection(Pin15,OUTPUT);

	
    SchedulerInit(); /* Initialize Scheduler */
	
	SchedulerAddTask(Task0,300,3); /* Add Task0 */
    SchedulerAddTask(Task1,300,7); /* Add Task1 */
    SchedulerAddTask(Task2,300,1);  /* Add Task2 */
	
	SchedulerStart(); /* Start Scheduler */
	

}


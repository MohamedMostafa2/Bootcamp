/*H**********************************************************************
* FILENAME :Schedular.c
*
* DESCRIPTION :
*       Scheduler Which Handle Tasks
*
* PUBLIC FUNCTIONS :
*             void SchedulerInit(void)
*             void SchedulerStart(void)
*             uint8 SchedulerAddTask(TaskType Task_ptr , uint16 TaskPeriodicity)
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

#include "../../MCAL/Includes/Timer_H/Timer.h"
#include "../Includes/Scheduler_H/Scheduler_cfg.h"
#include "../Includes/Scheduler_H/Scheduler.h"
#include "../../APP/Includes/Tasks_H/Tasks.h"
#include "../../ECUAL/Includes/Buttoms_H/Buttoms.h"


static void SortTaskArray(void);
static void SchedulerRemoveTask( void(*PtrToFunc)(void));
static void SetFlag(void);
static void Dispatcher( Task_s Tasks_arr[]);
static void SetCallback( void(*Callback_ptr)(void));


volatile uint8 Callback_Flag = INTIAL_VALUE ;
volatile TaskType Callback   = NULL;
volatile uint8 TasksAddedCounter = INTIAL_VALUE;


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
void SchedulerInit(void){
	
	timer0_init(TimerCTC_Mode,TimerPrescaler_64,OCR_VALUE); /* Timer Initialization */
	EnableTimer0Interrupt(); /* Enable Timer0 Interrupt */
	SetCallback(SetFlag); /* SetCallback */
}


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
void SchedulerStart(void){
	
	StartTimer0(); /* Start Timer0 */
	
	while (TRUE){
		
		if (TRUE == Callback_Flag) /* Check if Callback_Flag == TRUE */
		{
			Callback_Flag = FALSE ; /* Set Callback_Flag to False */
			Dispatcher(TasksQueue); /* Call Dispatcher function that call Tasks with Right Periodicity */
		}
		if(ReadButtom(Button1) == ButtonPressed) /* Check if Button Pressed or Not */
		{
			SchedulerRemoveTask(Task0); /* Call Function to Remove Taske */
		}
	}
	
}


/************************************************************************
* Function Name : Dispatcher
*
* Parameter
*			I/P : None
*			O/P : Tasks_arr[]
*			I/O : None
*
* Return : None
*
* Description : Call Tasks in Tasks_arr
*
************************************************************************/
static void Dispatcher( Task_s Tasks_arr[]){ 
	
	uint8 TaskIndex;
	for (TaskIndex = FIRST_TASK_INDEX ; TaskIndex < TasksAddedCounter ;TaskIndex++)
	{
		/* Check if Task State is Blocked or Not and Remaining Ticks not equal Zero*/
		if ( (TaskReady == Tasks_arr[TaskIndex].TaskState) && (ZERO == Tasks_arr[TaskIndex].RemainingTicks) )
		{
			Tasks_arr[TaskIndex].Task_ptr(); /* Call Task Function */
			Tasks_arr[TaskIndex].RemainingTicks = Tasks_arr[TaskIndex].TaskPeriodicity; /* Reset Remaining Ticks */
		}
		else
		{
			Tasks_arr[TaskIndex].RemainingTicks--; /* Every Time Remaining Ticks is decreased by 1 until reach Zero */
		}
		
	}
		
}


/************************************************************************
* Function Name : SetCallback
*
* Parameter
*			I/P : Callback_ptr
*			O/P : None
*			I/O : None
*
* Return : None
*
* Description : Set Callback
*
************************************************************************/
static void SetCallback( void(*Callback_ptr)(void)){
	
	Callback = Callback_ptr ; 
}


/************************************************************************
* Function Name : SetFlag
*
* Parameter
*			I/P : None
*			O/P : None
*			I/O : None
*
* Return : None
*
* Description : Set Flag
*
************************************************************************/
static void SetFlag(void){
	Callback_Flag = TRUE ;	
}


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
uint8 SchedulerAddTask(TaskType Task_ptr , uint16 TaskPeriodicity , uint8 TaskPriority){
	 uint8 AddTaskState; 
	if(TasksAddedCounter < TASKS_MAX_NUMBER )
	{
		TasksQueue[TasksAddedCounter].Task_ptr        = Task_ptr; /* pointer to task function */
		TasksQueue[TasksAddedCounter].TaskPeriodicity = TaskPeriodicity; /* Task Periodicity */
		TasksQueue[TasksAddedCounter].RemainingTicks  = TaskPeriodicity; /* RemainigTicks */
		TasksQueue[TasksAddedCounter].TaskPriority    = TaskPriority; /* Task Priority */
		TasksQueue[TasksAddedCounter].TaskState       = TaskReady; /* Task Priority */
		
		AddTaskState  = TRUE ;
	}
	else
	{
		AddTaskState  = FALSE ;
	}
	
	TasksAddedCounter++;
	
	SortTaskArray(); /* Sort Array Using Priorities*/
	
	return AddTaskState;
}


/************************************************************************
* Function Name : SortTaskArray
*
* Parameter
*			I/P : None
*			O/P : None
*			I/O : None
*
* Return : None
*
* Description : Sort Task Array With Priorities
*
************************************************************************/
static void SortTaskArray(void){
	uint8 LoopsNumber;
	uint8 ArrayIndex;
	Task_s Struct_Temp;
	
	/* Bubble Sort Algorithm*/
	for (LoopsNumber = TasksAddedCounter - ONE ; LoopsNumber > ZERO ; LoopsNumber-- )
	{
		for (ArrayIndex = ZERO ; ArrayIndex < LoopsNumber  ; ArrayIndex++ )
		{
		   if (TasksQueue[ArrayIndex].TaskPriority > TasksQueue[ArrayIndex + ONE].TaskPriority)
		   {
			   Struct_Temp                  = TasksQueue[ArrayIndex];        /***********************/
			   TasksQueue[ArrayIndex]       = TasksQueue[ArrayIndex + ONE];  /* Swap Array Elements */  
			   TasksQueue[ArrayIndex + ONE] = Struct_Temp;                   /***********************/

		   }
		   	
		}
		
	}
	
	
	
}


/************************************************************************
* Function Name : Scheduler Remove Task
*
* Parameter
*			I/P : PtrToFunc
*			O/P : None
*			I/O : None
*
* Return : None
*
* Description : Remove Task and Sort Array
*
************************************************************************/
static void SchedulerRemoveTask( void(*PtrToFunc)(void)){
	uint8 BlockTaskIndex;
	uint8 LoopsNumber;
	uint8 SortTaskIndex;
	Task_s Struct_Temp;
	
	for(BlockTaskIndex = ZERO ; BlockTaskIndex < TasksAddedCounter ; BlockTaskIndex++)
	{
		if ( PtrToFunc == TasksQueue[BlockTaskIndex].Task_ptr ) /*********************************/
		{													    /* Search For Task Which Chosen  */
			TasksQueue[BlockTaskIndex].TaskState = TaskBloced;  /* To be Remove                  */
			TasksAddedCounter--;                                /*********************************/
			/* Decrease Added Tasks Counter */                                
		}
	}
	
	
	/* Bubble Sort Algorithm*/
	for (LoopsNumber = TasksAddedCounter ; LoopsNumber > ZERO ; LoopsNumber-- )
	{
		for (SortTaskIndex = ZERO ; SortTaskIndex < LoopsNumber  ; SortTaskIndex++ )
		{
			if (TasksQueue[SortTaskIndex].TaskState > TasksQueue[SortTaskIndex + ONE].TaskState)
			{
				Struct_Temp                  = TasksQueue[SortTaskIndex];
				TasksQueue[SortTaskIndex]       = TasksQueue[SortTaskIndex + ONE];
				TasksQueue[SortTaskIndex + ONE] = Struct_Temp;

			}
			
		}
		
	}
	
	
	
}
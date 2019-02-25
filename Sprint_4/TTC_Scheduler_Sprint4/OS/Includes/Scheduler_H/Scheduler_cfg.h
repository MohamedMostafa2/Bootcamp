/*H**********************************************************************
* FILENAME :Schedular_cfg.h
*
* DESCRIPTION :
*       Schedular Configuration

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

#ifndef __SCHEDULAR_CFG_H__
#define __SCHEDULAR_CFG_H__

#include "../../../Includes/DataTypes.h"

#define FIRST_TASK_INDEX ((uint8)0)
#define INTIAL_VALUE ((uint8)0)
#define OCR_VALUE ((uint8) 250)
typedef enum{
	TaskReady  = ((uint8)0),
	TaskBloced = ((uint8)1),
}TaskState_e;

typedef void (*TaskType)(void);


#endif

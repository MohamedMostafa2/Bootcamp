/*
 * use_story_4.c
 *
 * Created: 2/14/2019 9:30:00 AM
 * Author: Mohamed Mostafa Abdel Karim
 */ 

#include "Types.h"
#include "BitwiseOperations.h"
#include "DIO.h"
#include "Timer.h"


int main(void)
{
	
	
	uint8 counter;
	timer_init();
	DIO_SetPinDirection(Pin10,input);
	DIO_SetPinDirection(Pin12,output);
	DIO_SetPinDirection(Pin13,output);
	DIO_SetPinDirection(Pin14,output);
    while (1) 
    {
	for(counter=0;counter < 25;counter++){
		DIO_WritePin(Pin12,high);
		DIO_WritePin(Pin13,low);
		DIO_WritePin(Pin14,low);
		timer_delay(40);
		if (DIO_ReadPin(Pin10))
		{
			DIO_WritePin(Pin13,high);
			DIO_WritePin(Pin12,low);
			DIO_WritePin(Pin11,low);
			timer_delay(1000);
		}
	}
	for(counter=0;counter < 25;counter++){
		DIO_WritePin(Pin12,low);
		DIO_WritePin(Pin13,low);
		DIO_WritePin(Pin14,high);
		timer_delay(40);
		if (DIO_ReadPin(Pin10))
		{
			DIO_WritePin(Pin12,low);
			DIO_WritePin(Pin13,high);
			DIO_WritePin(Pin14,low);
			timer_delay(1000);
		}
	}
	for(counter=0;counter < 25;counter++){
		DIO_WritePin(Pin12,low);
		DIO_WritePin(Pin13,high);
		DIO_WritePin(Pin14,low);
		timer_delay(40);
		if (DIO_ReadPin(Pin10))
		{
			DIO_WritePin(Pin12,low);
			DIO_WritePin(Pin13,high);
			DIO_WritePin(Pin14,low);
			timer_delay(1000);
		}
	}
		
    }
	
	return 0;
}


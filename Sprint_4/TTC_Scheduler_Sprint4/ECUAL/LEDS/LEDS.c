/*H**********************************************************************
* FILENAME :LEDS.c
*
* DESCRIPTION :
*       LEDS Driver
*
* PUBLIC FUNCTIONS :
*       void TurnLED(uint8 LED_Num,uint8 LED_State)
*       void InitLED(uint8 LED_Num)
*
* NOTES :
*       These Driver For Kit LEDs
*
*
* AUTHOR :    Mohamed AbdelKarim        START DATE :    19 Feb 19
*
* CHANGES : None
*
*
*H*/

#include "../../Includes/DataTypes.h"
#include "../../Includes/BitwiseOperations.h"
#include "../../MCAL/Includes/DIO_H/DIO.h"
#include "../Includes/LEDS_H/LEDS.h"

void InitLED(uint8 LED_Num){
	
	DIO_SetPinDirection(LED_Num,OUTPUT);
	
}

void TurnLED(uint8 LED_Num,uint8 LED_State){

	if (LED_State == Led_Toggle)
	{
		DIO_TogglePin(LED_Num);
	}
	else
	{
		DIO_WritePin(LED_Num ,LED_State);
	}	
}
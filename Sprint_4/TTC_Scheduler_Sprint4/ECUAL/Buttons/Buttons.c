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


#include "../Includes/Buttoms_H/Buttoms.h"
#include "../../MCAL/Includes/DIO_H/DIO.h"


uint8 ReadButtom(uint8 ButtonNum){
	
	switch(ButtonNum){
		
		case Button0 : return DIO_ReadPin(Button0);
					   break;
		case Button1 : return DIO_ReadPin(Button1);
		               break;
		default: return ERROR; 
		         break;
	}
	
}
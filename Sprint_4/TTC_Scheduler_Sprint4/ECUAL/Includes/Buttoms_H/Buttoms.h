/*H**********************************************************************
* FILENAME : Buttoms.h
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

#ifndef __BUTTONS_H__
#define __BUTTONS_H__

#include "../../../Includes/DataTypes.h"

#define ERROR ((uint8)0xFF);

typedef enum{
	
	ButtonPressed    = ((uint8)1),
	ButtonNotPressed = ((uint8)0),
}ButtonState_e; 

typedef enum{
	
	Button0 = ((uint8)23),
	Button1 = ((uint8)10),
}ButtonsNum_e;



uint8 ReadButtom(uint8 ButtomNum);

#endif
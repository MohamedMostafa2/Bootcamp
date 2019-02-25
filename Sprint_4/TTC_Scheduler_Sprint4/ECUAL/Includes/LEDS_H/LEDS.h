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

#ifndef __LEDS_H__
#define __LEDS_H__

#include "../../../Includes/DataTypes.h"
#include "../../../MCAL/Includes/DIO_H/DIO.h"

#define LEDS_MAX_NUMBER ((uint8) 4)

typedef enum{
	  Led_OFF    =  (LOW),
	  Led_ON     =  (HIGH),
	  Led_Toggle =  ((uint8)2),
}LedState_e;
			
typedef enum{
	Led0  =  (Pin12),
	Led1  =  (Pin13),
	Led2  =  (Pin14),
	Led3  =  (Pin15),
}LedPins_e;
			


extern void InitLED(uint8 LED_Num);
extern void TurnLED(uint8 LED_Num,uint8 LED_State);

#endif
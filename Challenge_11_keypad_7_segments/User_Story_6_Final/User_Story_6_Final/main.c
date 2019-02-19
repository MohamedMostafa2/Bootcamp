/*
 * User_Story_1.c
 *
 * Created: 2/18/2019 12:48:52 PM
 * Author : AVE-LAP-049
 */ 
#include "Includes/Types.h"
#include "Includes/DIO/DIO.h"
#include "Includes/7-Segments/BCDSevSegment.h"
#include "Includes/7-Segments/BCDSevSegment_cfg.h"
#include "Includes/Keypad/Keypad.h"
#include "Includes/Keypad/Keypad_cfg.h"
#include <util/delay.h>

#define TRUE 1

int main(void)
{
    /* Set Seven Segments Data Pins to Output   */
	DIO_SetPinDirection(SEV_SEGMENTS_DATA_PIN_0,output);
	DIO_SetPinDirection(SEV_SEGMENTS_DATA_PIN_1,output);
	DIO_SetPinDirection(SEV_SEGMENTS_DATA_PIN_2,output);
	DIO_SetPinDirection(SEV_SEGMENTS_DATA_PIN_3,output);
	/***********************/
	
	/* Set Seven Segment Enable Pin to Output   */
	DIO_SetPinDirection(SEV_SEGMENTS_A_Enable_PIN,output);

	Keypad_init();
	
	/* Enable Seven Segment ( A )   */
	BCDSevegments_enable(SEV_SEGMENTS_A_Enable_PIN);
	
    while (TRUE) 
    {
		BCDSevegments_displayNo( Keypad_getPressedKey() );
		
    }
}


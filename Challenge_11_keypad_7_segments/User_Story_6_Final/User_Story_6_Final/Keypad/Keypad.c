/*
 * Keypad.c
 *
 * Created: 2/18/2019 2:43:37 PM
 *  Author: AVE-LAP-049
 */ 

#include "../Includes/Types.h"
#include "../Includes/DIO/BitwiseOperations.h"
#include "../Includes/Keypad/Keypad_cfg.h"
#include "../Includes/Keypad/Keypad.h"
#include "../Includes/DIO/DIO.h"


void Keypad_init(void){
	
	/* Row Inputs */
	DIO_SetPinDirection(Row1,input);
	DIO_SetPinDirection(Row2,input);
	DIO_SetPinDirection(Row3,input);
	
	/* Pull-Up Resistor */
	DIO_WritePin(Row1,high);
	DIO_WritePin(Row2,high);
	DIO_WritePin(Row3,high);
	
	/* Col Outputs */
	DIO_SetPinDirection(Col1,output);
	DIO_SetPinDirection(Col2,output);
	DIO_SetPinDirection(Col3,output);
	
	/* Col High Default*/
	DIO_WritePin(Col1,high);
	DIO_WritePin(Col2,high);
	DIO_WritePin(Col3,high);

}

uint8 Keypad_getPressedKey(void){
	uint8 i,j;
	while(TRUE){
		for(i=INTIAL_VALUE;i<Col_numbers;i++){
			
			/* Set Columns to Default State = High */
			DIO_WritePin(Col1,high);
			DIO_WritePin(Col2,high);
			DIO_WritePin(Col3,high);
			
			DIO_WritePin(Col1+i,low);
			for (j=INTIAL_VALUE;j<Row_numbers;j++)
			{
				if (!(DIO_ReadPin(Row1+j)))
				{
					return (j*Row_numbers)+i+1U;
				}
			}
		}

	}
	
	
}


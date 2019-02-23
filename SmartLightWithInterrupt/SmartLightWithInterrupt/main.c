/*
 * SmartLightWithInterrupt.c
 *
 * Created: 2/20/2019 9:10:07 PM
 * Author : AVE-LAP-049
 */ 

#include "Includes/Types.h"
#include "Includes/DIO/DIO.h"
#include "Includes/DIO/BitwiseOperations.h"
#include "Includes/Timer/Timer.h"
#include "Includes/Interrupts/Interrupts.h"
#include <avr/interrupt.h>

volatile uint8 TOV_Flag = 0 ;
volatile uint8 INT2_Flag = 0 ;
volatile uint8 TimerCounter = 0 ;
 
int main(void)
{
	uint8 Break_GO_State = 0;
	
	DIO_SetPinDirection(Pin10,INPUT);
	
	DIO_SetPinDirection(Pin12,OUTPUT);
	DIO_SetPinDirection(Pin13,OUTPUT);
	DIO_SetPinDirection(Pin14,OUTPUT);
	DIO_SetPinDirection(Pin15,OUTPUT);
	
	EnableGlobalInterrupts();
	EnableTimerInterrupt();
	EnableINT2_Interrupts();
	timer_init();
	StartTimer();
    while (1){
		
		if ( TOV_Flag == 1){ 
			DIO_WritePin(Pin12,HIGH); /* LED0 is ON */
			DIO_WritePin(Pin14,LOW); /* LED1 is OFF */
			DIO_WritePin(Pin13,LOW); /* LED2 is OFF */
			TOV_Flag = 0;
			while(1){
				if (TOV_Flag == 1){
					
					DIO_WritePin(Pin12,LOW); /* LED0 is OFF */
					DIO_WritePin(Pin14,HIGH); /* LED1 is ON */
					DIO_WritePin(Pin13,LOW); /* LED2 is OFF */
					TOV_Flag = 0;
					
					while(1){
						if (TOV_Flag == 1){
							DIO_WritePin(Pin12,LOW); /* LED0 is OFF */
							DIO_WritePin(Pin14,LOW); /* LED1 is OFF */
							DIO_WritePin(Pin13,HIGH); /* LED2 is ON */
							TOV_Flag = 0;
							Break_GO_State = 1 ;
							break;
						}
						else{
							
							if (INT2_Flag == 1){						
								DIO_WritePin(Pin12,HIGH); /* LED0 is ON */
								DIO_WritePin(Pin14,LOW); /* LED1 is OFF */
								DIO_WritePin(Pin13,LOW); /* LED2 is OFF */
								INT2_Flag = 0;
								TOV_Flag = 0;
								Break_GO_State = 1 ;
								break;
							}
							else{}	
						}
					}
					
				} /* second if */
				else{
					
					if (INT2_Flag == 1){
						DIO_WritePin(Pin12,LOW);  /* LED0 is OFF */
						DIO_WritePin(Pin14,HIGH); /* LED1 is ON */
						DIO_WritePin(Pin13,LOW);  /* LED2 is OFF */
						INT2_Flag = 0;
						TOV_Flag = 0;
						break;
					}
					else{}
					
				}
				if(Break_GO_State == 1){
					Break_GO_State = 0;
					break;
				}
			} /*while */
			
		} /* first if */
		else{
			
			if (INT2_Flag == 1){
				DIO_WritePin(Pin12,LOW);  /* LED0 is OFF */
				DIO_WritePin(Pin14,HIGH); /* LED0 is ON */
				DIO_WritePin(Pin13,LOW);  /* LED0 is OFF */
				INT2_Flag = 0;
				TOV_Flag = 0;
			}
			else{}
				
        }
  }
}

ISR(TIMER0_OVF_vect){
	
	TimerCounter++;
	if (TimerCounter == 255)
	{
		TOV_Flag = 1;
		TimerCounter = 0;
	}
}

ISR(INT2_vect){
	
	INT2_Flag = 1;
}
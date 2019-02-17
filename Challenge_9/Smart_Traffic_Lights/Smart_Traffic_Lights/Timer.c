/*
 * Timer.c
 *
 * Created: 2/14/2019 9:33:28 AM
 *  Author: Mohamed Mostafa Abdel Karim
 */ 

#include "Types.h"
#include "BitwiseOperations.h"
#include "Timer.h"
#include "DIO.h"

void timer_delay(uint32 n){
	
	uint32 i;
	
	Set_Bit(TCCR0,CS00); /* 64 prescaler */
	Set_Bit(TCCR0,CS01);
	
	for(i=n;i>0;i--)
	{
		while(!(Get_Bit(TIFR,OCF0))); /* 1 milliseconds */
		
		Clear_Bit(TCCR0,CS00); /* Timer Stopped */
		Clear_Bit(TCCR0,CS01);
		
		Set_Bit(TIFR,OCF0);
		
		Set_Bit(TCCR0,CS00); /* 64 prescaler */
		Set_Bit(TCCR0,CS01);
	
	}
	
	
}

void timer_init(void){
	
	TCNT0 = 0x00; /* Timer Value = 0*/
	
	Set_Bit(TCCR0,WGM01); /* CTC Mode */
	
	OCR0 = 0xFA; /* OCR0 = 250 */
	
	
}
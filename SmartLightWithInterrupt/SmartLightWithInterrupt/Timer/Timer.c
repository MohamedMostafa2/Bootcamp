/*
 * Timer.c
 *
 * Created: 2/14/2019 9:33:28 AM
 *  Author: Mohamed Mostafa Abdel Karim
 */ 

#include "../Includes/Types.h"
#include "../Includes/DIO/BitwiseOperations.h"
#include "../Includes/Timer/Timer.h"
#include "../Includes/DIO/DIO.h"
#include "../Includes/Interrupts/Interrupts.h"

void timer_delay(uint32 n){
	
	uint32 i;
	
	StartTimer();
	
	for(i=n;i>0;i--)
	{
		while(!(Get_Bit(TIFR_REG,OCF0_BIT))); /* 1 milliseconds */
		
		StopTimer();
		
		Set_Bit(TIFR_REG,OCF0_BIT);
		
		StartTimer();
	
	}
	
	
}

void timer_init(void){
	
	TCNT0_REG = 0x00; /* Timer Value = 0*/
	
	Clear_Bit(TCCR0_REG,WGM00_BIT); /* Normal Mode */
	Clear_Bit(TCCR0_REG,WGM01_BIT); 
	
	
}

void EnableTimerInterrupt(void){
	
	Set_Bit(TIMSK_REG,TOIE0_BIT);
	
}

void StartTimer(void){
	
	Set_Bit(TCCR0_REG,CS00_BIT); /* 64 prescaler */
	Set_Bit(TCCR0_REG,CS01_BIT);
	
}

void StopTimer(void){
	
	Clear_Bit(TCCR0_REG,CS00_BIT); /* Timer Stopped */
	Clear_Bit(TCCR0_REG,CS01_BIT);
}

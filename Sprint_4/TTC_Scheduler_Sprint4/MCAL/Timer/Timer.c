/*H**********************************************************************
* FILENAME :Timer.c
*
* DESCRIPTION :
*       Timer Driver
*
* PUBLIC FUNCTIONS :
*       void timer0_init(void)
*       void StartTimer0(void)
*       void StopTimer0(void)
*       void EnableTimer0Interrupt(void)
*
* NOTES :
*       These Driver For MicroController Timer
*
*
* AUTHOR :    Mohamed AbdelKarim        START DATE :    19 Feb 19
*
* CHANGES : None
*
*
*H*/


#include <avr/interrupt.h>
#include "../../Includes/DataTypes.h"
#include "../../Includes/BitwiseOperations.h"
#include "../Includes/Timer_H/Timer.h"
#include "../Includes/DIO_H/DIO.h"

#include "../../OS/Includes/Scheduler_H/Scheduler.h"

volatile static uint8 TimerPrescalerFlag = 0 ; /* Flag For Timer Prescaler */


/************************************************************************
* Function Name : timer0_init
*
* Parameter
*			I/P : TimerMode , TimerPrescaler
*			O/P : None
*			I/O : None
*
* Return : None
*
* Description : Initialize Timer0 
*               1- Reset Timer Counter
*               2- Choose Timer Mode
*               3- Choose Timer Prescaler					
*
************************************************************************/

void timer0_init(uint8 TimerMode , uint8 TimerPrescaler , uint8 OCR_Value){
	
	TCNT0_REG = INITIAL_VALUE; /* Timer Counter Value = 0 */
	
	switch( TimerMode ) /* Choose Timer Mode */
	{
		case TimerNormalMode:    Clear_Bit(TCCR0_REG,WGM00_BIT); /* Normal Mode */
                                 Clear_Bit(TCCR0_REG,WGM01_BIT);
		                         break;
							  
		case TimerPhasePWM_Mode: Set_Bit(TCCR0_REG,WGM00_BIT);  /* PWM, Phase Correct Mode */
		                         Clear_Bit(TCCR0_REG,WGM01_BIT);
		                         break;
								 
		case TimerCTC_Mode:      Clear_Bit(TCCR0_REG,WGM00_BIT); /* CTC Mode */
		                         Set_Bit(TCCR0_REG,WGM01_BIT);
								
								 
		                         break;
		case TimerFastPWM_Mode:  Set_Bit(TCCR0_REG,WGM00_BIT); /* Fast PWM Mode */
		                         Set_Bit(TCCR0_REG,WGM01_BIT);
		                         break;
								 
		default:   Clear_Bit(TCCR0_REG,WGM00_BIT); /* Default is Normal Mode */
		           Clear_Bit(TCCR0_REG,WGM01_BIT);
		           break;
	}
	
	switch(TimerPrescaler) /* Choose Timer Prescaler */
	{
		
		case TimerPrescaler_1    : TimerPrescalerFlag = TimerPrescaler_1 ;    /* clk / 1 (No prescaling) */
		                           break;
		case TimerPrescaler_8    : TimerPrescalerFlag = TimerPrescaler_8 ;    /* clk / 8 (From prescaler) */
		                           break;
		case TimerPrescaler_64   : TimerPrescalerFlag = TimerPrescaler_64 ;   /* clk / 64 (From prescaler) */
		                           break;
		case TimerPrescaler_256  : TimerPrescalerFlag = TimerPrescaler_256 ;  /* clk / 256 (From prescaler) */
		                           break;
		case TimerPrescaler_1024 : TimerPrescalerFlag = TimerPrescaler_1024 ; /* clk / 1024 (From prescaler) */
		                           break;
		default: TimerPrescalerFlag = TimerPrescaler_64 ; /* Default is 64 Prescaler */
		         break;
		
	}
	
	OCR0_REG = OCR_Value;
	

}


/************************************************************************
* Function Name : EnableTimer0Interrupt
*
* Parameter
*			I/P : None
*			O/P : None
*			I/O : None
*
* Return : None
*
* Description : Enable Timer0 Interrupt
*
************************************************************************/
void EnableTimer0Interrupt(void){
	
	Set_Bit(S_REG,I_BIT);
	
	Set_Bit(TIMSK_REG,OCIE0_BIT); /* Set OCIE0 Bit in TIMSK Register */
	
}



/************************************************************************
* Function Name : StartTimer0
*
* Parameter
*			I/P : None
*			O/P : None
*			I/O : None
*
* Return : None
*
* Description : Start Timer0 to Count
*
************************************************************************/
void StartTimer0(void){
	
	switch(TimerPrescalerFlag)
	{
		case TimerPrescaler_1    : Set_Bit(TCCR0_REG,CS00_BIT);   /* Start Timer with Prescaler = 1 */
		                           Clear_Bit(TCCR0_REG,CS01_BIT); 
		                           Clear_Bit(TCCR0_REG,CS02_BIT);
								   TCNT0_REG = INITIAL_VALUE ;
		                           break;
								   
		case TimerPrescaler_8    : Clear_Bit(TCCR0_REG,CS00_BIT);  /* Start Timer with Prescaler = 8 */
		                           Set_Bit(TCCR0_REG,CS01_BIT);
		                           Clear_Bit(TCCR0_REG,CS02_BIT);
								   TCNT0_REG = INITIAL_VALUE ;
		                           break;
		
		case TimerPrescaler_64   : Set_Bit(TCCR0_REG,CS00_BIT);  /* Start Timer with Prescaler = 64 */
		                           Set_Bit(TCCR0_REG,CS01_BIT);  
								   Clear_Bit(TCCR0_REG,CS02_BIT);
								   TCNT0_REG = INITIAL_VALUE ; 
		                           break;
								   
		case TimerPrescaler_256  : Clear_Bit(TCCR0_REG,CS00_BIT); /* Start Timer with Prescaler = 256 */
		                           Clear_Bit(TCCR0_REG,CS01_BIT);
		                           Set_Bit(TCCR0_REG,CS02_BIT);
								   TCNT0_REG = INITIAL_VALUE ;
		                           break;
								   
		case TimerPrescaler_1024 : Set_Bit(TCCR0_REG,CS00_BIT);  /* Start Timer with Prescaler = 1024 */
		                           Clear_Bit(TCCR0_REG,CS01_BIT);
		                           Set_Bit(TCCR0_REG,CS02_BIT);
								   TCNT0_REG = INITIAL_VALUE ;
		                           break;
		default: Set_Bit(TCCR0_REG,CS00_BIT);  /* Default is Timer start with prescaler = 64 */
		         Set_Bit(TCCR0_REG,CS01_BIT);
		         Clear_Bit(TCCR0_REG,CS02_BIT);
				 TCNT0_REG = INITIAL_VALUE ;
		         break; 
	}
	
}


/************************************************************************
* Function Name : StopTimer0
*
* Parameter
*			I/P : PinNum , PinValue
*			O/P : None
*			I/O : None
*
* Return : None
*
* Description : Stop Timer To Count 
*
************************************************************************/
void StopTimer0(void){
	
	Clear_Bit(TCCR0_REG,CS00_BIT); /* Timer Stopped No clock source */
	Clear_Bit(TCCR0_REG,CS01_BIT);
	Clear_Bit(TCCR0_REG,CS02_BIT);
}

ISR(TIMER0_COMP_vect){
	
  Callback();
 	
}


/*H**********************************************************************
* FILENAME :PWM.c
*
* DESCRIPTION :
*       Pulse Width Modulation (PWM) Driver
*
* PUBLIC FUNCTIONS :
*       void DIO_WritePin(uint8 PinNum,uint8 PinValue)
*       uint8 DIO_ReadPin(uint8 PinNum)
*       DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection)
*
* NOTES :
*       These Driver For MicroController PWM
*
*
* AUTHOR :    Mohamed AbdelKarim        START DATE :    19 Feb 19
*
* CHANGES : None
*
*
*H*/

#include "../../Includes/DataTypes.h"
#include "../Includes/DIO_H/DIO.h"
#include "../Includes/PWM_H/PWM.h"
#include "../../Includes/BitwiseOperations.h"

static uint8 PWM_OutputPinFlag  = 0;
static uint8 PWM1_PrescalerFlag = 0;


/************************************************************************
* Function Name : PWM1_init
*
* Parameter
*			I/P : PWM_OperationMode , PWM_WaveFormMode , PWM_Prescaler , PWM_OutputPin , PWM_Top
*			O/P : None
*			I/O : None
*
* Return : None
*
* Description : Initialize PWM Timer 1
*               1- Set PWM_OperationMode (FastPWM_Mode , PhaseCorrectPWM_Mode)
*               2- Set PWM_WaveFormMode ( PWM1_ToggleMode , PWM1_non_InvertingMode , PWM1_InvertingMode )
*               3- Set PWM_Prescaler (PWM1_Prescaler_1 , PWM1_Prescaler_8 , PWM1_Prescaler_64,
*                                     PWM1_Prescaler_256 , PWM1_Prescaler_1024)
*               4- Set PWM_OutputPin (PWM1_OutputPin_OC1B , PWM1_OutputPin_OC1A)
*               5- Set PWM_Top Value ( 0xFFFF <= PWM_Top <= 0x0003 )
*
************************************************************************/
void PWM1_init(uint8 PWM_OperationMode,uint8 PWM_WaveFormMode,uint8 PWM_Prescaler,uint8 PWM_OutputPin,uint16 PWM_Top){
	
	TCNT1H_REG = INITIAL_VALUE; /* Reset Timer1 Counter Value = 0x0000 */
	TCNT1L_REG = INITIAL_VALUE;
	
	switch(PWM_OutputPin) /* Choose PWM Output Pin */
	{
		case PWM1_OutputPin_OC1B : DIO_SetPinDirection(OC1B_Pin,OUTPUT); /* OC1B set to be PWM OutPut */
                                  PWM_OutputPinFlag = PWM1_OutputPin_OC1B; /* Set Flag to OC1B Pin */
                                  break;
		case PWM1_OutputPin_OC1A : DIO_SetPinDirection(OC1A_Pin,OUTPUT); /* OC1A set to be PWM OutPut */
		                          PWM_OutputPinFlag = PWM1_OutputPin_OC1A; /* Set Flag to OC1A Pin */
		                          break;
		default: DIO_SetPinDirection(OC1A_Pin,OUTPUT); /* OC1A set to be PWM OutPut (Default) */
		         PWM_OutputPinFlag = PWM1_OutputPin_OC1A; /* Set Flag to OC1A Pin */
		         break;
	}
	
	switch(PWM_OperationMode) /* Choose Mode of Operation Fast PWM or Phase Correct PWM */
	{
		
		case FastPWM_Mode : Clear_Bit(TCCR1A_REG,WGM10_BIT); /* Set Mode 14 = Fast PWM  */
		                    Set_Bit(TCCR1A_REG,WGM11_BIT);   /* WGM10_Bit = 0 , WGM11_Bit = 1 */
		                    Set_Bit(TCCR1A_REG,WGM12_BIT);   /* WGM12_Bit = 1 , WGM13_Bit = 1 */
		                    Set_Bit(TCCR1A_REG,WGM13_BIT);
							break;
								
		case PhaseCorrectPWM_Mode : Clear_Bit(TCCR1A_REG,WGM10_BIT); /* Set Mode 10 = PWM, Phase Correct  */
		                            Set_Bit(TCCR1A_REG,WGM11_BIT);   /* WGM10_Bit = 0 , WGM11_Bit = 1 */
		                            Clear_Bit(TCCR1A_REG,WGM12_BIT); /* WGM12_Bit = 0 , WGM13_Bit = 1 */
		                            Set_Bit(TCCR1A_REG,WGM13_BIT);
		                            break;
		default: Clear_Bit(TCCR1A_REG,WGM10_BIT); /* Set Mode 14 = Fast PWM (Default)  */
		         Set_Bit(TCCR1A_REG,WGM11_BIT);   /* WGM10_Bit = 0 , WGM11_Bit = 1 */
		         Set_Bit(TCCR1A_REG,WGM12_BIT);   /* WGM12_Bit = 1 , WGM13_Bit = 1 */
		         Set_Bit(TCCR1A_REG,WGM13_BIT);
		         break;	
	}
	
	
	switch(PWM_WaveFormMode){
		
		case PWM1_ToggleMode        : Set_Bit(TCCR1A_REG,COM1A0_BIT);  /* Toggle Mode Mode */
		                             Clear_Bit(TCCR1A_REG,COM1A1_BIT);  /* COM1A0_Bit = 1 , COM1A1_Bit = 0 */
		                             break;
									 
		case PWM1_non_InvertingMode : Clear_Bit(TCCR1A_REG,COM1A0_BIT);  /* Non-Inverting Mode */
		                             Set_Bit(TCCR1A_REG,COM1A1_BIT);  /* COM1A0_Bit = 0 , COM1A1_Bit = 1 */
		                             break;
									 
		case PWM1_InvertingMode     : Set_Bit(TCCR1A_REG,COM1A0_BIT);  /* Inverting Mode */
		                             Set_Bit(TCCR1A_REG,COM1A1_BIT);  /* COM1A0_Bit = 1 , COM1A1_Bit = 1 */
									 break;
	   default: Set_Bit(TCCR1A_REG,COM1A0_BIT);  /* Inverting Mode (Default) */
	            Set_Bit(TCCR1A_REG,COM1A1_BIT);  /* COM1A0_Bit = 1 , COM1A1_Bit = 1 */
	            break;
		
	}
	
	
	switch(PWM_Prescaler) /* Choose PWM Prescaler */
	{
		
		case PWM1_Prescaler_1    : PWM1_PrescalerFlag = PWM1_Prescaler_1 ;    /* clk / 1 (No prescaling) */
		                           break;
		case PWM1_Prescaler_8    : PWM1_PrescalerFlag = PWM1_Prescaler_8 ;    /* clk / 8 (From prescaler) */
		                           break;
		case PWM1_Prescaler_64   : PWM1_PrescalerFlag = PWM1_Prescaler_64 ;   /* clk / 64 (From prescaler) */
		                           break;
		case PWM1_Prescaler_256  : PWM1_PrescalerFlag = PWM1_Prescaler_256 ;  /* clk / 256 (From prescaler) */
		                           break;
		case PWM1_Prescaler_1024 : PWM1_PrescalerFlag = PWM1_Prescaler_1024 ; /* clk / 1024 (From prescaler) */
		                           break;
		default: PWM1_PrescalerFlag = PWM1_Prescaler_64 ; /* Default is 64 Prescaler */
		                           break;
		
	}


	if( ( PWM_Top <= PWM1_TOP_MAX ) && ( PWM_Top >= PWM1_TOP_MIN ) ) 
	{
		ICR1H_REG = (uint8)(PWM_Top>>8U); /* ICR1 Register is Top = PWM_Top */
		ICR1L_REG = (uint8)(PWM_Top);
	}
	else
	{
		ICR1H_REG = (uint8)(PWM1_TOP_MAX>>8U); /* (Default) ICR1 Register is Top = PWM1_TOP_MAX ( 0xFFFF ) */
		ICR1L_REG = (uint8)(PWM1_TOP_MAX);
		
	}

	
	
}



/************************************************************************
* Function Name : StartPWM1
*
* Parameter
*			I/P : PWM_DutyCycle
*			O/P : None
*			I/O : None
*
* Return : None
*
* Description : Set PWM DutyCycle
*
************************************************************************/
void StartPWM1(uint8 PWM_DutyCycle)
{
	
	uint16 DutyCycle_temp;
	DutyCycle_temp = (( (PWM_DutyCycle) * ( ICR1H_REG + ICR1L_REG ) ) /ONE_HUNDRED ); /* DutyCycle = ( PWM_Duty / 100 ) x Top */
	switch (PWM_OutputPinFlag){
		case PWM1_OutputPin_OC1B : OCR1BH_REG = (uint8)(DutyCycle_temp>>8U); /* Set DutyCycle Value in OCR1B Register */
		                           OCR1BL_REG = (uint8)(DutyCycle_temp);
								   break;
								   
		case PWM1_OutputPin_OC1A : OCR1AH_REG = (uint8)(DutyCycle_temp>>8U); /* Set DutyCycle Value in OCR1A Register */
		                           OCR1AL_REG = (uint8)(DutyCycle_temp);
								   break;
		default: OCR1AH_REG = (uint8)(DutyCycle_temp>>8U); /* Set DutyCycle Value in OCR1A Register (Default) */
		         OCR1AL_REG = (uint8)(DutyCycle_temp);
		         break;
	}

	
	switch(PWM1_PrescalerFlag){
		
		case PWM1_Prescaler_1    : Set_Bit(TCCR1B_REG,CS10_BIT); /* Start PWM with prescaler = 1 */
		                           Clear_Bit(TCCR1B_REG,CS11_BIT);
		                           Clear_Bit(TCCR1B_REG,CS12_BIT);
		                           break;
								   
		case PWM1_Prescaler_8    : Clear_Bit(TCCR1B_REG,CS10_BIT); /* Start PWM with prescaler = 8 */
		                           Set_Bit(TCCR1B_REG,CS11_BIT);
		                           Clear_Bit(TCCR1B_REG,CS12_BIT);
		                           break;
								   
		case PWM1_Prescaler_64   : Set_Bit(TCCR1B_REG,CS10_BIT); /* Start PWM with prescaler = 64 */
		                           Set_Bit(TCCR1B_REG,CS11_BIT);
		                           Clear_Bit(TCCR1B_REG,CS12_BIT);
		                           break;
								   
		case PWM1_Prescaler_256  : Clear_Bit(TCCR1B_REG,CS10_BIT); /* Start PWM with prescaler = 256 */
		                           Clear_Bit(TCCR1B_REG,CS11_BIT);
		                           Set_Bit(TCCR1B_REG,CS12_BIT);
		                           break;
								   
		case PWM1_Prescaler_1024 : Set_Bit(TCCR1B_REG,CS10_BIT); /* Start PWM with prescaler = 1024 */
		                           Clear_Bit(TCCR1B_REG,CS11_BIT);
		                           Set_Bit(TCCR1B_REG,CS12_BIT);
								   break;
								   
		default: Set_Bit(TCCR1B_REG,CS10_BIT); /* Start PWM with prescaler = 1024 (Default) */
		         Clear_Bit(TCCR1B_REG,CS11_BIT);
		         Set_Bit(TCCR1B_REG,CS12_BIT);
		         break;	
	}
	
}



/************************************************************************
* Function Name : StopPWM1
*
* Parameter
*			I/P : PinNum , PinValue
*			O/P : None
*			I/O : None
*
* Return : None
*
* Description : Stop PWM ( No Clock Source )
*
************************************************************************/
void StopPWM1(void){
	
	Clear_Bit(TCCR1B_REG,CS10_BIT); /* PWM Stopped No clock source */
	Clear_Bit(TCCR1B_REG,CS11_BIT);
	Clear_Bit(TCCR1B_REG,CS12_BIT);
}
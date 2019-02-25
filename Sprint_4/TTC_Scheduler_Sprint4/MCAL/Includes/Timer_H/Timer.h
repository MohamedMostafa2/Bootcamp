/*H**********************************************************************
* FILENAME :DIO.h
*
* DESCRIPTION :
*       Digital Input Output Driver
*
* PUBLIC FUNCTIONS :
*       void DIO_WritePin(uint8 PinNum,uint8 PinValue)
*       uint8 DIO_ReadPin(uint8 PinNum)
*       DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection)
*
* NOTES :
*       These Driver For MicroController DIO
*
*
* AUTHOR :    Mohamed AbdelKarim        START DATE :    19 Feb 19
*
* CHANGES : None
*
*
*H*/

#ifndef __TIMER_H__
#define __TIMER_H__

#include "../../../Includes/DataTypes.h"



#define TCNT0_REG	(*(volatile uint8 *) 0x52)
#define TCCR0_REG	(*(volatile uint8 *) 0x53)
#define OCR0_REG	(*(volatile uint8 *) 0x5C)

#define TCCR1B_REG	(*(volatile uint8 *) 0x4E)
#define TCCR1A_REG	(*(volatile uint8 *) 0x4F)

#define TCNT1H_REG	(*(volatile uint8 *) 0x4D)
#define TCNT1L_REG	(*(volatile uint8 *) 0x4C)

#define ICR1H_REG	(*(volatile uint8 *) 0x47)
#define ICR1L_REG	(*(volatile uint8 *) 0x46)

#define OCR1AH_REG	(*(volatile uint8 *) 0x4B)
#define OCR1AL_REG	(*(volatile uint8 *) 0x4A)

#define S_REG	    (*(volatile uint8 *) 0x5F)
#define TIMSK_REG	(*(volatile uint8 *) 0x59)

#define INITIAL_VALUE ((uint8)0x00)

#define TOIE0_BIT ((uint8)0)
#define OCIE0_BIT ((uint8)1)
#define I_BIT     ((uint8)7)

typedef enum{
	
	 CS00_BIT  = ((uint8)0),
     CS01_BIT  = ((uint8)1),
     CS02_BIT  = ((uint8)2),
     WGM00_BIT = ((uint8)6),
     COM00_BIT = ((uint8)4),
     COM01_BIT = ((uint8)5),
     WGM01_BIT = ((uint8)3),
	 
	}TCCR0_Reg_Bits_e;

typedef enum{
	TimerNormalMode    = 0U,
	TimerPhasePWM_Mode = 1U,
	TimerCTC_Mode      = 2U,
	TimerFastPWM_Mode  = 3U,
}TimerModes_e;

typedef enum{
	TimerPrescaler_1    = 0U,
	TimerPrescaler_8    = 1U,
	TimerPrescaler_64   = 2U,
	TimerPrescaler_256  = 3U,
	TimerPrescaler_1024 = 4U,
}TimerPrescaler_e;



/************************************************************************
* Function Name : timer0_init
*
* Parameter
*			I/P : TimerMode , TimerPrescaler , OCR_Value
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
extern void timer0_init(uint8 TimerMode , uint8 TimerPrescaler , uint8 OCR_Value);


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
extern void StartTimer0(void);


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
extern void StopTimer0(void);


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
extern void EnableTimer0Interrupt(void);


#endif
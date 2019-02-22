/*H**********************************************************************
* FILENAME :PWM.h
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

#include "../Includes/DataTypes.h"
#include "../Includes/DIO_Headers/DIO.h"


#define TCCR1B_REG	(*(volatile uint8 *) 0x4E)
#define TCCR1A_REG	(*(volatile uint8 *) 0x4F)

#define TCNT1H_REG	(*(volatile uint8 *) 0x4D)
#define TCNT1L_REG	(*(volatile uint8 *) 0x4C)

#define ICR1H_REG	(*(volatile uint8 *) 0x47)
#define ICR1L_REG	(*(volatile uint8 *) 0x46)

#define OCR1AH_REG	(*(volatile uint8 *) 0x4B)
#define OCR1AL_REG	(*(volatile uint8 *) 0x4A)

#define OCR1BH_REG	(*(volatile uint8 *) 0x49)
#define OCR1BL_REG	(*(volatile uint8 *) 0x48)

#define ONE_HUNDRED    ((uint8)100)
#define INITIAL_VALUE  ((uint8)0x00)
#define ICR1_MAX_VALUE ((uint8)0xFF)


typedef enum{
		OC1B_Pin = Pin28,
		OC1A_Pin = Pin29,
	}OC1x_Pins_e;

typedef enum{   
		WGM10_BIT  = ((uint8)0),
		WGM11_BIT  = ((uint8)1),
		COM1A0_BIT = ((uint8)6),
		COM1A1_BIT = ((uint8)7),
	}TCCR1A_Reg_Bits_e;


typedef enum{
	CS10_BIT  = ((uint8)0),
	CS11_BIT  = ((uint8)1),
	CS12_BIT  = ((uint8)2),
    WGM12_BIT = ((uint8)3),
	WGM13_BIT = ((uint8)4),
	}TCCR1B_RegBits_e;

typedef enum{
	FastPWM_Mode         = ((uint8)0),
	PhaseCorrectPWM_Mode = ((uint8)1),
	}PWM1_OperationMode_e;
	
typedef enum{
	PWM1_OutputPin_OC1B = ((uint8)0),
	PWM1_OutputPin_OC1A = ((uint8)1),
}PWM1_OutputPins_e;


typedef enum{
	PWM1_OutputPin_OC1B = ((uint8)0),
	PWM1_OutputPin_OC1A = ((uint8)1),
	PWM1_OutputPin_OC1A = ((uint8)2),
}PWM1_WaveFormModes_e;

typedef enum{
	PWM1_ToggleMode        = ((uint8)0),
	PWM1_non_InvertingMode = ((uint8)1),
	PWM1_InvertingMode     = ((uint8)2),
}PWM1_WaveFormModes_e;

typedef enum{
	 PWM1_Prescaler_1    = ((uint8)0),
	 PWM1_Prescaler_8    = ((uint8)1),
	 PWM1_Prescaler_64   = ((uint8)2),
	 PWM1_Prescaler_256  = ((uint8)3),
	 PWM1_Prescaler_1024 = ((uint8)4),
	}PWM1_Prescaler;

extern void PWM1_init(void);

extern void StopPWM1(void);

extern void StartPWM1(void);

#endif
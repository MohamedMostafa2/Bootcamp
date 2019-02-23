/*H**********************************************************************
* FILENAME :Motor.c
*
* DESCRIPTION :
*       Motor Driver
*
* PUBLIC FUNCTIONS :
*       void StartMotor1(uint8 MotorSpeed , uint8 Direction)
*       void StopMotor1(void)
*
* NOTES :
*       These Driver For DC Motor
*
*
* AUTHOR :    Mohamed AbdelKarim        START DATE :    19 Feb 19
*
* CHANGES : None
*
*
*H*/


#include "../../MCAL/Includes/PWM_H/PWM.h"
#include "../Includes/Motor_H/Motor.h"
#include "../../Includes/BitwiseOperations.h"
#include "../../MCAL/Includes/DIO_H/DIO.h"

void StartMotor1(uint8 MotorSpeed , uint8 Direction){
	
	DIO_SetPinDirection(MOTOR_1_DIR_A_PIN,OUTPUT);
	DIO_SetPinDirection(MOTOR_1_DIR_B_PIN,OUTPUT);

	switch(Direction){
		case MOTOR_RIGHT_DIRECTION : DIO_WritePin(MOTOR_1_DIR_A_PIN,HIGH);
									 DIO_WritePin(MOTOR_1_DIR_B_PIN,LOW);
			break;
		case MOTOR_LEFT_DIRECTION :  DIO_WritePin(MOTOR_1_DIR_A_PIN,LOW);
									 DIO_WritePin(MOTOR_1_DIR_B_PIN,HIGH);
			break;
		default: DIO_WritePin(MOTOR_1_DIR_A_PIN,LOW);
		         DIO_WritePin(MOTOR_1_DIR_B_PIN,HIGH);
				 break;
	}
	
	StartPWM1(MotorSpeed);
	
}

void StopMotor1(void){
	
	StopPWM1();
	
}
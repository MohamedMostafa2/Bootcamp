/*
 * Main.c
 *
 * Created: 2/19/2019 11:43:47 AM
 * Author : AVE-LAP-049
 */ 

#include "Includes/DataTypes.h"
#include "MCAL/Includes/DIO_H/DIO.h"
#include "Includes/BitwiseOperations.h"
#include "MCAL/Includes/PWM_H/PWM.h"
#include "ECUAL/Includes/Motor_H/Motor.h"

int main(void)
{
	
	
	PWM1_init(FastPWM_Mode,PWM1_InvertingMode,PWM1_Prescaler_1024,OC1A_Pin,0xFFF0);
	StartMotor1(0,MOTOR_RIGHT_DIRECTION);
    while (1) 
    {

    }
}


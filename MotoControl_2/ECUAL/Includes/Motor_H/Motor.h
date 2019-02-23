/*
 * Motor.h
 *
 * Created: 2/21/2019 2:38:27 PM
 *  Author: AVE-LAP-049
 */ 

#ifndef __MOTOR_H__
#define __MOTOR_H__

#include "../../../Includes/DataTypes.h"
#include "../../../MCAL/Includes/DIO_H/DIO.h"

#define MOTOR_RIGHT_DIRECTION ((uint8)0)
#define MOTOR_LEFT_DIRECTION ((uint8)1)

#define MOTOR_1_DIR_A_PIN (Pin30)
#define MOTOR_1_DIR_B_PIN (Pin31)


extern void StartMotor1(uint8 DutyCycle , uint8 Direction);

extern void StopMotor1(void);

#endif
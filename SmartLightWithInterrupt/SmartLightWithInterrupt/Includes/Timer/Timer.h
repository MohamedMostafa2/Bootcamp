/*
 * Timer.h
 *
 * Created: 2/14/2019 9:35:03 AM
 *  Author: Mohamed Mostafa Abdel Karim
 */ 
#ifndef __TIMER_H__
#define __TIMER_H__

#include "../Types.h"

#define TCNT0_REG	(*(volatile uint8 *) 0x52)
#define TCCR0_REG	(*(volatile uint8 *) 0x53)
#define OCR0_REG	(*(volatile uint8 *) 0x5C)

#define CS00_BIT	((uint8)0)
#define CS01_BIT	((uint8)1)
#define CS02_BIT	((uint8)2)

#define COM00_BIT	((uint8)4)
#define COM01_BIT	((uint8)5)

#define WGM00_BIT	((uint8)3)
#define WGM01_BIT	((uint8)6)


extern void timer_delay(uint32 n);

extern void timer_init(void);

extern void StartTimer(void);
extern void StopTimer(void);
extern void EnableTimerInterrupt(void);


#endif
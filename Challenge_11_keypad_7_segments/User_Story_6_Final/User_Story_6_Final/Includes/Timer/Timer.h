/*
 * Timer.h
 *
 * Created: 2/14/2019 9:35:03 AM
 *  Author: Mohamed Mostafa Abdel Karim
 */ 
#ifndef __TIMER_H__
#define __TIMER_H__

#include "../Types.h"

#define TCNT0	(*(volatile uint8 *) 0x52)
#define TCCR0	(*(volatile uint8 *) 0x53)
#define OCR0	(*(volatile uint8 *) 0x5C)
#define TIFR	(*(volatile uint8 *) 0x58)

#define CS00	((uint8)0)
#define CS01	((uint8)1)
#define CS02	((uint8)2)

#define COM00	((uint8)4)
#define COM01	((uint8)5)

#define WGM00	((uint8)3)
#define WGM01	((uint8)6)

#define OCF0	((uint8)1)

extern void timer_delay(uint32 n);

extern void timer_init(void);


#endif
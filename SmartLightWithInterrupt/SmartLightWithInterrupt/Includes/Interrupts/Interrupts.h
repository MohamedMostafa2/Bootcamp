/*
 * Timer.h
 *
 * Created: 2/14/2019 9:35:03 AM
 *  Author: Mohamed Mostafa Abdel Karim
 */ 
#ifndef __INTERRUPTS_H__
#define __INTERRUPTS_H__

#include "../Types.h"

#define SREG_REG		(*(volatile uint8 *) 0x5F)
#define TIFR_REG		(*(volatile uint8 *) 0x58)
#define TIMSK_REG	    (*(volatile uint8 *) 0x59)

#define MCUCSR_REG	    (*(volatile uint8 *) 0x54)
#define GICR_REG	    (*(volatile uint8 *) 0x5B)
#define GIFR_REG	    (*(volatile uint8 *) 0x5A)

#define GLOBAL_INTERRUPT_ENABLE_BIT (7U)

#define TOIE0_BIT (0U)
#define OCIE0_BIT (1U)

#define TOV0_BIT (0U)
#define OCF0_BIT (1U)


#define ISC2_BIT (6U)

#define INT2_BIT (5U)

#define INTF2_BIT (5U)

extern void EnableGlobalInterrupts(void);

extern void EnableINT2_Interrupts(void);

#endif
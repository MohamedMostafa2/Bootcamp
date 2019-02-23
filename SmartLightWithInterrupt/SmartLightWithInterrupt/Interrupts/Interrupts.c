/*
 * Interrupts.c
 *
 * Created: 2/20/2019 9:59:14 PM
 *  Author: AVE-LAP-049
 */ 

#include "../Includes/Types.h"
#include "../Includes/DIO/BitwiseOperations.h"
#include "../Includes/DIO/DIO.h"
#include "../Includes/Interrupts/Interrupts.h"

void EnableGlobalInterrupts(void){
	
	Set_Bit(SREG_REG,GLOBAL_INTERRUPT_ENABLE_BIT);
}

void EnableINT2_Interrupts(void){
	
	Set_Bit(MCUCSR_REG,ISC2_BIT);
	
	Set_Bit(GICR_REG,INT2_BIT);
	
}
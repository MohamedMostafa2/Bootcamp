/*
 * Bitwise_Operations.h
 *
 * Created: 2/13/2019 10:54:34 AM
 *  Author: Mohamed Mostafa Abdel Karim
 */ 
#ifndef __BITWISEOPERATIONS_H__
#define __BITWISEOPERATIONS_H__

#include "Types.h"

#define Set_Bit(Register,Bit)		((Register)|=(1U<<(uint8)(Bit)))

#define Clear_Bit(Register,Bit)		((Register)&=~(1U<<(uint8)(Bit)))

#define Get_Bit(Register,Bit)		(((Register)>>(uint8)(Bit))&1U)

#define Toggle_Bit(Register,Bit)	((Register)^=(uint8)(1U<<(Bit)))

#endif
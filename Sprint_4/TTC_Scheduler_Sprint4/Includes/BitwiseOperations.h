/*H**********************************************************************
* FILENAME :BitwiseOperations.h
*
* DESCRIPTION :
*       Macros as Function For Bit operations
*
* PUBLIC FUNCTIONS :
*       Set_Bit(Register,Bit)
*       Clear_Bit(Register,Bit)
*       Get_Bit(Register,Bit)
*       Toggle_Bit(Register,Bit)
*
* NOTES :
*       This Can Fit for any Register with any Size
*
*
* AUTHOR :    Mohamed AbdelKarim        START DATE :    19 Feb 19
*
* CHANGES : None
*
*
*H*/
#ifndef __BITWISEOPERATIONS_H__
#define __BITWISEOPERATIONS_H__

#include "DataTypes.h"

#define Set_Bit(Register,Bit)		((Register)|=(1U<<(uint8)(Bit)))

#define Clear_Bit(Register,Bit)		((Register)&=~(1U<<(uint8)(Bit)))

#define Get_Bit(Register,Bit)		(((Register)>>(uint8)(Bit))&1U)

#define Toggle_Bit(Register,Bit)	((Register)^=(uint8)(1U<<(Bit)))

#endif
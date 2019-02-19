/*
 * DIO.c
 *
 * Created: 2/13/2019 2:03:28 PM
 *  Author: Mohamed Mostafa Abdel Karim
 */ 

#include "../Includes/Types.h"
#include "../Includes/DIO/BitwiseOperations.h"
#include "../Includes/DIO/DIO.h"

void DIO_WritePin(uint8 PinNum,uint8 PinValue){
	
	if( (PinNum >= Pin0) && (PinNum <= Pin7) ){
		if(PinValue == low){
			Clear_Bit(PORTA,PinNum);
		}
		else{
			Set_Bit(PORTA,PinNum);
		}
	}
	else if( (PinNum >= Pin8) && (PinNum <= Pin15) ){
		if(PinValue == low){
			Clear_Bit(PORTB,PinNum-Pin8);
		}
		else{
			Set_Bit(PORTB,PinNum-8U);
		}
	}
	else if( (PinNum >= Pin16) && (PinNum <= Pin23) ){
		if(PinValue == low){
			Clear_Bit(PORTC,PinNum-Pin16);
		}
		else{
			Set_Bit(PORTC,PinNum-Pin16);
		}
	}
	else if( (PinNum >= Pin24) && (PinNum <= Pin31) ){
		if(PinValue == low){
			Clear_Bit(PORTD,PinNum-Pin24);
		}
		else{
			Set_Bit(PORTD,PinNum-Pin24);
		}
	}
	else{
		
	}
	
}
uint8 DIO_ReadPin(uint8 PinNum){
	
	if( (PinNum >= Pin0) && (PinNum <= Pin7) ){
		return Get_Bit(PINA,PinNum);
	}
	else if( (PinNum >= Pin8) && (PinNum <= Pin15) ){
		return Get_Bit(PINB,PinNum-Pin8);
	}
	else if( (PinNum >= Pin16) && (PinNum <= Pin23) ){
		return Get_Bit(PINC,PinNum-Pin16);
	}
	else if( (PinNum >= Pin24) && (PinNum <= Pin31) ){
		return Get_Bit(PIND,PinNum-Pin24);
	}
	else{
		
	}
	
}
void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection){
	
	if( (PinNum >= Pin0) && (PinNum <= Pin7) ){
		if(PinDirection == low){
			Clear_Bit(DDRA,PinNum);
		}
		else{
			Set_Bit(DDRA,PinNum);
		}
	}
	else if( (PinNum >= Pin8) && (PinNum <= Pin15) ){
		if(PinDirection == low){
			Clear_Bit(DDRB,PinNum-Pin8);
		}
		else{
			Set_Bit(DDRB,PinNum-Pin8);
		}
	}
	else if( (PinNum >= Pin16) && (PinNum <= Pin23) ){
		if(PinDirection == low){
			Clear_Bit(DDRC,PinNum-Pin16);
		}
		else{
			Set_Bit(DDRC,PinNum-Pin16);
		}
	}
	else if( (PinNum >= Pin24) && (PinNum <= Pin24) ){
		if(PinDirection == low){
			Clear_Bit(DDRD,PinNum-Pin24);
		}
		else{
			Set_Bit(DDRD,PinNum-Pin24);
		}
	}
	else{
		
	}
	
	
}

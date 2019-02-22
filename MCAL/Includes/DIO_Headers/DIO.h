/*H**********************************************************************
* FILENAME :DIO.h
*
* DESCRIPTION :
*       Digital Input Output Driver
*
* PUBLIC FUNCTIONS :
*       void DIO_WritePin(uint8 PinNum,uint8 PinValue)
*       uint8 DIO_ReadPin(uint8 PinNum)
*       DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection)
*
* NOTES :
*       These Driver For MicroController DIO
*
*
* AUTHOR :    Mohamed AbdelKarim        START DATE :    19 Feb 19
*
* CHANGES : None
*
*
*H*/

#ifndef __DIO_H__
#define __DIO_H__

#include "../DataTypes.h"


#define PORTA_REG	(*(volatile uint8 *) 0x3B)
#define DDRA_REG	(*(volatile uint8 *) 0x3A)
#define PINA_REG	(*(volatile uint8 *) 0x39)

#define PORTB_REG	(*(volatile uint8 *) 0x38)
#define DDRB_REG	(*(volatile uint8 *) 0x37)
#define PINB_REG	(*(volatile uint8 *) 0x36)

#define PORTC_REG	(*(volatile uint8 *) 0x35)
#define DDRC_REG	(*(volatile uint8 *) 0x34)
#define PINC_REG	(*(volatile uint8 *) 0x33)

#define PORTD_REG	(*(volatile uint8 *) 0x32)
#define DDRD_REG	(*(volatile uint8 *) 0x31)
#define PIND_REG	(*(volatile uint8 *) 0x30)

#define ERROR_PIN_NUM	((uint8)0xFF)

typedef enum{
	 Pin0  = ((uint8)0),
     Pin1  = ((uint8)1),
     Pin2  = ((uint8)2),
     Pin3  = ((uint8)3),
     Pin4  = ((uint8)4),
     Pin5  = ((uint8)5),
     Pin6  = ((uint8)6),
     Pin7  = ((uint8)7),
     Pin8  = ((uint8)8),
     Pin9  = ((uint8)9),
     Pin10 = ((uint8)10),
     Pin11 = ((uint8)11),
     Pin12 = ((uint8)12),
     Pin13 = ((uint8)13),
     Pin14 = ((uint8)14),
     Pin15 = ((uint8)15),
     Pin16 = ((uint8)16),
     Pin17 = ((uint8)17),
     Pin18 = ((uint8)18),
     Pin19 = ((uint8)19),
     Pin20 = ((uint8)20),
     Pin21 = ((uint8)21),
     Pin22 = ((uint8)22),
     Pin23 = ((uint8)23),
     Pin24 = ((uint8)24),
     Pin25 = ((uint8)25),
     Pin26 = ((uint8)26),
     Pin27 = ((uint8)27),
     Pin28 = ((uint8)28),
     Pin29 = ((uint8)29),
     Pin30 = ((uint8)30),
     Pin31 = ((uint8)31),
	}Pins_e;
	
	
typedef enum{
	INPUT  = ((uint8)0),
	OUTPUT = ((uint8)1),
	}PinDirection_e;

typedef enum{
	
	LOW  = ((uint8)0),
	HIGH = ((uint8)1),
	
	}PinValue_e;



/************************************************************************
* Function Name : DIO_WritePin
*
* Parameter
*			I/P : PinNum , PinValue
*			O/P : None
*			I/O : None
*
* Return : None
*
* Description : Set (High) or Clear (Low) to Specific Pin
*
************************************************************************/
extern void DIO_WritePin(uint8 PinNum,uint8 PinValue);



/************************************************************************
* Function Name : DIO_ReadPin
*
* Parameter
*			I/P : PinNum
*			O/P : None
*			I/O : None
*
* Return : Value of PinNum
*
* Description : Get Value of Specific Pin (High/Low)
*
************************************************************************/
extern uint8 DIO_ReadPin(uint8 PinNum);


/************************************************************************
* Function Name : DIO_SetPinDirection
*
* Parameter
*			I/P : PinNum , PinDirection
*			O/P : None
*			I/O : None
*
* Return : None
*
* Description : Set Direction To Specific Pin (Input / Output)
*
************************************************************************/
extern void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection);

#endif
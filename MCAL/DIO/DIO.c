/*H**********************************************************************
* FILENAME :DIO.c
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

#include "../Includes/DataTypes.h"
#include "../Includes/BitwiseOperations.h"
#include "../Includes/DIO_Headers/DIO.h"


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
void DIO_WritePin(uint8 PinNum,uint8 PinValue){
	
    if( (PinNum >= Pin0) && (PinNum <= Pin7) ) /* Check If PinNum in PortA   */
    {
	
	    if(PinValue == LOW) /* Check If Pin Value = LOW */
	    { 
		
		    Clear_Bit(PORTA_REG,PinNum); /* Clear Bit (PinNum) on PortA Register  */
                                     /* Ex. PinNum = 5 ,Then Clear Bit 5 on PortA */
	    }
	    else /* Default State is Set Bit*/
	    { 
		    Set_Bit(PORTA_REG,PinNum); /* Set Bit (PinNum) on PortA Register  */
                                   /* Ex. PinNum = 3 ,Then Clear Bit 3 on PortA */
	    }
    }

    else if( (PinNum >= Pin8) && (PinNum <= Pin15) ) /* Check If PinNum in PortB   */
    {
	    if(PinValue == LOW) /* Check If PinValue = LOW */
	    {  
		    Clear_Bit(PORTB_REG,PinNum-Pin8); /* Clear Bit (PinNum - 8) on PortB Register  */
                                          /* Ex. PinNum = 9 ,Then Clear Bit 1 on PortB */
	    }
	    else /* Default State is Set Bit*/
	    { 
		    Set_Bit(PORTB_REG,PinNum-Pin8); /* Set Bit (PinNum - 8) on PortB Register  */
                                        /* Ex. PinNum = 10 ,Then Set Bit 2 on PortB */	
	    }
    }

    else if( (PinNum >= Pin16) && (PinNum <= Pin23) ) /* Check If PinNum in PortC   */
    {
	    if(PinValue == LOW) /* Check If PinValue = LOW */
	    { 
		    Clear_Bit(PORTC_REG,PinNum-Pin16); /* Clear Bit (PinNum - 16) on PortC Register  */
                                           /* Ex. PinNum = 20 ,Then Clear Bit 4 on PortC */		
	    }    
	    else /* Default State is Set Bit*/
	    { 
            Set_Bit(PORTC_REG,PinNum-Pin16);   /* Set Bit (PinNum - 16) on PortC Register  */
                                           /* Ex. PinNum = 21 ,Then Set Bit 5 on PortC */		
        }
    }

    else if( (PinNum >= Pin24) && (PinNum <= Pin31) )  /* Check If PinNum in PortD   */
    {
	    if(PinValue == LOW) /* Check If PinValue = LOW */
	    { 
		    Clear_Bit(PORTD_REG,PinNum-Pin24); /* Clear Bit (PinNum - 23) on PortD Register  */
                                           /* Ex. PinNum = 25 ,Then Clear Bit 2 on PortD */
	    }                                  
	    else /* Default State is Set Bit*/
	    {
			Set_Bit(PORTD_REG,PinNum-Pin24);  /* Set Bit (PinNum - 23) on PortD Register  */
                                          /* Ex. PinNum = 23 ,Then Set Bit 0 on PortD */
	    }                             
    }
    else
    {
		/* Do Nothing */
		/* PinNum Out of Range ( 0 - 31 ) */					
    }
						
}




/************************************************************************
* Function Name : DIO_ReadPin
*
* Parameter
*			I/P : PinNum
*			O/P : None
*			I/O : None
*
* Return : Value of PinNum
		   Return 0xFF if PinNum Out Of Range ( 0 - 31 )
*
* Description : Get Value of Specific Pin (High/Low)
*
************************************************************************/
uint8 DIO_ReadPin(uint8 PinNum){
						
    if( (PinNum >= Pin0) && (PinNum <= Pin7) ) /* Check If PinNum in PortA */
	{
	    return Get_Bit(PINA_REG,PinNum);  /* Return The Value of Pin (PinNum) From PinA Register*/
                                      /* Ex. PinNum = 2 ,Then Get The Value of Pin 2 From PinA Register */
    }
    else if( (PinNum >= Pin8) && (PinNum <= Pin15) ) /* Check If PinNum in PortB */
	{
	    return Get_Bit(PINB_REG,PinNum-Pin8); /* Return The Value of Pin (PinNum - 8) From PinB Register*/
                                          /* Ex. PinNum = 9 ,Then Get The Value of Pin 1 From PinB Register */
    }
    else if( (PinNum >= Pin16) && (PinNum <= Pin23) ) /* Check If PinNum in PortC */
	{
	    return Get_Bit(PINC_REG,PinNum-Pin16); /* Return The Value of Pin (PinNum - 16) From PinC Register*/
		                                   /* Ex. PinNum = 18 ,Then Get The Value of Pin 2 From PinC Register */
    }
    else if( (PinNum >= Pin24) && (PinNum <= Pin31) ) /* Check If PinNum in PortD */
    {
	    return Get_Bit(PIND_REG,PinNum-Pin24); /* Return The Value of Pin (PinNum - 23) From PinD Register*/
                                           /* Ex. PinNum = 26 ,Then Get The Value of Pin 3 From PinD Register */
    }
    else
	{
	     return ERROR_PIN_NUM ; /* PinNum Out Of Range ( 0 - 31 ) */
		 
    }
						
}




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
void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection){
						
    if( (PinNum >= Pin0) && (PinNum <= Pin7) ) /* Check If PinNum in PortA */
	{ 
        if(PinDirection == INPUT) /* Check If Pin Direction = Input */
		{
            Clear_Bit(DDRA_REG,PinNum); /* Clear Bit (PinNum) on DDRA Register  */
			                        /* Ex. PinNum = 2 ,Then Clear Bit 2 on DDRA Register */
        }
        else  /* Default State is Set Bit Direction to Output */
		{
            Set_Bit(DDRA_REG,PinNum);  /* Set Bit (PinNum) on DDRA Register  */
			                       /* Ex. PinNum = 5 ,Then Set Bit 5 on DDRA Register */
        }                          
    }
    else if( (PinNum >= Pin8) && (PinNum <= Pin15) ) /* Check If PinNum in PortB */
    {
        if(PinDirection == INPUT) /* Check If Pin Direction = Input */
        { 
            Clear_Bit(DDRB_REG,PinNum-Pin8); /* Clear Bit (PinNum - 8) on DDRB Register  */
        }                                /* Ex. PinNum = 9 ,Then Clear Bit 1 on DDRB Register */
        else /* Default State is Set Bit Direction to Output */
        {
            Set_Bit(DDRB_REG,PinNum-Pin8);  /* Set Bit (PinNum - 8) on DDRA Register  */
        }                               /* Ex. PinNum = 10 ,Then Set Bit 2 on DDRA Register */
    }
    else if( (PinNum >= Pin16) && (PinNum <= Pin23) ) /* Check If PinNum in PortC */
    { 
        if(PinDirection == INPUT) /* Check If Pin Direction = Input */
        {  
            Clear_Bit(DDRC_REG,PinNum-Pin16);/* Clear Bit (PinNum - 16) on DDRC Register  */
			                             /* Ex. PinNum = 17 ,Then Clear Bit 1 on DDRC Register */		
        }                                
        else /* Default State is Set Bit Direction to Output */
        { 
            Set_Bit(DDRC_REG,PinNum-Pin16);  /* Set Bit (PinNum - 16) on DDRC Register  */
        }                                /* Ex. PinNum = 18 ,Then Set Bit 2 on DDRC Register */
    }
    else if( (PinNum >= Pin24) && (PinNum <= Pin31) ) /* Check If PinNum in PortD */
    { 
        if(PinDirection == INPUT) /* Check If Pin Direction = Input */
		{  
            Clear_Bit(DDRD_REG,PinNum-Pin24); /* Clear Bit (PinNum - 24) on DDRD Register  */
        }                                 /* Ex. PinNum = 25 ,Then Clear Bit 1 on DDRD Register */
        else
        { /* Default State is Set Bit Direction to Output */
            Set_Bit(DDRD_REG,PinNum-Pin24);  /* Set Bit (PinNum - 24) on DDRA Register  */
        }                                /* Ex. PinNum = 26 ,Then Set Bit 2 on DDRA Register */
    }
    else
    {
       /* Do Nothing */
	   /* PinNum Out of Range ( 0 - 31 ) */
    }
														
														
}

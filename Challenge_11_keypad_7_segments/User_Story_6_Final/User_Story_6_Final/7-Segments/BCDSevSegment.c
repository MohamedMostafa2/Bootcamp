/*
 * BCDSevSegment.c
 *
 * Created: 2/18/2019 12:50:53 PM
 *  Author: AVE-LAP-049
 */ 

#include "../Includes/Types.h"
#include "../Includes/DIO/DIO.h"
#include "../Includes/DIO/BitwiseOperations.h"
#include "../Includes/7-Segments/BCDSevSegment.h"
#include "../Includes/7-Segments/BCDSevSegment_cfg.h"


void BCDSevegments_enable(uint8 SevenSegment_Number){
	
	DIO_WritePin(SevenSegment_Number,high);
	
}
void BCDSevegments_disable (uint8 SevenSegment_Number){
	
	DIO_WritePin(SevenSegment_Number,low);
}
void BCDSevegments_displayNo (uint8 Display_Number){
	
	switch(Display_Number){
		
		case 0: DIO_WritePin(SEV_SEGMENTS_DATA_PIN_0,low);
				DIO_WritePin(SEV_SEGMENTS_DATA_PIN_1,low);
				DIO_WritePin(SEV_SEGMENTS_DATA_PIN_2,low);
				DIO_WritePin(SEV_SEGMENTS_DATA_PIN_3,low);
			break;
		case 1:	DIO_WritePin(SEV_SEGMENTS_DATA_PIN_0,high);
				DIO_WritePin(SEV_SEGMENTS_DATA_PIN_1,low);
				DIO_WritePin(SEV_SEGMENTS_DATA_PIN_2,low);
				DIO_WritePin(SEV_SEGMENTS_DATA_PIN_3,low);
			break;
		case 2:	DIO_WritePin(SEV_SEGMENTS_DATA_PIN_0,low);
				DIO_WritePin(SEV_SEGMENTS_DATA_PIN_1,high);
				DIO_WritePin(SEV_SEGMENTS_DATA_PIN_2,low);
				DIO_WritePin(SEV_SEGMENTS_DATA_PIN_3,low);
			break;
		case 3:	DIO_WritePin(SEV_SEGMENTS_DATA_PIN_0,high);
				DIO_WritePin(SEV_SEGMENTS_DATA_PIN_1,high);
				DIO_WritePin(SEV_SEGMENTS_DATA_PIN_2,low);
				DIO_WritePin(SEV_SEGMENTS_DATA_PIN_3,low);
			break;
		case 4:	DIO_WritePin(SEV_SEGMENTS_DATA_PIN_0,low);
				DIO_WritePin(SEV_SEGMENTS_DATA_PIN_1,low);
				DIO_WritePin(SEV_SEGMENTS_DATA_PIN_2,high);
				DIO_WritePin(SEV_SEGMENTS_DATA_PIN_3,low);
			break;
		case 5:	DIO_WritePin(SEV_SEGMENTS_DATA_PIN_0,high);
				DIO_WritePin(SEV_SEGMENTS_DATA_PIN_1,low);
				DIO_WritePin(SEV_SEGMENTS_DATA_PIN_2,high);
				DIO_WritePin(SEV_SEGMENTS_DATA_PIN_3,low);
			break;
		case 6:	DIO_WritePin(SEV_SEGMENTS_DATA_PIN_0,low);
				DIO_WritePin(SEV_SEGMENTS_DATA_PIN_1,high);
				DIO_WritePin(SEV_SEGMENTS_DATA_PIN_2,high);
				DIO_WritePin(SEV_SEGMENTS_DATA_PIN_3,low);
			break;
		case 7:	DIO_WritePin(SEV_SEGMENTS_DATA_PIN_0,high);
				DIO_WritePin(SEV_SEGMENTS_DATA_PIN_1,high);
				DIO_WritePin(SEV_SEGMENTS_DATA_PIN_2,high);
				DIO_WritePin(SEV_SEGMENTS_DATA_PIN_3,low);
			break;
		case 8:	DIO_WritePin(SEV_SEGMENTS_DATA_PIN_0,low);
				DIO_WritePin(SEV_SEGMENTS_DATA_PIN_1,low);
				DIO_WritePin(SEV_SEGMENTS_DATA_PIN_2,low);
				DIO_WritePin(SEV_SEGMENTS_DATA_PIN_3,high);
			break;
		case 9:	DIO_WritePin(SEV_SEGMENTS_DATA_PIN_0,high);
				DIO_WritePin(SEV_SEGMENTS_DATA_PIN_1,low);
				DIO_WritePin(SEV_SEGMENTS_DATA_PIN_2,low);
				DIO_WritePin(SEV_SEGMENTS_DATA_PIN_3,high);
			break;
		default:break;	
	}
	
}
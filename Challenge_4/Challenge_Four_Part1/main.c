/*
 * AUTHOR: Ahmed Nofal, Avelabs Embedded R&D software team
 */
#include <stdio.h>
/* Complete the function below to detect the endianness of the machine*/

#define TEST_NUMBER 0xaabb
#define MSB_OF_TEST_NUMBER 0xaa

typedef unsigned short 	u16;
typedef unsigned char 	u8;

void Detect_Endianness(void){

	u16 num=TEST_NUMBER;

	u8 *p=&num; //point to first byte of TEST_NUMBER

	if(*p == MSB_OF_TEST_NUMBER)
	{
		printf("Big endian\n");
	}
	else{
		printf("Little endian\n");
	}
}

int main(void){
	Detect_Endianness();
}

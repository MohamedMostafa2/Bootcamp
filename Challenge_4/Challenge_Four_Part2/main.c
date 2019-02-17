/*
 * Author: Ahmed Nofal, Avelabs Embedded R&D software team
 */
#include <stdio.h>
#include <limits.h>
#define INT_MAX  2147483647
#define INT_MIN -2147483648
void Detect_Overflow(char operator, int x, int a){

	switch(operator){

	signed int num=0;

	case '+' : num = a + x;
		break;
	case '-' : num = a - x;
		break;
	case '*' : num = a * x;
		break;
	default : break;
	}



}
int main(void){
	int a1 = INT_MAX, b1 = 1; /* Overflow test for addition */
	int a2 = INT_MIN, b2 = -1; /* Underflow test for addition */
	int a3 = INT_MIN, b3 = INT_MIN - INT_MAX; /* Overflow test for subtraction */
	int a4 = INT_MIN - 10, b4 = INT_MIN; /* Underflow test for subtraction */
	int a5 = INT_MAX, b5 = INT_MAX;
	int a6 = INT_MIN, b6 = INT_MIN;
	Detect_Overflow('+',a1 ,b1);
	Detect_Overflow('+',a2 ,b2);
	Detect_Overflow('-',a3 ,b3);
	Detect_Overflow('-',a4 ,b4);
	Detect_Overflow('*',a5 ,b5);
	Detect_Overflow('*',a6 ,b6);

}

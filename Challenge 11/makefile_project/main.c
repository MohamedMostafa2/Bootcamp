#include <stdio.h>
#include "func1.h"
#include "func2.h"

//objdump -x main.o func1.o func2.o

int main(void){

	func1();
	func2();

	return 0;
}

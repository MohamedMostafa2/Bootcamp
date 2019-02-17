#include <stdio.h>

#define ARR_SIZE 12U

void main(void){
	int arr[ARR_SIZE] = {1, 55, 10, 23, 6, 12, 44, 2, 0, 15, 43, 7};
	int index;
	index=Linear_search_algo(arr, ARR_SIZE, 18);
	if(index == -1 ){
		printf("Target not found in the array\n");
	}
	else{
		printf("Target is found in the array at index %d\n", index);
	}
	Bubble_sort_algo(arr,ARR_SIZE);
	index = Binary_search_algo(arr,ARR_SIZE,18);
	if(index == -1 ){
		printf("Target not found in the array\n");
	}
	else{
		printf("Target is found in the array at index %d\n", index);
	}


}

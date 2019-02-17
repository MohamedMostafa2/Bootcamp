/*********************************************************************************
 *
 *  Selection_Sort.c
 *  Author: Mohamed Mostafa Abdel Karim
 *  		Mohamed Hassan
 *
 ********************************************************************************/


/****************************[Problem Description]*********************************
 *
 * As per explained algorithm, complete the below code to implement a fully
 * functional selection sort code
 *
 ********************************************************************************/
#include <stdio.h>
#include "Selection_Sort.h"


void selectionSort(int arr[], int arr_size)
{
	unsigned int i=0,j=0;
	int min=arr[0];
	int temp=0;
	for(i=0;i<arr_size-1;i++){
		for(j=i+1;j<arr_size;j++){
			if(arr[i] > arr[j]){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}

		}

	}
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* Driver program to test above functions */
int main()
{

    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}

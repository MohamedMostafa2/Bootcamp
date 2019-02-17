/*********************************************************************************
 *
 *  Bubble_Sort.c
 *  Author: Ahmed Nofal, Avelabs Embedded software R&D crew
 *
 ********************************************************************************/
/*#include <Bubble_Sort.h>*/
extern void Bubble_sort_algo(int arr[], int size);
/********************************************************************************
 *
Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.
Example:
First Pass:
( '5' '1' 4 2 8 ) –> ( '1' '5' 4 2 8 ), Here, algorithm compares the first two elements, and swaps since 5 > 1.
( 1 '5' '4' 2 8 ) –>  ( 1 '4' '5' 2 8 ), Swap since 5 > 4
( 1 4 '5' '2' 8 ) –>  ( 1 4 '2' '5' 8 ), Swap since 5 > 2
( 1 4 2 '5' '8' ) –> ( 1 4 2 '5' '8' ), Now, since these elements are already in order (8 > 5), algorithm does not swap them.

Second Pass:
( '1' '4' 2 5 8 ) –> ( '1' '4' 2 5 8 ), No swapping
( 1 '4' '2' 5 8 ) –> ( 1 '2' '4' 5 8 ), Swap since 4 > 2
( 1 2 '4' '5' 8 ) –> ( 1 2 '4' '5' 8 ), No swapping
( 1 2 4 '5' '8' ) –>  ( 1 2 4 '5' '8' ), No swapping
Now, the array is already sorted, but our algorithm does not know if it is completed. The algorithm needs
one whole pass without any swap to know it is sorted.

Third Pass:
( '1' '2' 4 5 8 ) –> ( '1' '2' 4 5 8 ), No swapping
( 1 '2' '4' 5 8 ) –> ( 1 '2' '4' 5 8 ), No swapping
( 1 2 '4' '5' 8 ) –> ( 1 2 '4' '5' 8 ), No swapping
( 1 2 4 '5' '8' ) –> ( 1 2 4 '5' '8' ), No swapping
 *******************************************************************************/
void Bubble_sort_algo(int arr[], int size){
	unsigned short i=0U,j=0U;
	int temp=0U;
	for(i = 0U;i < size ;i++){
		for(j=0 ; j < size-1  ; j++){

			if(arr[j] > arr[j+1] ){

				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
			else{}
		}

	}

}

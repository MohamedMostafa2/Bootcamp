/*********************************************************************************
 *
 *  Merge_Sort.c
 *  Author: Ahmed Nofal, Avelabs Embedded software R&D crew
 *
 ********************************************************************************/



/****************************[Problem Description]*********************************
 *
 * As per explained algorithm, complete the below code to implement a fully
 * functional merge sort code
 *
 ********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define max 1000 // assuming worest case is 1000

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int *arr, int left, int middle, int right)
{ 	int f2 = middle+1;
	int s1, s2, s3, k1, k2, k3;
	s1 = middle - left + 1;
	s2 = right - f2 + 1;
	s3 = s1 + s2;
	int temp[max];
	k1 = left; k2 = f2; k3 = 0;
while ((k1 <= middle) && (k2 <= right))
{
	if (arr[k1] < arr[k2]) { temp[k3] =
			arr[k1]; k1++; k3++; }
	else {
			temp[k3] = arr[k2]; k2++; k3++; }
}
while (k1 <= middle) temp[k3++] = arr[k1++];
while (k2 <= right) temp[k3++] = arr[k2++];
for (k3 = 0; k3 < s3; k3++)
arr[k3 + left] = temp[k3];


}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int *arr, int l, int r)
{
	int m;
	if (r > l)
	{
	m = (l + r) / 2;
	mergeSort(arr, l, m);
	mergeSort(arr, m + 1,r);

	 merge(arr, l, m, r);
	}
}


/* Driver program to test above functions */
int main(void)
{   int i;
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    printf("Given array is \n");
    for(i=0;i<arr_size;i++) printf("%d ",arr[i]);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    for(i=0;i<arr_size;i++) printf("%d ",arr[i]);
    return 0;
}

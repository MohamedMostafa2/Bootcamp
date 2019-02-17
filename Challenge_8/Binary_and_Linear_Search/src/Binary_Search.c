/*********************************************************************************
 *
 *  Binary_Search.c
 *  Author: Ahmed Nofal, Avelabs Embedded software R&D crew
 *
 ********************************************************************************/



/****************************[Problem Description]*********************************
 *
 * Binary search is one of the best searching algorithms. Binary search algorithm
 * works as follows:
 * Assume having a sorted array arr = [1, 2, 3, 4, 5, 6, 7] and you want to search
 * for the number "2" the algorithm starts by comparing your target number "2" to
 * the middle number in the array which is "4" if this is the desired number then
 * return the index of it, if not, is 2 greater than 4 ? no then is it less than 4?
 * Yes, then start looking in the sub array starting from the first element in the
 * array to the elment right before the middle element "4", i.e (1..arr[mid-1]).
 * Get the middle element in this sub-array and compare it to 2, is 2 equal to 2?
 * Yes then return the index of it.
 * As we can see Binary search found this number in 2 iterations only.
 *
 *Notice:: if you try searching for the element "6" you will reach it in only two
 *		   iterations
 ********************************************************************************/
#include <stdio.h>
#include "Binary_Search.h"
#include "Bubble_Sort.h"

#define ARR_SIZE 12

int Linear_search_algo(int arr[], int arr_size, int target){
	unsigned short i=0U;
	for(i=0U;i<arr_size;i++){
		if(arr[i]==target){
			return i;
		}
	}
	return -1;
}
int Binary_search_algo(int arr[], int arr_size, int target){
	unsigned short i = 0;
	unsigned short first = 0;
	unsigned short last  = arr_size-1U;
	unsigned short med   = ((last-first)+!((last-first)%2))/2U;

	while((first <= last)){

		if(arr[med] == target){
			return med;
		}
		else if(target > arr[med]){
			first=med+1;
			med = (((last-first)+!((last-first)%2))/2U)+first;
		}
		else{
			last=med-1;
			med = (((last-first)+!((last-first)%2))/2U)+first;
		}
	}

	return -1;

}


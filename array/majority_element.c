#include "array.h"

/*
 * majority_element.c
 * CTCI 6 17.10 | LeetCode Medium
 *
 * Given a positive integers array, find the majority element.
 * A majority element is that element which appears more then half the size of the array.
 */
/** Algorithm:
 * 1. Find the candidate element for the majority element.
 * 2. Check if it is majority element.
 */

int check_for_majority(int *A, int size, int maj);
int majority_element(int *A, int size){
	int majority = 0;
	int count = 0;

	for(int i = 0; i< size; i++){
		// If count is 0, then set this element as the majority
		if(count == 0){
			majority = A[i];
			count = 1;
			continue;
		}
		// else if the current element is a majority element
		else {
			if (A[i] == majority)
				count++ ;
			else
				count-- ;
		}
	}

	int res = check_for_majority(A, size, majority);
	printf("Majority element = %d\n", res);
	return res;
}

int check_for_majority(int *A, int size, int maj){
	int count = 0;
	for(int i = 0; i<size; i++){
		if(A[i] == maj){
			count++;
		}
	}

	if(count >= size/2)
		return maj;
	else
		return -1;

}

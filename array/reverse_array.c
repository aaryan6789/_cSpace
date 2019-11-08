/*
 * reverse_array.c * Created on: Apr 14, 2018 * Author: hsahu
 */

#include "array.h"

/**
 * reverse_array: reverse an array
 * @A:	Input array
 * @n:	size of the array
 *
 * A 	= 1 3 4 9 2
 * rA 	= 2 9 4 3 1
 */
void reverse_array(int A[], int n){
	printf("\nReversing array now\n");
	int start, end;
	//int temp;

	start = 0;
	end = n-1;

	while (start <= end){
		swap(&A[start], &A[end]);
		start++;
		end--;
	}
}



/**
 * rotate_array - rotate an array by d elements
 */
// void rotate_array(int *A, int size, int d){
// 	printf("Rotating the array... \n");

// 	// By Reversal Algorithm
// 	reverse_array(A, 0, d);
// 	reverse_array(A, d+1, size);
// 	reverse_array(A, 1, size);
// }

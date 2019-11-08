/*
 * pair_sum_close_to_0.c
 *
 *  Created on: Apr 20, 2018
 *      Author: hsahu
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include "array.h"


int compare1(const void *a, const void *b){
	return (*(int*)a - *(int*)b);
}
void sum_close_to_zero(int *A, int size){
	int l, r, sum;

	int minSum = INT_MAX;			// <--- Pay Attention Here
	int min_left, min_right;
	l = 0;
	r = size-1;

	qsort(A, size, sizeof(int), compare1);
	printArray(A, size);
	printf("\n");

	while(l < r){
		sum = A[l] + A[r];
		printf("Sum = %d abs(sum) = %d minSum=%d\n ", sum, abs(sum), minSum);

		if(abs(sum) <= abs(minSum)){				//<----- Pay attention here
			//printf("l = %d r = %d\n", l, r);
			minSum = sum;
			min_left = l;
			min_right = r;
		}

		if(sum<0){
			l++;
		}
		else{
			r--;
		}
	}

	printf("The 2 elements with sum closest to 0 is %d with %d and %d at index %d %d",
			minSum, A[min_left], A[min_right], min_left, min_right);

}

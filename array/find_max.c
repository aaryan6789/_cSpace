/*
 * find_max.c
 *
 *  Created on: Apr 14, 2018
 *      Author: hsahu
 */
#include <stdio.h>
#include <stdlib.h>
#include "array.h"

/**
 * find_max_in_array - find maximum element in the array.
 * 1. By index
 * 2. By pointers
 * @IP: array A[], size of the array
 */
void find_max_in_array(int *A, int length){
	int i, max, location = 0;

	max = A[0];
	for(i = 0; i<length; i++){
		if (A[i] > max) {
			max = A[i];
			location = i;
		}
	}
	printf("%s: The maximum element is %d at location %d\n",
			__FUNCTION__, max, location);
}

#include <stdio.h>
#include <stdlib.h>
#include "array.h"

/**
 * segregate_0_1
 * Given an array with 0s and 1s in random order.
 * Segregate 0s on the left side and 1s on the right side.
 *
 * Algorithm:
 * 1. Use 2 indexes : left and right, left = 0, right = size-1
 * 2. while left <= right
 * a) keep incrementing left if A[left] is 0.
 * b) keep decrementing right, if A[right] is 1
 * c) Now left index has a 1 and right index has 0.
 *    Swap them and increment left and decrement right by 1.
 *
 * Time Complexity = O(n), O(1) space complexity for temp variable.
 */
void segregate_0_1(int A[], int size) {
	int left = 0;
	int right = size-1;
	//int count = 1;

	while(left <= right) {
		while ((A[left] == 0) && left < right)
			left++;

		while ((A[right] == 1) && left < right)
			right--;

		// Here: left index has a 1 and right index has a 0
		if(left <= right) {							//<-- Pay attention here
			swap(&A[left], &A[right]);
			left++;
			right--;
		}
	}
}


/**
 * segregate_even_odd
 * Given an array with 0s and 1s in random order.
 * Segregate 0s on the left side and 1s on the right side.
 */
void segregate_even_odd(int A[], int size) {
	int left = 0;
	int right = size-1;

	while(left <= right) {
		while ((A[left]%2 == 0) && left < right)
			left++;

		while ((A[right]%2 == 1) && left < right)
			right--;

		if(left <= right) {
			swap(&A[left], &A[right]);
			left++;
			right--;
		}
	}
}

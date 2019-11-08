#include "array.h"

/*
 * sorted_merge.c

 * Given 2 sorted arrays A and B. A has large enough buffer in the end to hold B.
 * Merge B and A in sorted order.
 */
void sorted_merge(int *A, int *B, int sizeA, int sizeB){
	// Since A has large enough memory to keep B in it.
	// Also both the arrays are also individually sorted.
	// So all we have to do is compare the individual values and put them in A.
	// Bit to do this we should start from the back of A as then we dont have to
	// move the elements already in A.

	// Last indexes of arrays A and B
	int lastA = sizeA-1;
	int lastB = sizeB-1;
	int mergedIndex = sizeA + sizeB -1;

	while (lastB >= 0){
		if (lastA >= 0 && A[lastA] > B[lastB]){
			A[mergedIndex] = A[lastA];
			lastA--;
		}
		else{
			A[mergedIndex] = B[lastB];
			lastB--;
		}

		mergedIndex--;	// move indices for the resulting array
	}
	return;
}

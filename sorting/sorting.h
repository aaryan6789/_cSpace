/*
 * sorting.h
 *
 * Contains the Helper functions for Sorting.c
 */

#ifndef SORTING_H_
#define SORTING_H_

//Print Array
void printArray (int arr[], int n) {
	int i;

	printf("\nArray : ");
	for(i=0; i<n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

// Swap
void swap(int *a, int *b){
	//printf("\nSwap\n");
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

#endif /* SORTING_H_ */

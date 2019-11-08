// Sorting Algorithms

#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

/*  TODO:
 *  Insertion Sort
 *  arr[] 	- Unsorted I/P array
 *  n 		- size of the array
 *
 *  Sorting the array in increasing order.
 */
void insertionSort (int arr[], int n) {
	printf("\nInsertion Sort\n");

	int i,j;
	int element;

	for (i = 1; i < (n-1); i++) {
		element = arr[i];
		printf("\ni:%d element: %d \n", i, element);
		j = i;

		while (j>0 && arr[j-1]>element) {
			arr[j] = arr[j-1];
			j = j-1 ;
		}
		arr[j] = element;
		printf("j:%d element: %d \n", j, element);
	}
}

/*
 * Selection Sort
 */
void selectionSort(int arr[], int n){
	printf("\n\n ---- Selection Sort ----");

	int i, j, min;

	for (i=0; i<(n-1); i++) {
		min = i;
		for(j=i+1; j<n; j++){
			if (arr[j] < arr[min]){
				min = j;
			}
		}
		swap(&arr[min], &arr[i]);
	}
}

/**
 * mergeSort - MergeSort
 * Divide and Conquer Algorithm
 * RECURSIVE
 * Divides AN UN-Sorted array into 2 Sorted Arrays
 * Merges the 2 Sorted array to make final Sorted Array
 * Needs extra space for this algorithm - How much?
 *
 *
 * TODO:
 * mergeSort ---- Organization of the algorithm
 * merge ---- where all the action happens
 *
 * merge
 * -- Divide the arrays
 * -- Merge the array by comparing the elements
 *
 * e.g =
 * 1 Unsorted: 5 3 8 1
 * 2 UnSorted Array : 5 3 and 8 1
 * 2 Sorted Arrays : 5 and 3 && 8 and 1
 *
 * @arr[] : unsorted array
 * @start : first index of the unsorted array
 * @end: last index of the array
 * @mid : middle element of the array
 */
void mergeSort(int arr[], int start, int end);
void merge(int arr[], int start, int mid, int end);

void mergeSort(int arr[], int start, int end){
	int mid;
	mid = start + (end - start)/2;

	if (start < end){
		mergeSort(arr, start, mid);
		mergeSort(arr, mid+1, end);

		merge(arr, start, mid, end);
	}
}

void merge (int arr[], int start, int mid, int end) {
	int i, j, k;
	int nl = mid - start + 1;
	int nr = end - mid ;

	// Create temporary Arrays
	int L[nl];
	int R[nr];

	// Populate the arrays from unsorted arrays
	for (int i = 0; i<nl; i++)
		L[i] = arr[start + i];

	for (int i=0; i<nr; i++)
		R[i] = arr[mid+1 + i];

	// Merge
	i = 0; 	j = 0;
	k = start;

	while (i<nl && j<nr){
		if (L[i] < R[j]){
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i<nl){
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j<nr){
		arr[k] = R[j];
		j++;
		k++;
	}
}

// QuickSort

int _partition(int arr[], int start, int end){
	int pIndex = start;
	int pivot = arr[end];

	for(int i=start; i<end; i++){
		if(arr[i]<=pivot){
			swap(&arr[i], &arr[pIndex]);
			pIndex = pIndex+1;
		}
	}
	swap(&arr[pIndex], &arr[end]);
	printf("pIndex : %d \n", pIndex);
	return pIndex;
}

void quicksort(int arr[], int start, int end){
	if (start < end){			//<----- Pay attention here, not while its if
		int pIndex = _partition(arr, start, end);
		quicksort(arr, start, pIndex-1);		//<----- Pay attention, its pIndex-1
		quicksort(arr, pIndex, end);
	}
}

int main () {
	int n;
	int A[] = {5, 10,999, -2, 1, 3, 2, 4, -1000 };

	n = sizeof(A)/sizeof(A[0]);
	printf("Size of Array: %d\n", n);

	printArray(A, n);
	//insertionSort(A, n);
	//selectionSort(A, n);
	quicksort(A, 0, (n-1));
	//printf("\n\n---- MergeSort ----");
	//mergeSort(A, 0, (n-1));
	printArray(A, n);

	return 0;
}

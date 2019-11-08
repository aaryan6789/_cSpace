/* find_peak.c | Created on: Apr 14, 2018 | Author: hsahu */
#include <stdio.h>
#include <stdlib.h>
#include "array.h"
/**
 * CTCI
 * find_peak_in_array - find the peak element in an array
 * Peak Element is that element in the array which is larger than its neighbors
 * A[] = 1 3 4 2 5
 * Peak element = 4
 *
 * Algorithm:
 * 1. Linear Search
 * Iterate through the array and check if the index +1 and index-1 is smaller then this index element.
 * Time Complexity:  O(n)
 *
 */

void find_peak_in_array(int *A, int length){
	// HINT: The array is unsorted.
	int i;

	for(i = 0; i<length; i++) {
		if (A[i]>A[i+1] && A[i] > A[i-1]){
			printf("%s: Peak Element in the Array: %d\n",__FUNCTION__, A[i]);
		}
	}
}

/** 2. Binary Search

 * ii) Use binary search and find the peak.
 * -- For peak , binary Search condition would be:
 * 1. if A[mid] > A[mid+1] && A[mid] > A[mid-1]
 * 2. Boundary Conditions:
 * a) start, if mid == start && A[mid]>A[mid+1]
 * b) end, if mid == end && A[mid] > A[mid-1]
 *
 *
 * Time Complexity = O(nlogn)
*/

// A binary search based function that returns index of a peak element
int findPeakUtil(int arr[], int low, int high, int n)
{
    // Find index of middle element
    int mid = low + (high - low)/2;  /* (low + high)/2 */

    // Compare middle element with its neighbours (if neighbours exist)
    if ((mid == 0 || arr[mid-1] <= arr[mid]) &&
            (mid == n-1 || arr[mid+1] <= arr[mid]))
        return mid;

    // If middle element is not peak and its left neighbour is greater
    // than it, then left half must have a peak element
    else if (mid > 0 && arr[mid-1] > arr[mid])
        return findPeakUtil(arr, low, (mid -1), n);

    // If middle element is not peak and its right neighbour is greater
    // than it, then right half must have a peak element
    else return findPeakUtil(arr, (mid + 1), high, n);
}

// A wrapper over recursive function findPeakUtil()
int findPeak(int arr[], int n)
{
    return findPeakUtil(arr, 0, n-1, n);
}

// NIO
// A binary search based function that returns
// index of a local minima.
int localMinUtil(int arr[], int low, int high, int n)
{
    // Find index of middle element
    int mid = low + (high - low)/2;  /* (low + high)/2 */

    // Compare middle element with its neighbours
    // (if neighbours exist)
    if ((mid == 0 || arr[mid-1] > arr[mid]) &&
            (mid == n-1 || arr[mid+1] > arr[mid]))
        return mid;

    // If middle element is not minima and its left
    // neighbour is smaller than it, then left half
    // must have a local minima.
    else if (mid > 0 && arr[mid-1] < arr[mid])
        return localMinUtil(arr, low, (mid -1), n);

    // If middle element is not minima and its right
    // neighbour is smaller than it, then right half
    // must have a local minima.
    return localMinUtil(arr, (mid + 1), high, n);
}

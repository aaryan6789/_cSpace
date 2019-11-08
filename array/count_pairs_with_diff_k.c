
/* count_pairs_with_diff_k.c *  Created on: Apr 20, 2018 * Author: hsahu */
#include <stdio.h>
#include <stdlib.h>
#include "array.h"

/**
 * Given an array and a +ve integer K.
 * Count all the distinct pairs with difference "K".
 */

/* Best
 * Method 3 : Using Sorting and 2 index variables
 *  1. Sort the array.
 *  2. Take two variables, l and r, both pointing to 1st element
 *  3. Take the difference A[r] � A[l]
	- If value diff is K,
			increment count and
			move both pointers to next element
	- if value diff > k,
			move l to next element
	- if value diff < k,
			move r to next element
 *	4. Return count
 *
 *	Time Complexity: O(nlogn) + O(n) for Sorting
 */
int compare(const void *a, const void *b){
	return (*(int*)a - *(int*)b);
}

/* Returns count of pairs with difference k in arr[] of size n. */
int countPairsWithDiffK(int arr[], int size, int k) {
    int count = 0;
    qsort(arr, size, sizeof(int), compare);  // Sort array elements

    printArray(arr, size);
    int l = 0;
    int r = 0;
    while(r < size) {
    	// If difference found, then increment count, l and r all
    	if(arr[r] - arr[l] == k) {
    		count++;
            l++;
            r++;
        }
    	else if(arr[r] - arr[l] > k)
    		l++;
    	else // arr[r] - arr[l] < k
    		r++;
    }
    printf("\n kCount = %d\n", count);
    return count;
}

/* Method 2: Sorting and Searching
 *
 * 1. Initialize count as 0
 * 2. Sort all numbers in Increasing order.
 * 3. Remove Duplicates from the Array
 * 4. For each element in the array: A[i]
 * 		- Binary Search for (A[i] + k) element in subarray (i+1, size-1);
 * 		- If found then increment count
 * 5. Return Count.
 *
 * Time Complexity = O(nlogn) + n * O(logn)
 * Overall time complexity is O(nLogn).
 */

/**
 * Method 1 : Two Loops Method
 * 1. Consider all pairs one by one and check the difference
 * 2. Use 2 loops and
 * In Outer Loop pick one element from the Array one by one.
 * In Inner Loop pick the element from the rest of the forward array one by one
 * and check for difference.
 * 3. If difference found then increase count.
 *
 * Time Complexity : O(n2)
 * Note:
 * This Solution wont work for Duplicate Values as it is not keeping a check on
 * seen values and not seen values.
 */
void countPairs(int *A, int size, int k){
	int count = 0;

	for(int i = 0; i<size; i++){
		for(int j = i+1; j<size; j++){
			if ((A[i] - A[j] == k) || (A[j] - A[i] == k)){
				count++;
			}
		}
	}

	printf("Count Pairs with difference %d = %d\n", k, count);
	return;

}

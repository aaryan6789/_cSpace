/* find_duplicate.c * Created on: Apr 14, 2018 | Author: hsahu */
#include "array.h"
#include <stdlib.h>
#include <string.h>

/* LEETCODE M
 * Given an array nums containing n + 1 integers where each integer is
 * between 1 and n (inclusive), prove that at least one duplicate number
 * must exist. Assume that there is only one duplicate number,
 * find the duplicate one.
 *
 * Note:
 * - You must not modify the array (assume the array is read only).
 * - You must use only constant, O(1) extra space.
 * - Your runtime complexity should be less than O(n2).
 * - There is only one duplicate number in the array,
 * 	but it could be repeated more than once.
 **/

int findMax(int *A, int size){
	int max = A[0];
	for(int i = 1; i<size; i++){
		if(A[i] > max){
			max = A[i];
		}
	}

	// If max is less then the Size of the array.
    if(max < size){
        max = size;
        return max;
    }
    else {
        return max;
    }

}

int findDuplicate(int* A, int size) {
    // Create a Hash Table of size "size" as the numbers in the Array are
	// in the range 1 to size

	int max = findMax(A, size);
    printf("Size of Hash = %d\n", max);

    int hash[max+1];
    memset(hash, 0, max*sizeof(int));	// Initialize to all 0s

    int dup;

    for(int i = 0; i<size; i++){		// Populate the hash table with the entries
        hash[A[i]]++;
    }

    for(int i = 0; i<size; i++){
        if(hash[i] > 1){
            printf("i = %d %d\n", i, hash[i]);
            dup = i;
        }
    }

    printf("%s: Duplicate Value is %d\n", __FUNCTION__, dup);
    return dup;
}

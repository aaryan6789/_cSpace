/**
 * LeetCode Hard 41
 * Find the smallest positive number missing from an unsorted
 *
 * You are given an unsorted array with both positive and negative elements.
 * You have to find the smallest positive number missing from the array in O(n)
 * time using constant extra space.
 * You can modify the original array.
 *
 * Examples
   Input:  {2, 3, 7, 6, 8, -1, -10, 15}
   Output: 1

   Input:  { 2, 3, -7, 6, 8, 1, -10, 15 }
   Output: 4

   Input: {1, 1, 0, -1, -2}
   Output: 2
 */
#include "array.h"
/**
 * Using Hash Map - O(n) Time and O(N) Space
 * - Build a hash table of all positive elements in the given array.
 * - Once the hash table is built. We can look in the hash table for all positive integers,
 *  starting from 1.
 * - As soon as we find a number which is not there in hash table, we return it.
 * - This approach may take O(n) time on average, but it requires O(n) extra space.
 */
int firstMissingPositive_Hashmap(int* nums, int numsSize) {
    int *hash = calloc((numsSize + 2), sizeof(int));
    int i = 0;
    while(i < numsSize){
        if(nums[i] <= numsSize && nums[i] > 0){
            hash[nums[i]] = 1;
        }
        i++;
    }
    i = 1;
    while(i < numsSize + 2){
        if(hash[i] == 0)
            return i;
        i++;
    }
    return 1;
}

/**
 * Using Cyclic Sort Pattern:
 * O(n) and O(1) Space Complexity
 */

int firstMissingPositive(int* A, int ASize) {
    // Parse through the array
    // If value is negative or greater than array size, then it cannot be marked in array.
    // So move to next element.
    // If the item is positive then swap it with its index i.e put number in its
    // right place, E.g 1 should be in A[0], 2 in A[1], so on..
    for (int i = 0; i < ASize; i++) {
        while ((A[i] > 0) && (A[i] <= ASize) && (A[i] != A[A[i] - 1])) {
            swap(&A[i], &A[A[i] - 1]);
        }
    }

    //find missing number ad return early
    for (int i = 0; i < ASize; i++) {
        if (A[i] != i + 1)
            return i+1;
    }

    return ASize + 1;
}


void swap2(int* nums, int j, int k) {
    int tmp = nums[k];
    nums[k] = nums[j];
    nums[j] = tmp;
}

int firstMissingPositive2(int* nums, int numsSize) {
    int i = 0;
    int p = numsSize;

    while (i < p) {
        if (nums[i] == i+1)
            ++i; // already in the right place,
        else if (nums[i] <= 0 || nums[i] > p || nums[i] == nums[nums[i]-1]) {
            swap2(nums, i, --p); // out of range or duplicate, put it at the end
        } else {
            swap2(nums, i, nums[i]-1); // within range; put it in the right place.
        }
    }

    return p + 1;
}
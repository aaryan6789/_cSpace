/* dominant_index.c * Created on: Apr 21, 2018 * Author: hsahu */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * LEETCODE | E | Google
 * Dominant Index
 * In a given integer array nums, there is always exactly one largest element.
 *
 * Find whether the largest element in the array is at
 * least twice as much as every other number in the array.
 *
 * If it is, return the index of the largest element, otherwise return -1.
 *
 * Example 1:
 * Input: nums = [3, 6, 1, 0]
 * Output: 1
 *
 * Explanation: 6 is the largest integer,
 * and for every other number in the array x,
 * 6 is more than twice as big as x.
 *
 * The index of value 6 is 1, so we return 1.
 *
 * Example 2:
 * Input: nums = [1, 2, 3, 4]
 * Output: -1
 *
 * Explanation:
 * 4 isn't at least as big as twice the value of 3, so we return -1.
 *
 * Note:
 * nums will have a length in the range [1, 50].
 * Every nums[i] will be an integer in the range [0, 99].
 **/

int dominantIndex(int* A, int size) {
    int max = INT_MIN;
    int max_index;
    for(int i = 0; i< size; i++){
        if(A[i] > max){
            max = A[i];
            max_index = i;
        }
    }
    // for(int i = 0; i < size; i++){
    //     if( i != max_index && A[i] > max/2){
    //         return -1;
    //     }
    // }

    printf("%s : Largest element in the array is = %d at %d\n",
            __FUNCTION__, max, max_index);

    return max_index;

}

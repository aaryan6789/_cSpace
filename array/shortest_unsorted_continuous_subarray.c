/*
 * shortest_unsorted_continuous_subarray.c  * Created on: Apr 21, 2018 * Author: hsahu
 */
#include "array.h"

/* Leetcode Easy
 * Given an integer array,
 * you need to find one continuous subarray that if you only
 * sort this subarray in ascending order, then the whole array
 * will be sorted in ascending order, too.
 *
 * You need to find the shortest such subarray and output its length.
 *
 * Example 1:
 * Input: [2, 6, 4, 8, 10, 9, 15]
 * Output: 5
 *
 * Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order
 * to make the whole array sorted in ascending order.
 *
 **/

#define max(x,y) (((x) > (y)) ? (x) : (y))
#define min(x,y) (((x) < (y)) ? (x) : (y))

int findUnsortedSubarray(int* A, int size) {
    int l = size, r = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (A[j] < A[i]) {
                r = max(r, j);
                l = min(l, i);
            }
        }
    }

    return r - l < 0 ? 0 : r - l + 1;

}

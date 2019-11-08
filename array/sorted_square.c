#include "array.h"
/**
 * Given an array of integers A sorted in non-decreasing order, return an array
 * of the squares of each number, also in sorted non-decreasing order.

Example 1:
Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]

Example 2:
Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]

Note:
1.  1 <= A.length <= 10000
2.  -10000 <= A[i] <= 10000
3. A is sorted in non-decreasing order.
 */

/**
 * Algorithm:
 * -- Same concept as MergeSort
 * 2 pointer solution
 *      i --> set to first index
 *      j --> Set to last index
 * Compare the values of the 2 numbers and then start filling the result array
 * from behind.
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* A, int ASize, int* returnSize){
    if (A == NULL || ASize <= 0)
        return NULL;

    // Dynamically created array for result
    int *ret = (int *)malloc(sizeof(int) * ASize);

    int i = 0;
    int j = ASize - 1;
    int k = ASize - 1;

    while (i <= j) {
        if (abs(A[i]) <= abs(A[j])) {
            ret[k--] = A[j] * A[j];
            j--;
        }
        else {
            ret[k--] = A[i] * A[i];
            i++;
        }
    }

    *returnSize = ASize;
    return ret;
}
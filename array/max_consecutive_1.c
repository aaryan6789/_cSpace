#include "array.h"
/**
 * max_consecutive_1.c
 *
 * LeetCode E
 * Given a binary array,
 * find the maximum number of consecutive 1s in this array.
 */

int findMaxConsecutiveOnes(int* A, int size) {
    int maxCount = 0;
    int count = 0;

    for(int i = 0; i< size; i++){
        if(A[i] == 0){
            count = 0;
        }
        else if(A[i] == 1){
            count++;
        }

        if(count > maxCount){
            maxCount = count;
        }
    }
    printf("MaX Count of 1's = %d\n", maxCount);
    return maxCount;
}

// LeetCode M
// CTCI Flip Bit to Win
// Given a binary array,
// find the maximum number of consecutive 1s in this array if you can flip at most one 0.

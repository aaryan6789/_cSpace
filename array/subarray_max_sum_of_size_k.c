#include "array.h"
/**
 * LeetCode Easy
 *
 * Find maximum (or minimum) sum of a subarray of size k

Given an array of integers and a number k, find maximum sum of a subarray of size k.

Examples :
Input  : arr[] = {100, 200, 300, 400}
         k = 2
Output : 700

Input  : arr[] = {1, 4, 2, 10, 23, 3, 1, 0, 20}
         k = 4
Output : 39
We get maximum sum by adding subarray {4, 2, 10, 23} of size 4.

Input  : arr[] = {2, 3}
         k = 3
Output : Invalid
There is no subarray of size 3 as size of whole array is 2.
 */

/**
 * Solutions:
 * 1. Sliding Window
 *
 */

int subarray_max_sum_size_k(int *A, int sizeA, int k){
    printf("\n-------- %s -------- \n", __func__);
    if(k >= sizeA || k < 0){
        return 0;
    }
    else if( k == sizeA){
        int sum;
        for(int i = 0; i< sizeA; i++){
            sum += A[i];
        }
        printf("Sum = %d\n", sum);
        return sum;
    }

    // Get the first K sum
    int sumK = 0;
    for (int i = 0; i< k; i++){
        sumK += A[i];
    }

    int maxSum = sumK;
    int sumCurr = 0;
    for (int i = k; i< sizeA; i++){
        sumCurr = sumK + A[i] - A[i-k];
        if(sumCurr > maxSum){
            maxSum = sumCurr;
        }
    }

    printf("Max Sum = %d\n", maxSum);
    return maxSum;
}
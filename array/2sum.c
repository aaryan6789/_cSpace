/* 2sum.c | Created on: Apr 10, 2018 | Author: hsahu */

// Array of Integer , target,
// Algorithm:
// Input:
// 1. Array is Unsorted
// 2. All the pairs of the target
//
// Method1:
// 1. Iterate throught he aray, for each figure out (target -element)
// O(n2)

// 1. Sort this array
// 2. 2 variables start, end
// 3. Sum = A[Start] + A[end
// if sum == target, resturn the pair, and start++ and end--
// if not , sum<target then start ++ else end --

#include <stdlib.h>
#include <stdio.h>
#include "array.h"

void printArray(int *A, int size){
    printf(" Array = ");
    for(int i = 0; i< size; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    return;
}


int *two_pair_sum(int *A, int size, int target){
    int *result = NULL;
    result = (int*)malloc(size * sizeof(int));

    // Sort this array
    // qsort(A, size, sizeof(A[0]), cmp);

    // Here the array is sorted, Find the pairs
    int start = 0;
    int end = size-1;
    int sum;
    int k = -1;

    while(start < end){
        sum = A[start] + A[end];

        if(sum == target){
            printf("Pair Found with %d, %d\n", A[start], A[end]);
            result[++k] = A[start++];           //<--- Pay attention Here start++ and end--
            result[++k] = A[end--];
        }
        else if(sum < target){
            start++;
        }
        else{
            end--;
        }
    }

    if(k){
        printArray(result, size);
        return result;
    }
    else{
        printf("No Pairs found\n");
        return NULL;
    }
}

void two_pair_sum_print(int *A, int size, int target){
    int *result = NULL;
    result = (int*)malloc(size * sizeof(int));

    // Sort this array
    //qsort(A, size, sizeof(A[0]));

    // Here the array is sorted, Find the pairs
    int start = 0;
    int end = size-1;
    int sum;
    int k = -1;

    while(start < end){
        sum = A[start] + A[end];

        if(sum == target){
            printf("%s: Pair Found with %d, %d\n", __FUNCTION__, A[start], A[end]);
            result[++k] = A[start++];
            result[++k] = A[end--];
        }
        else if(sum < target){
            start++;
        }
        else{
            end--;
        }
    }

    if(k){
        printArray(result, size);
        return;
    }
    else{
        printf("No Pairs found\n");
        return;
    }
}

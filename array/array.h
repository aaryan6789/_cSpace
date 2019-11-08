#ifndef ARRAY_H_
#define ARRAY_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <math.h>
#include <limits.h>

/*
1. Insert in an array.
2. Delete from an array.
3. Print an array
4. Rotate an array
5. Find the maximum element in the array.
6. I/P = 1 2 3 4
   O/P = 2*3*4 1*3*4 1*2*4 1*2*3
8. How to access array elements without using index and pointer increment variable?
9. How do you remove the duplicates from an Array? - C and Perl
10. Insert and Delete in array
11. Maximum element in an array
12. Peak element in an array (Peak element is larger than its neighbors)
13. Minimum element in Sorted and Rotated Array
14. Leaders in an array (An element is a leader if it is greater than the elements to its right)
15. Merge an array of Size N into another array if Size M+N
16. Count inversions in an array (Inversion Count indicates that how far the array is from being sorted)
17. Rotate an array
18. Reverse an array
19. Find 2 elements in an array whose SUM is closest to ZERO.
20. Search an element in a SORTED AND ROTATED Array
21. Count the number of occurences of an element in a SORTED Array
22. Find the REPEATING elements in an array
23. Array SUBSET of another array
	Given 2 arrays A1, A2, find whether A2 is a Subset of A1 or not.
	Both the arrays are not in Sorted order.
24. UNION and INTERSECTION OF 2 SORTED Arrays
25. Given an Unsorted array, Find 2 numbers occuring odd number of times.
26. Remove the duplicates from an array.
27. Find the minimum element in a Sorted rotated array.
28. Rearrange an array so that arr[i] becomes arr[arr[i]].
	In O(1) extra space.
29. Move all the 0's to the end of the array.
30. Count all distinct pairs in an array with difference K.
31. Find the maximum repeating element in an array.
32. Rearrange +ve and -ve elements alternately.

 */


void two_pair_sum_print(int *A, int size, int target);
void swap(int *a, int *b);
void segregate_0_1(int A[], int size);
void segregate_even_odd(int A[], int size);
void printArray(int *A, int size);

void sorted_merge(int *A, int *B, int sizeA, int sizeB);

void regarrange_pos_neg(int* A, int size);
void push_zero_to_end(int *A, int size);

int maxProfit(int* stock, int size);
int max_profit_many(int *prices, int length);
int missingNumber(int* A, int size);
int findDuplicate(int* A, int size);
void check_duplicates_bitArray(int * arr, int size);
void find_peak_in_array(int *A, int length);
void find_max_in_array(int *A, int length);
// void odd_occurence_of_number(int *A, int size);

int* plusOne(int* digits, int digitsSize, int* returnSize);
int check_zero_subarray(int* A, int size);
void countPairs(int *A, int size, int k);
int countPairsWithDiffK(int arr[], int n, int k);
void sum_close_to_zero(int *A, int size);
int largest_zero_subarray(int *A, int size);
int dominantIndex(int* A, int size);
double findMaxAverage(int* A, int size, int k);
double findMaxAverage2(int* A, int size, int k);
void thirdLargest(int arr[], int arr_size);


int removeDuplicates(int A[], int n);

#define bool int
int checkPossibility1(int* nums, int numsSize);
bool checkPossibility(int* nums, int numsSize);
bool checkPossibility3(int* nums, int numsSize);

/** Practice */
void twoSumP(int* A, int size, int val);
void removeDuplicatesSortedArrayP(int* A, int size);
void rearrangePosNegP(int* A, int size);


void peaks_and_valleys(int* A, int size);

#endif /* ARRAY_H_ */

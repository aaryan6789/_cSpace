#include <stdlib.h>
#include <stdio.h>

/*
 * find_repeating_1.c
 * LeetCode Medium, CTCI Medium
 * Given an Array of n+2 numbers.
 * All elements in the array are in the range 1 to n.
 * All elements occur in the element once but 2 numbers.
 * Find the 2 repeating numbers.
 */

/* Algorithm 1 :
 * Two Loop method: O(n2)
 *
 * 1. Pick one element from the array one by one. i 0 to size-1
 * 2. In the second loop find if the element is there or not. j i+1 to size-1
 * 3. If found then that is the repeating number
 *
 * Algorithm 2 :
 * One Loop Method: Sorting  + Searching
 * Time Complexity = O(nlogn) + O(n)
 *
 * 1. Sort the array using Qsort algorithm
 * 2. Linear Search the element as the repeating element will be adjacent.
 *
 * Algorithm 3 :
 * HashMap Method :
 * Time Complexity : O(n) + O(k) Space
 *
 * 1. Create a hash array whose size will be the size of Max mum element in the array.
 * 2. Iterate through the array and Increment the hash[array[i]]
 * 3. Go over the Hash array and check for count == 2.
 * 4. Return these numbers.
 *
 * Algorithm 4 :
 * XOR Method:
 *
 * 1. If only 1 number would have been Repeated.
 * then We take the XOR of
 */

/* sum_0_largest_subarray.c  * Created on: Jul 16, 2018 * Author: Harsh */

#include "array.h"

/* Method 1: Using Hash Table
 *
 * 1. Create a extra table to store the current Sum of the array elements.
 * The sum is the index in this table and the value in it is the index i.
 *
 */
int MAX(int x, int y){
	return x > y ? x : y;
}
#define INT_MAX__ 3200
int largest_zero_subarray(int* A, int size) {
    int sum[INT_MAX__] = {-1};
    int current_sum = 0;
    int max_len = 0;

    for(int i = 0; i<size; i++){
        current_sum = current_sum + A[i];

        // If the element itself is 0 and max_len so far is also 0 then update
        if(A[i] == 0 && max_len == 0)
        	max_len = 1;

        if(current_sum == 0){
        	max_len = i+1;
        }

        if(sum[current_sum] != -1){
        	max_len = MAX (max_len, i-sum[current_sum]);
        }
        else{
        	// Update the current sum with the index of the array element
        	sum[current_sum] = i;
        }
    }
    return max_len;
}

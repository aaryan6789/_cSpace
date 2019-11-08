/* find_max_average.c *  Created on: Apr 21, 2018 * Author: hsahu */
#include <limits.h>
#include "array.h"

/* LeetCode Easy
 *  Given an array consisting of n integers,
 *  find the contiguous sub-array of given length k that has
 *  the maximum average value.
 *  And you need to output the maximum average value.
 *
 *  Example 1:
 *  Input: [1,12,-5,-6,50,3], k = 4
 *  Output: 12.75
 *
 *  Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
 *
 *  Note:
 *  1 <= k <= n <= 30,000.
 *  Elements of the given array will be in the range [-10,000, 10,000].
 */

/*
 * Algorithm: By Hash Map
 * 1. create a Hash map of size size - 3
 * 2. For each entry in the Hash map store the average of the contiguos k numbers
 * 3. Check the Max of them
 */

double findMaxAverage(int* A, int size, int k) {
    if(size == 1){
        return A[0];
    }
    printf("%s: Size = %d, k = %d, size-k+1 = %d\n", __FUNCTION__, size, k, size-k+1);

    double hash[size-k+1];
    memset( hash, 0, (size-k+1)*sizeof(double));

    double average;
    int sum;

    for(int i = 0; i<size-k+1; i++) {
        sum = 0;
        for(int j = 0; j<k; j++){
            sum = sum + A[i + j];
            //printf("Sum = %d i = %d j = %d A[i+j] %d\n", sum, i, j, A[i+j] );
        }

        average = (double)sum/k;
        //printf("i = %d\n", i);
        hash[i] = (double)average;

        //printf("Sum = %d Average = %f ~ %f hash[%d] = %d\n",sum, average, sum/k, i, hash[i]);
    }

    double max = LONG_MIN;
    for(int m = 0; m<size-k+1; m++) {
        if(hash[m] > max){
            max = hash[m];
        }
    }

    printf("%s: Max average is %f\n", __FUNCTION__, max);
    return max;
}

/**
 * Sliding Window [Accepted]
Algorithm

- Instead of creating a cumulative sum array first, and then traversing over it
 to determine the required sum, we can simply traverse over nums just once, and
 on the go keep on determining the sums possible for the subarrays of length k.

 To understand the idea, assume that we already know the sum of elements from
 index i to index i+k, say it is sum.  <---- First k elements

Now, to determine the sum of elements from the index i+1 to the index i+k+1, all
 we need to do is to subtract the element nums[i] from x and to add the element
 nums[i+k+1] to sum.

 We can carry out our process based on this idea and determine the maximum possible average.
 */

double findMaxAverageSliding(int* nums, int numsSize, int k){
    double sum = 0;
    // Calculate the average of the first k elements
    for(int i = 0; i< k; i++){
        sum += nums[i];
    }

    printf("First k elements average = %f\n", sum);

    double res = sum;
    // Now lets calculate the rest of the averages one by one and also update the max
    for(int i = k; i< numsSize; i++){
        res = res + nums[i] - nums[i-k];        // Every time add the new num but subtract the first one then
        if (res > sum){
            sum = res;
        }
    }

    printf("New maxAvg = %f \n", res);

    return res/(double)k;

}

/* Method 2:
 *
 *
 */
double findMaxAverage2(int* A, int size, int k) {
    int max= INT_MIN;
    int tem=0;

    // When size and K are the same
    if(size<=k){
        max=0;
        for(int i=0; i<size; i++)
            max= max + A[i];

        printf("%d *",max);
        return (double)max/size;
    }

    for(int i=0; i<k; i++){
        tem = tem + A[i];
        printf("%d %d %d\n", tem, size, k);
    }

    for(int i=0; i<=size-k; i++){
    	if (tem>max)
    		max=tem;

        tem = tem - A[i]+ A[i+k];
    }

    printf("%d",max);
    return (double)max/k;
}

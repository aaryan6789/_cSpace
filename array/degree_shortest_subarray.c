/**
 * Leetcode Easy
 *
 *
  Given a non-empty array of non-negative integers nums, the degree of this
  array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

Example 1:
Input: [1, 2, 2, 3, 1]
Output: 2
Explanation:
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.
Example 2:
Input: [1,2,2,3,1,4,2]
Output: 6
Note:

nums.length will be between 1 and 50,000.
nums[i] will be an integer between 0 and 49,999.
 */

int findShortestSubArray(int* A, int size){
    int hash[50000] = {0};
    int first[50000] = {0};
    int max = 0;
    int res = 0;

    for(int i = 0; i< size; i++){
        // Put the index of the element seen for the first time, so that we can
        // calculate the len of the sub array later
        if(first[A[i]] == 0){
            first[A[i]] = i + 1;
        }

        // Update the hash tables frequency number
        hash[A[i]]++;

        // Check if the element is the max occuring one or not
        if(hash[A[i]] > max){
            max = hash[A[i]];
            res = i - first[A[i]] + 2;      // if it is max occuring then calculate the len of this subarray
        }
        else if (hash[A[i]] == max){        // If it is equal to max then compare the len of this sub array with the previous one and update if its smaller
            if((i- first[A[i]] + 2) < res){
                res = i - first[A[i]]+2;
            }
        }
    }
    return res;
}
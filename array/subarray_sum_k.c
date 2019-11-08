/*
 * sum_subarray_k.c *  Created on: Apr 15, 2018 * Author: hsahu
 */

#include "array.h"

/*
 * Given an array of integers and an integer k,
 * you need to find the total number of continuous subarrays whose sum equals to k.
 *
 * Algorithm 1: Two Loop method
 * 1. For each element see if the continuous sub arrays can be formed which can
 * lead to the sum.
 * 2. Pick a element one by one from the First loop.
 * 3. Check for the subsequent elements if they can form a sum == k.
 *
 * Time Complexity = O(n2)
 */

int subarraySum1(int* A, int size, int k) {
    int count = 0;
    for(int i = 0; i< size; i++){
        int sum = A[i];
        if (sum == k)
            count = count+1;

        for(int j = i+1; j< size; j++){
            sum = sum + A[j];
            if(sum == k){
                count++;
            }
        }
    }
    printf("total subarrays with sum = %d are %d\n", k, count);
    return count;
}

/*
 * Algorithm : Use Hash Map
 * The idea behind this approach is as follows:
 *
 * 1. If the cumulative sum (represented by sum[i] for sum upto ith index)
 * upto two indices is the same, the sum of the elements lying in between those indices is zero.
 *
 * Extending the same thought further, if the cumulative sum upto two indices, say i and j
 * is at a difference of k i.e. if sum[i] - sum[j] = k,
 * the sum of elements lying between indices i and j is k.
 *
 * Based on these thoughts, we make use of a hashmap sumMap which is used to store
 * the cumulative sum upto all the indices possible along with the number of times
 * the same sum occurs.
 *
 * We store the data in the form: (sum_i, no. of occurrences of sum_i).
 *
 * We traverse over the array A and keep on finding the cumulative sum.
 * Every time we encounter a new sum, we make a new entry in the hashmap corresponding to that sum.
 * If the same sum occurs again, we increment the count corresponding to that sum in the hashmap.
 * Further, for every sum encountered, we also determine the number of times the sum sum-k
 * has occurred already, since it will determine the number of times a subarray with sum k has
 *
 * occurred upto the current index.
 *
 * We increment the count by the same amount.
 * After the complete array has been traversed, the count gives the required result.
 *
 **/

int subarraySum2(int* A, int size, int k) {
    int sum[size];
    int current_sum = 0;
    int count = 0;

    for(int i = 0; i<size; i++){
        //sum[i] = sum[i-1] + A[i];
        current_sum = current_sum + A[i];
        if(current_sum == k)
            count++;

        sum[i] = current_sum;
        for(int j = 0; j<i; j++){
            if(sum[j] == (current_sum - k)){
                count++;
            }
        }
    }
    printf("Count 2 = %d\n", count);
    return count;
}


// Method 3: By making a custom Hash table

#define MAX_N 20005
struct Node{
    int sum;
    int cnt;
    struct Node* next;
}nodes[MAX_N];

int node_id;

struct Node* malloc_node()
{
    struct Node* n = &nodes[node_id++];
    n->next = NULL;
    return n;
}

struct Node* bucket[MAX_N];

struct Node* insert_list(struct Node* head, int sum)
{
    if(head == NULL) {
        head = malloc_node();
        head->sum = sum;
        head->cnt = 1;
    }
    else {
        struct Node* cur = head;
        while(cur->sum != sum && cur->next)
            cur = cur->next;
        if(cur->sum != sum)
        {
            cur->next = malloc_node();
            cur = cur->next;
            cur->sum = sum;
            cur->cnt = 1;
        }
        else {
            (cur->cnt)++;
        }
    }
    return head;
}

void insert_hash(int sum) {
    int key = sum > 0 ? sum : -sum;
    key = key % MAX_N;

    bucket[key] = insert_list(bucket[key], sum);
}

int find_hash(int sum){
    int key = sum > 0 ? sum : -sum;
    key = key % MAX_N;

    int cnt = 0;
    struct Node* cur = bucket[key];
    while(cur)    {
        if(cur->sum == sum)
            return cur->cnt;
        cur = cur->next;
    }

    return cnt;
}

int subarraySum3(int* nums, int numsSize, int k) {
    int sum = 0;
    node_id = 0;
    for(int i = 0; i < MAX_N; ++i)
        bucket[i] = NULL;

    insert_hash(0);
    int res = 0;

    for(int i = 0; i < numsSize; ++i)
    {
        sum += nums[i];
        res += find_hash(sum - k);
        insert_hash(sum);
    }

    return res;

}

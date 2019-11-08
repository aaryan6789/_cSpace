/*missing_num_1.c |  Created on: Apr 14, 2018 | Author: hsahu */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "array.h"

/**
 * LeetCode Easy 268 | CTCI
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 * Find the one that is missing from the array.
 *
 * Example 1
 * Input: [3,0,1]
 * Output: 2

 * Example 2
 * Input: [9,6,4,2,3,5,7,0,1]
 * Output: 8
 */

int missingNumber(int* A, int size) {
    int allSum = 0;
    int arrSum = 0;

    for(int i = 0; i< size; i++){
        arrSum = arrSum+A[i];
    }

    allSum = (size*(size + 1))/2;

    return (allSum - arrSum);
}


//Same type of question with Strings

/*
2 strings (s, t) are given which are anagrams of each other and also t has more
characters than s.
So we can create a Hash map of all the characters in the 2 strings and
return the only character that was there in the hash map.
*/

// Since only Lower case letters are present

#define INULL 0
#define MAX_CHARS 26
char findTheDifference(char* s, char* t) {
    int hash[MAX_CHARS] = {0};
    int biglen;

    int len1 = strlen(s);
    int len2 = strlen(t);

    if(len1 == len2 || len1>(len2+2) || len2 > (len1+2) ){
        return INULL;
    }

    for(int i =0; i<len1; i++){
        hash[s[i] - 'a']++;
    }

    for(int i =0; i<len2; i++){
        hash[t[i] - 'a']++;
    }

    // the extra character only will be occuring odd no of times
    for(int i = 0; i<MAX_CHARS; i++){
        if(hash[i]%2 != 0){
            printf("%c", (i+'a'));
            return ((char)i + 'a');
        }
    }

    return INULL;
}


/**
 * Creating a Dynamic Array
int *save=(int*)malloc(sizeof(int)*numsSize);
    for(int i=0;i!=numsSize;i++){
        save[i]=0;
    }
*/
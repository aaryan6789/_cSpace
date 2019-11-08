/*
 * plus_one.c
 *
 *  Created on: Apr 14, 2018
 *      Author: hsahu
 */
#include <stdio.h>
#include <stdlib.h>
#include "array.h"

/**
 * Given an Input array of digits of a non negative number D,
 * Update the array to show D+1.
 */

// I/P = {1 2 9}
// O/P = {1 3 0}

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int carry = 1;
    int i = digitsSize;             // i from the digits Size
    int* ret = (int*)malloc(sizeof(int)*(digitsSize+1));

    while (i > 0) {
        ret[i] = (digits[i-1]+carry)%10;
        carry = (digits[i-1]+carry)/10;
        i--;
    }
    if (!ret[1]) {          // False on when ret[1] will be zero as maximum it can go to is 10 so ret[1] will be 0
        // size increased 1, set the first digit
        ret[0] = 1;
        *returnSize = digitsSize+1;
        return ret;
    } else {
        *returnSize = digitsSize;
        return (ret+1);       // Pointer Magic by returning the next memory location of the return function
    }
}

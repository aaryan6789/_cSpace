/*
 * third_largest_element.c
 *
 *  Created on: Apr 21, 2018
 *      Author: hsahu
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "array.h"

void thirdLargest(int arr[], int arr_size) {
    /* There should be atleast three elements */
    if (arr_size < 3){
        printf(" Invalid Input ");
        return;
    }

    // Initialize first, second and third Largest element
    int first = arr[0];
    int second = INT_MIN;
    int third = INT_MIN;

    // Traverse array elements to find the third Largest
    for (int i = 1; i < arr_size ; i ++) {
        /* If current element is greater than first,
           then update first, second and third */
        if (arr[i] > first) {
            third  = second;
            second = first;
            first  = arr[i];
        }

        /* If arr[i] is in between first and second */
        else if (arr[i] > second) {
            third = second;
            second = arr[i];
        }

        /* If arr[i] is in between second and third */
        else if (arr[i] > third)
            third = arr[i];
    }

    printf("The third Largest element is %d\n", third);
}

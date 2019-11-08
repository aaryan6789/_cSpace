#include "array.h"
static int cmp1 (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}


void peaks_and_valleys(int* A, int size){
    /** Algortithms:
     * 1. Sort the array
     * 2. Once the array is sorted that means the numbers are in a particular order. i.e increasing order.
     * 3. loop through this array starting from 1 jumping 2 values every time
     * 4. Swap the item from its previous value
     *
     * Unsorted Array --> Sorted Array
     *
     * small , medium, large, x large, xxlarge
     * medium , small, xlarge, large, xxlarge
     * peak , valley, peak, valley, peak
    */
    qsort(A, size, sizeof(A[0]), cmp1);

    for(int i = 1; i< size; i = i+2){
        swap(&A[i], &A[i-1]);
    }
}

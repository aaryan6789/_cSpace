/*
 * remove_duplicates.c * Created on: Apr 21, 2018 * Author: hsahu
 */

#include "array.h"

// Function to remove duplicate elements
// This function returns new size of modified array.
int removeDuplicates(int A[], int n){
	if(n==0 || n==1)
    	return n;

    // To store index of next unique element
    int j = 0;

    // Doing same as done in Method 1
    // Just maintaining another updated index i.e. j
    for (int i=0; i < n-1; i++) {
    	if (A[i] != A[i+1])
            A[j++] = A[i];
    }
	// Last element also since we are looping only till the second last element
    A[j++] = A[n-1];

    return j;   // j is the new Lnegth
}

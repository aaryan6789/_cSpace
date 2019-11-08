/*
 * push_0_to_end.c
 */

#include "array.h"


void push_zero_to_end(int *A, int size){
	int count =0;

	for(int i = 0; i< size; i++){
		if(A[i]!=0){
			A[count++] = A[i];
		}
	}

	while(count < size){
		A[count++] = 0;
	}

	return;
}

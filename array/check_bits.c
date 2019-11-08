/* check_bits.c * Created on: Apr 14, 2018 * Author: hsahu */

#include "array.h"

// Read the notes before this question
#define TRUE 1
#define FALSE 0
#define MAX_INT 32000
#define SET_BIT(arr, bit) (arr[bit/32] |= (1 << (bit % 32)))
#define CHK_BIT(arr, bit) ((1 << (bit % 32)) & (arr[bit/32])) ? TRUE : FALSE

void check_bit(int *arr, int bit){
	// Divide by 32 to find position of number at which byte/ index in the bit_vector array.
	int index = (bit >> 5); // pos>>5 is equal to bit/32;
	// Now find bit number in arr[index]
	int bitNo = (bit & 0x1F); 	// pos&)x1F is equal to pos%32.

	unsigned int flag = 1;
	flag = flag << bitNo;

	if (arr[index] & flag){
		printf("%s : %dth bit is Set.\n",__FUNCTION__, bit);
	}
	else {
		printf("%s : %dth bit is not set.\n",__FUNCTION__, bit);
	}
}

void set_bit(int *arr, int bit){

	int index = bit >> 5;
	int bitNo = bit%32;

	unsigned int flag = 1;
	flag = flag << bitNo;

	printf("%s: Set %dth bit.\n", __FUNCTION__, bit);
	arr[index] = arr[index] | flag;
	//check_bit(arr, bit);
	return;
}

void check_duplicates_bitArray(int * arr, int size){
	// Divide by 32.
	// To store n bits, we need n/32 + 1 integers
	// (Assuming int is stored using 32 bits)
	int bit_vector[MAX_INT/32] = {0};

	for(int i = 0; i < size; i++){
		if(CHK_BIT(bit_vector, arr[i])){
			check_bit(bit_vector, arr[i]);
			printf("%s: %d is Duplicate element\n", __FUNCTION__, arr[i]);
		}
		else{
			set_bit(bit_vector, arr[i]);
			//SET_BIT(bit_vector, arr[i]);
		}
	}
}

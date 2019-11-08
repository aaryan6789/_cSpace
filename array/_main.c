/* ARRAY_C_ */
#include "array.h"

#define length(a) (sizeof a / sizeof *a)
//=============================================================================
// Utility Functions
//=============================================================================
/**
 * Swap - swaps 2 numbers by reference
 */
void swap(int *a, int *b){
	int temp ;
	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * insert - Insert in an Array
 */
void insert(int *A, int data, int position, int length){
	int i;

	for (i = length-1; i>=position-1; i--) {
		printf("A[%d]: %d\n", i, A[i]);
		A[i+1] = A[i];
		printf("A[%d]: %d\n", i, A[i]);
	}

	A[position-1] = data;
}

/**
 * Print an array
 * == NOTE == :
 * The sizeof way is the right way iff you are dealing with arrays not received
 * as parameters. An array sent as a parameter to a function is treated as a pointer,
 * so sizeof will return the pointer's size, instead of the array's.
 */
void print_array(int *A, int length){
	int i;
	printf("\n");
	printf("%s : Array Size: %d ->", __FUNCTION__, length);
	printf(" Array: ");

	for(i = 0; i<length; i++)
		printf("%d ", A[i]);

	printf("\n");
}
// </Utility Functions>
int main(){
	int A[] = {1, -3, 16, 6, 7, 9};
	int length = 0;
	length = sizeof(A)/sizeof(A[0]);

	int B[] = {1, 0, 1, 0, 1, 0};
	int lengthB = 0;
	lengthB = sizeof(B)/sizeof(B[0]);

	int a = 7;
	int b = 8;
	swap(&a, &b);
	printf("a = %d", a);
	printf(" b = %d\n", b);

	two_pair_sum_print(A, length, 10);

	for(int i = 0; i<5; i++){
		A[i]  = i+1;
		printf("%d\n", A[i]);
	}
	print_array(A, length);
	insert(A, 2, 1, length);
	length = sizeof(A)/sizeof(A[0]);
	print_array(A, length);
	printArray(A, length);
	find_max_in_array(A, length);
	find_peak_in_array(A, length);
	print_array(A, length);
	segregate_even_odd(A, length);
	print_array(A, length);

	print_array(B, lengthB);
	segregate_0_1(B, lengthB);
	print_array(B, lengthB);

	int C[] = {};
	int D[] = { 3, 6, 9};

	sorted_merge(C, D, 0, 3);
	printf("Sorted Merge");
	print_array(C, 4);

	// /* ------------ bit Array --------*/
    int arr[] = {1, 5, 1, 10, 12, 10};
    int size = sizeof(arr)/sizeof(arr[0]);
	int result;

    check_duplicates_bitArray(arr, size);
	result = dominantIndex(arr, size);

    /* ------------ Rearrange Array --------*/

    int E[] = {20, -10, 35, 45, 55, 67, -90};
    int esize = sizeof(E)/sizeof(E[0]);

    regarrange_pos_neg(E, esize);
    print_array(E, esize);

    int F[] = {0, 0, 1 , 3, 5, 6, 0, 9, 0, 2, 0, 0, 8};
    int fsize = sizeof(F)/sizeof(F[0]);

    push_zero_to_end(F, fsize);
    print_array(F, fsize);

    int G[] = {8,1,1,1,2,7,4,3,1,1};
    int gsize = sizeof(G)/sizeof(G[0]);
    print_array(G, gsize);

    maxProfit(G, gsize);
    max_profit_many(G, gsize);

	findDuplicate(G, gsize);

    check_zero_subarray(E, esize);

    int H[] = {1,3, -2, 9, 5, -6};
    int hsize = sizeof(H)/sizeof(H[0]);

    printArray(H, hsize);
    // int* ret = plus_one(H, hsize);
    printArray(H, hsize);

    countPairs(G, gsize, 2);

    countPairsWithDiffK(G, gsize, 2);

    sum_close_to_zero(H, hsize);

    // int* p;
    // printf(" Size Of %lu , %lu\n", sizeof(p), sizeof(*p));

	findMaxAverage(G, gsize, 2);
	thirdLargest(H, hsize);

	/** ========== Practice ============== */
	int arr1[] = {4, 9, -1, 2, 0, 6, 8};
	int sarr1 = sizeof(arr1)/sizeof(arr1[0]);

	int arr2[] = {4, 4, 9, -1, 2, 0, 7, 9, 8};
	int sarr2 = sizeof(arr1)/sizeof(arr1[0]);

	twoSumP(arr1, sarr1, 10);

	int arr3[] = {1,1,1,2, 3, 4, 5,5,5,6,6,6,7};
	int sarr3 = sizeof(arr3)/sizeof(arr3[0]);
	printArray(arr3, sarr3);
	removeDuplicatesSortedArrayP(arr3, sarr3);
	// removeDuplicates(arr3, sarr3);
	printArray(arr3, sarr3);

	int arr4[] = {-1,2,-9,-8, -3, -4, 5,5,5,6,6,6,-7, 0};
	int sarr4 = sizeof(arr4)/sizeof(arr4[0]);

	printArray(arr4, sarr4);
	rearrangePosNegP(arr4, sarr4);
	printArray(arr4, sarr4);

	int arr5[] = {2,3,5,0, 9, -2, -22, 88, -9, 99, 122};
	int s5 = sizeof(arr5)/sizeof(arr5[0]);
	printArray(arr5, s5);

	peaks_and_valleys(arr5, s5);
	printArray(arr5, s5);

	int AA[] = {1, 1, 2, 2, 3, 3, 4};
	int BB[] = {1, 1, 2, 2, 3, 3, 4};


	p_twoArraySum(AA, BB, 7, 7, 2);

	sumSwap(AA, BB, 7,7);

	subarray_max_sum_size_k(AA, 7, 6);
	subarray_max_sum_size_k(arr5, s5, 6);



	printf("End of Array\n");

	return 0;
}

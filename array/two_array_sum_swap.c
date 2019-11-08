#include "array.h"

/**
 * Given 2 Unsorted arrays, find a pair of values (one value from each array) that
 * you can swap to give the 2 arrays the same SUM.
 *
 * Example 1:
 * A = {4,1,2,1,1,2}        B = {3,6,3,3}
 * O/p = 1, 3
 */

/**
 * Algorithm:
 * Basics:
 *
 * A --> SumA , B --> SumB
 * sumA != sumB
 *
 * But if we remove one elsement from A and one from B and put them in the other
 * array respectively. then we reach to this equation.
 *     ===> sumA - a + b = sumB -b + a
 *     ===> (sumA - sumB)/2 = a - b
 *
 * Method 1: Sorting and computing the difference
 * Time Complexity = O(nlogn) + O(n)
 * 1. Sort Both the arrays
 * 2. Calculate the sum of A and B
 * 3. Target = SumA - SumB/2
 * 4. while (a<sizeA AND b< sizeB)
 *
 *
 *
 * Method 2: Hash Map
 * 1. Parse thrugh the Array 1 and Put all the the numbers in a Hash map
 * 2. Parse through the second array and check
 */

/** Get the target value for the 2 arrays */
int getTarget(int* A, int* B, int sizeA, int sizeB){
    int sumA = 0, sumB = 0;


    for(int i = 0; i< sizeA; i++){
        sumA += A[i];
    }

    for(int i = 0; i< sizeB; i++){
        sumB += B[i];
    }

    int target = (sumA - sumB)/ 2;

    printf("Target = %d\n", target);
    return target;
}

void findDifference(int* A, int* B, int sizeA, int sizeB, int target){
    int a = 0;
    int b = 0;
    int count = 0;

    while(a < sizeA && b < sizeB){
        int diff = A[a] - B[b];

        if(diff == target){
            printf("Pair %d %d found\n", A[a], B[b]);
            a++;
            b++;
            count++;
        }
        else if (diff < target){
            a++;
        }
        else{
            b++;
        }
    }
    printf("Total pairs found = %d\n", count);
}

int sumSwap(int* A, int* B, int sizeA, int sizeB){
    int target = getTarget(A, B, sizeA, sizeB);

    findDifference(A, B, sizeA, sizeB, target);

    return 0;
}
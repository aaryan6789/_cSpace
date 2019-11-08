#include "array.h"
int cmp (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}






/** Given two unsorted arrays, find all pairs whose sum is x */
// Same as 2 Sum problem
int p_twoArraySum(int *A, int *B, int sizeA, int sizeB, int target){
    // Sort Array A
    // Sort Array B
    qsort(A, sizeA, sizeof(A[0]), cmp);
    qsort(B, sizeB, sizeof(B[0]), cmp);

    // Have 2 pointers
    int left = 0;
    int right = sizeB-1;
    int count = 0;
    int sum;

    // Go through both the Arrays one by one
    while (left < sizeA && right >= 0){     // <--- && Pay Attention here
        sum = A[left] + B[right];
        if(sum == target){
            printf("Sum found at A = %d  B = %d\n", left, right);
            left++;
            right--;
            count++;
        }
        else if (sum < target){
            left++;
        }
        else{
            right--;
        }
    }
    printf("Count = %d\n", count);
    return count;
}



// Find smallest different close to 0 in 2 arrays
int smallest_diff_2ArraysP(int* A, int* B, int sizeA, int sizeB){
    // Sort both the arrays
    int a = 0;
    int b = 0;
    int min = INT_MAX;

    while(a < sizeA && b < sizeB){
        int diff = abs(A[a] - B[b]);
        if(diff < min){
            min = diff;
        }

        // Move in the Smaller array foward to reduce the diff
        if(A[a] < B[b]){
            a++;
        }
        else{
            b++;
        }
    }
    return min;
}


// Pair Sum in 2 Arrays
// 1. Given two unsorted arrays, find all pairs whose sum is x
// 2. Count pairs from two sorted arrays whose sum is equal to a given value x
/*
Method 2: Hashing
Method 3: Binary search for each element in array 1
Method 4 (Efficient Approach): This approach uses the concept of two pointers,
one to traverse 1st array from left to right and
another to traverse the 2nd array from right to left.

Algorithm :

countPairs(arr1, arr2, m, n, x)

     Initialize l = 0, r = n - 1
     Initialize count = 0

     loop while l = 0
        if (arr1[l] + arr2[r]) == x
           l++, r--
           count++
        else if (arr1[l] + arr2[r]) < x
           l++
        else
           r--

     return count
*/
int pairSumP(int* A, int* B, int sizeA, int sizeB, int target){
    qsort(A, sizeA, sizeof(A[0]), cmp);
    qsort(B, sizeB, sizeof(B[0]), cmp);

    int a_left = 0;
    int b_right = sizeB-1;
    int count = 0;

    while(a_left < sizeA && b_right>=0){
        int sum = A[a_left] + B[b_right];

        if(sum == target){
            count++;
            a_left++;
            b_right--;
        }
        else if(sum < target){
            a_left++;
        }
        else{
            b_right--;
        }
    }

    if(count ==0){
        return -1;
    }
}




void p_peaks_and_valleys(int* A, int size){
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
    qsort(A, size, sizeof(A[0]), cmp);

    for(int i = 1; i< size; i = i+2){
        swap(&A[i], &A[i-1]);
    }
}


// Rearrange +ve and -ve numbers in an array alternatively
// Given: An array with +ve and -Ve numbers in random order
// Algorithm:
// - Partition the array around 0
// - -ve first and +ve after
// - Then Swap

void swapP(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void rearrangePosNegP(int* A, int size){
    int pI = -1;

    for(int i = 0; i < size; i++){
        if(A[i] < 0){
            pI++;
            swap(&A[i], &A[pI]);
        }
    }

    int neg = 0;
    int pos = pI+1;

    while(neg<pos && pos<size && A[neg]<0){
        swap(&A[neg], &A[pos]);
        neg +=2;
        pos +=1;
    }
}

void p_rearrangePosNeg(int* A, int size){
    int pI = -1;

    // Partition the array around 0 (O(n))
    for(int i = 0; i< size; i++){
        if(A[i] < 0){
            pI++;
            swapP(&A[i], &A[pI]);
        }
    }

    int neg = 0;
    int pos = pI+1;

    while(neg< pos && pos<size &&A[neg]<0){
        swap(&A[neg], &A[pos]);
        neg = neg+3;
        pos = pos+1;
    }
}


#define MAX(x, y) (((x))>((y)) ? (x):(y))
#define MIN(x, y) ((x)) < ((y)) ? (x) : (y)
// Given an array of prices, find the max profit that can be found from a single buy and sell.
int maxProfitStockP(int* price, int size){
    int min_val_so_far = price[0];
    int max_profit = 0;
    int profit_today = 0;

    for(int i =1; i<size; i++){
        profit_today = price[i] - min_val_so_far;
        max_profit = MAX(profit_today, max_profit);
        min_val_so_far = MIN(min_val_so_far, price[i]);
    }

    printf("Max Profit = %d\n", max_profit);
    return 0;
}

// Remove duplicates from sorted array
void removeDuplicatesSortedArrayP(int* A, int size){
    // Since the array si ssorted already so we just have to look for
    // adjacent ducplicate values

    if (size == 0 || size == 1)
        return;

    int j = 0;  // Index for putting no duplicate values

    for (int i =0; i< size-1; i++){
        if(A[i] != A[i+1]){
            A[j] = A[i];
            j++;
        }
    }
    A[j++] = A[size-1];

    printArray(A, j);
}

// Sorted Array, find a target value
int binarySearch(int *A, int size, int target){
    int start = 0;
    int end = size-1;

    while(start <= end){
        int mid = start + (end-start)/2;
        if(A[mid] == target){
            printf("Found the target at %d\n", mid);
            return mid;
        }
        // A[mid] is smaller than target that means in a sorted ascending order
        // array the target element would be in the next half.
        else if(A[mid] < target){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }

    // No target found
    return -1;
}


// Local Maxima or Minima | NIO onsite
// Pivot will be the min element
int findPivotP(int* A, int size){
    int start = 0;
    int end = size-1;

    while(start <= end){
        int pivot = start+ (end-start)/2;
        if(((pivot == start) && (A[pivot] < A[pivot+1])) ||     // When the pivot is in the front itself
            ((pivot == end) && (A[pivot] < A[pivot-1])) ||      // When the pivot is in the end
            ((A[pivot] < A[pivot+1] && A[pivot] < A[pivot-1] ))){   // When the pivot is in the middle somewhere
                printf("Pivot found at %d %d\n", pivot, A[pivot]);
                return pivot;
            }
        else if (A[pivot] > A[pivot-1]){
            end = pivot-1;
        }
        else{
            start = pivot+1;
        }
    }
    return -1;
}


int searchPivotedArrayP(int *A, int l, int h, int target){
    if (l > h)
        return -1;

    int mid = (l+h)/2;

    if (A[mid] == target){
        return mid;
    }

    // If the mid is greater than the first element that means the array is sorted between l and mid
    if(A[l] <= A[mid]){
        // Look for the target in this array
        if(target >= A[l] && target <= A[mid]){
            searchPivotedArrayP(A, l, mid-1, target);
        }
        else{
            searchPivotedArrayP(A, mid+1, h, target);
        }
    }

    if(target >= A[mid] && target <= A[h]){
        searchPivotedArrayP(A, mid+1, h, target);
    }
    else{
        searchPivotedArrayP(A, l, mid-1, target);
    }
}

//Algo 2 for Search in Sorted rotated Array would be
// - Find pivot
// - Compare the target value with A[l] and A[pivot]
// - Compare the values between A[pivot] and A[h]
// - Apply binary search accordingly





int cmp2(void* a, void* b){
    return (*(int*)a - *(int*)b);
}

// Unsorted array
// Find the pair with the given val
void twoSumP(int* A, int size, int val){
    // Sort the array first
    printf("Practice: twoSumP for %d\n", val);
    qsort(A, size, sizeof(A[0]), cmp);
    printArray(A, size);

    int start = 0;
    int end = size-1;
    int sum;
    int count = 0;

    while(start < end){
        sum = A[start] + A[end];
        if( sum == val){
            printf("Found Pair %d, %d\n", A[start], A[end]);
            start++;
            end--;
            count++;
        }
        else if(sum < val){
            start++;
        }
        else{
            end--;
        }
    }
    if(count == 0)
        printf("no pairs found with sum = %d\n", val);

    return;
}
// Time Coplexity = O(nlogn) + O(n) (Sorting + Searching)


void threeSumP(int* A, int size, int val){
    int count = 0;

    // Sort the array first
    qsort(A, size, sizeof(A[0]), cmp);

    for(int i = 0; i<size-2; i++){
        int left = i+1;
        int right = size-1;

        while(left < right){
            int sum = A[i] + A[left] + A[right];

            if(sum == val){
                left++;
                right--;
                count++;
                printf("Triplet #%d are %d, %d %d\n",val, A[i], A[left], A[right]);
            }
            else if(sum < val){
                left++;
            }
            else{
                right--;
            }
        }
    }

    if(count ==0){
        printf("No triplets found\n");
    }
}


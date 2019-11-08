#include "array.h"

/* Traverse all n entry in the array.
 * If A[i] > A[i+1], then check whether this condition can
 * be resolved by one entry change.
 */
#define true 1
#define false 0
#define bool int

int checkPossibility1(int* nums, int numsSize) {
    int count = 0, i = 0;

    for(i=0; i < numsSize-1 ; i++) {
    	if (nums[i] > nums[i+1]) {
    		count++;

            if (count>=2)
            	return false;

            if ( (i != 0 && i+2 < numsSize && nums[i+2] < nums[i]) &&
                 (i-1 >= 0 && nums[i+1] < nums[i-1]) )
                return false;
        }
    }
    return true;
}



bool checkPossibility(int* nums, int numsSize) {
    int count=0;

    if(numsSize==1 || numsSize==2)
    	return true;

    for(int i=1; i < numsSize-1; i++){
    	if( !(nums[i]>=nums[i-1] && nums[i+1]>=nums[i])){
    		if(nums[i+1]>=nums[i-1]){
    			count++;
    			nums[i]=nums[i-1];
    		}else{
    			if(nums[i]<nums[i-1] && nums[i+1]<nums[i]) return false;
    			else if(nums[i]<=nums[i+1]){
    				nums[i-1]=nums[i];
    				if(i-1==0 || nums[i-2]<=nums[i-1]) count++;
    				else return false;
    			}
    			else{
    				nums[i+1]=nums[i];
    				count++;
    			}
    		}
    	}

    	if(count>1)
    		return false;
    }
    return true;
}


bool checkPossibility3(int* nums, int numsSize) {
    int i = 0 ;
    bool result = true;
    bool result1 = true;
    if (numsSize<=2)
        return true;

    int *nums1 = malloc(sizeof(int)*numsSize);

    if (!nums1)
        return false;

    memcpy (nums1, nums, sizeof(int)*numsSize);

    for (i=0; i < numsSize-1; i++)
    {
        if (nums[i] > nums[i+1])
        {
            nums[i+1] = nums[i];
            nums1[i] = nums1[i+1];
            break;
        }
    }

    for (i=0; i < numsSize-1; i++)
    {
        if (nums[i] > nums[i+1])
            result = false;
        if (nums1[i] > nums1[i+1])
            result1 = false;
    }
    if (nums1)
        free(nums1);

    return (result || result1);
}

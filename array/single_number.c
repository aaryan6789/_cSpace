/* single_number.c  * Created on: Jul 30, 2018 * Author: Harsh */


/* Given a non-empty array of integers,
 * every element appears twice except for one. Find that single one.
 *
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 *
 * Example 1:
 * Input: [2,2,1]
 * Output: 1
 *
 * Example 2:
 * Input: [4,1,2,1,2]
 * Output: 4
 */

int singleNumber(int* A, int size) {
    if(size == 1)
        return A[0];

    int res = A[0];

    for(int i = 1; i<size; i++){
        res = res^A[i];
    }

    return res;

}

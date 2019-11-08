#include "string_moderate.h"

/**
 * Given a string s, find the length of the longest substring t that contains at
 * most 2 distinct characters.

Example 1:
Input: "eceba"
Output: 3
Explanation: t is "ece" which its length is 3.

Example 2:
Input: "ccaabbb"
Output: 5
Explanation: t is "aabbb" which its length is 5.
 */

/** Algorithm:
 * - Sliding Window Concept
 * To solve the problem in one pass let's use here sliding window approach with
 * two set pointers left and right serving as the window boundaries.
 *
 * The idea is to set both pointers in the position 0 and then move right pointer
 * to the right while the window contains not more than two distinct characters.
 *
 * If at some point we've got 3 distinct characters, let's move left pointer to
 * keep not more than 2 distinct characters in the window.
 *
 * Basically that's the algorithm :
 * to move sliding window along the string,
 * to keep not more than 2 distinct characters in the window, and
 * to update max substring length at each step.
 *
 * There is just one more question to reply - how to move the left pointer to
 * keep only 2 distinct characters in the string?
 *
 * Let's use for this purpose hashmap containing all characters in the sliding
 * window as keys and their rightmost positions as values.
 *
 * At each moment, this hashmap could contain not more than 3 elements.
 *
 * For example, using this hashmap one knows that the rightmost position of character
 * e in "eeeeeeeet" window is 8 and so one has to move left pointer in the
 * position 8 + 1 = 9 to exclude the character e from the sliding window.
 *
 * Do we have here the best possible time complexity?
 * Yes, we do - it's the only one pass along the string with N characters and
 * the time complexity is \mathcal{O}(N)O(N).
 *
 * Algorithm
 *
 * Return N if the string length N is smaller than 3.
 * Set both set pointers in the beginning of the string left = 0 and right = 0
 * and init max substring length max_len = 2.
 *
 * While right pointer is less than N:
 * If hashmap contains less than 3 distinct characters, add the current
 * character s[right] in the hashmap and move right pointer to the right.
 *
 * If hashmap contains 3 distinct characters, remove the leftmost character from
 * the hashmap and move the left pointer so that sliding window contains again
 * 2 distinct characters only.
 * Update max_len.
 *
 */
#include <stdio.h>
#include <string.h>

/**
 * Use two pointers: right and left,
 * calculate the appears characters between [left----->right].
 * When appears characters > 2, shift left so that unique characters <= 2.
 * Compare the substring len: right - left + 1,
 * with maxLen during each loop.
 */
int lengthOfLongestSubstringTwoDistinct(char* s, int k) {
    printf("- - - - - - %s - - - - - - \n", __func__);
    int len = strlen(s);
    if (len == 0)
        return 0;

    int left = 0, right = 0;
    int hashTable[256] = {0};
    int uniqueChars = 0;
    int maxLen = 0;

    for (right = 0; right < len; right++) {
        char curChar = s[right];
        printf("\n%c %d\n", curChar, (curChar - '~'));

        if (hashTable[curChar - ' '] == 0)
            uniqueChars += 1;

        hashTable[curChar - ' ']++;
        // printf("\n");
        // for(int i = 0; i< 26; i++){
        //     printf("%d ", hashTable[i]);
        // }

        // If appeared chars have exceeded 2 or we have reached the end of the string
        // Push out the left character
        while (uniqueChars > 2 && left < len) {
            hashTable[s[left] - ' ']--;           // Push out the start character

            if (hashTable[s[left] - ' '] == 0)
                uniqueChars -= 1;         // Decrease the Chars
            left++;
        }

        // Update the Max Len
        if ((right - left + 1) > maxLen)
            maxLen = right - left + 1;
            printf("New Max Len = %d left = %d right = %d\n", maxLen, left, right);
            for(int i = left; i<= right; i++){
                printf("%c", s[i]);
            }
    }

    // printf("\n HashTable = \n");
    // for(int i = 0; i< 256; i++){
    //     printf("%d ", hashTable[i]);
    // }

    for(int i = left; i< maxLen; i++){
        printf("%c", s[i]);
    }

    printf("\n%s --> Max Len = %d\n",s, maxLen);
    return maxLen;
}
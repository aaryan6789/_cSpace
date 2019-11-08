
#include <iostream>
#include <unordered_map>
#include <iterator>

using namespace std;

// 0. using a idx_start to remember the current start
// 1. using a map<char, int> cand remember how many times char occurs
// 2. once the map has more than two elements.
// 3. then move the idx_start and minus the count in map and then calculate the len
int lengthOfLongestSubstringTwoDistinct(string s) {
    const int size_s = s.size();
    unordered_map<char, int> cand;
    int idx_start = 0, long_len = 0;
    for (int i = 0; i < size_s; i++) {
        cand[s[i]]++;
        while (cand.size() > 2) {
            if (--cand[s[idx_start]] == 0)
                cand.erase(s[idx_start]);
            idx_start++;
        }
        long_len = max(long_len, i - idx_start + 1);
    }
    return long_len;
}

/** Similar to minimum window substring,
 * use two pointers: pend and pstart,
 * calculate the appears characters between [pstart----->pend].
 * When appears characters > 2, shift pstart so that appears characters <= 2.
 * Compare the substring len: pend - pstart + 1, with maxLen during each loop.
 */
//longest substring with at most two distinct characters
int lengthOfLongestSubstringTwoDistinct(string s) {
    if (s.length() == 0) return 0;
    int pstart = 0, pend = 0;
    int hashTable[256] = {0};
    int appearedChars = 0;
    int maxLen = 0;
    for (; pend < s.length(); pend++) {
        char curChar = s[pend];
        if (hashTable[curChar] == 0) appearedChars += 1;
        hashTable[curChar]++;

        while (appearedChars > 2 && pstart < s.length()) {
            hashTable[s[pstart]]--;
            if (hashTable[s[pstart]] == 0) appearedChars -= 1;
            pstart++;
        }

        if (pend - pstart + 1 > maxLen)
            maxLen = pend - pstart + 1;
    }
    return maxLen;
}
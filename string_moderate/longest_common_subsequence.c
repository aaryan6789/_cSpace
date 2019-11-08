/* longest_common_subsequence.c |  Created on: May 3, 2018 | Author: Harsh */

#include "string_moderate.h"

// https://leetcode.com/problems/longest-common-subsequence/

/**
 * Given two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.



If there is no common subsequence, return 0.



Example 1:

Input: text1 = "abcde", text2 = "ace"
Output: 3
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.


Constraints:

1 <= text1.length <= 1000
1 <= text2.length <= 1000
The input strings consist of lowercase English characters only.
 */
/* A Naive recursive implementation of LCS problem */
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs_recursive( char *X, char *Y, int m, int n ) {
   if (m == 0 || n == 0)
     return 0;
   if (X[m-1] == Y[n-1])
     return 1 + lcs_recursive(X, Y, m-1, n-1);
   else
     return max(lcs_recursive(X, Y, m, n-1), lcs_recursive(X, Y, m-1, n));
}

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs_dp( char *X, char *Y, int m, int n ){

	// Make a Table of m+1 and n+1 length 2 D array
	int L[m+1][n+1];
	int i, j;

	/* Following steps build L[m+1][n+1] in bottom up fashion.
	* Note that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
	for (i=0; i<=m; i++) {
		for (j=0; j<=n; j++) {
			// Same as Base Case
			if (i == 0 || j == 0)
				L[i][j] = 0;

			// Recursive Case
			else if (X[i-1] == Y[j-1])
				L[i][j] = L[i-1][j-1] + 1;

			else
				L[i][j] = max(L[i-1][j], L[i][j-1]);
		}
	}

	/* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
	return L[m][n];
}

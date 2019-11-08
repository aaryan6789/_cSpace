/*
 * main.c
 *
 *  Created on: May 6, 2018
 *      Author: Harsh
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "string_moderate.h"


// Driver program to test above functions
int main()
{
	char* wordArr[] = {"cat", "dog", "tac", "god", "act"};
	int size = sizeof(wordArr) / sizeof(wordArr[0]);
	printAnagramsTogether(wordArr, size);

	// LONGEST COMMON SUBSEQUENCE
	char X[] = "AGGTAB";
	char Y[] = "GXTXAYB";

	int m = strlen(X);
	int n = strlen(Y);

	printf("\nLength of LCS is %d \n", lcs_recursive( X, Y, m, n ) );
	printf("\nLength of LCS is %d \n", lcs_dp( X, X, m, m ) );

	longestPalSubstr(X);

	char Z[] = "LEEEEEEEEETCOOOOOOOOOOOOOODEE";

	lengthOfLongestSubstringTwoDistinct(Z);

	return 0;

}

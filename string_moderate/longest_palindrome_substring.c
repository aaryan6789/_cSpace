/*
 * longest_palindrome_substring.c
 *
 *  Created on: May 2, 2018
 *      Author: Harsh
 */
#include <string.h>

/* Given a string, find the longest substring which is palindrome.
 * For example,
 * if the given string is �forgeeksskeegfor�, the output should be �geeksskeeg�.
 */

// Brute Force Not sure
// 3 Loops
// A utility function to print a substring str[low..high]
void printSubStr( char* str, int low, int high )
{
    for( int i = low; i <= high; ++i )
        printf("%c", str[i]);
}

/** Method 2 ( Dynamic Programming )
	The time complexity can be reduced by storing results of subproblems.
	The idea is similar to this post.
	We maintain a boolean table[n][n] that is filled in bottom up manner.
	The value of table[i][j] is true, if the substring is palindrome, otherwise false.
	To calculate table[i][j], we
	first check the value of table[i+1][j-1],
	if the value is true and str[i] is same as str[j], then we make table[i][j] true.
	Otherwise, the value of table[i][j] is made false.
 */

// This function prints the longest palindrome substring
// It also returns the length of the longest palindrome
int longestPalSubstr(char* str)
{
    // get length of input string
    int n = strlen(str);

    // table[i][j] will be false if substring str[i..j]
    // is not palindrome.
    // Else table[i][j] will be true
    int table[n][n];

    memset(table, 0, sizeof(table));

    // All substrings of length 1 are palindromes
    int maxLength = 1;

    for (int i = 0; i < n; ++i)
        table[i][i] = 1;

    // check for sub-string of length 2.
    int start = 0;
    for (int i = 0; i < n-1; ++i)
    {
        if (str[i] == str[i+1])
        {
            table[i][i+1] = 1;
            start = i;
            maxLength = 2;
        }
    }

    // Check for lengths greater than 2. k is length
    // of substring
    for (int k = 3; k <= n; ++k)
    {
        // Fix the starting index
        for (int i = 0; i < n-k+1 ; ++i)
        {
            // Get the ending index of substring from
            // starting index i and length k
            int j = i + k - 1;

            // checking for sub-string from ith index to
            // jth index iff str[i+1] to str[j-1] is a
            // palindrome
            if (table[i+1][j-1] && str[i] == str[j])
            {
                table[i][j] = 1;

                if (k > maxLength)
                {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }

   printf("Longest palindrome substring is: ");
   printSubStr( str, start, start + maxLength - 1 );

    // return length of LPS
    return maxLength;
}
/**
 * Time complexity: O ( n^2 )
Auxiliary Space: O ( n^2 )
 */

/*
 * longest_palindrome_subsequence.c
 *
 *  Created on: May 3, 2018
 *      Author: Harsh
 */


#include<stdio.h>
#include<string.h>

/*
// Algorithm:
Following is a general recursive solution with all cases handled.

// Every single character is a palindrome of length 1
L(i, i) = 1 for all indexes i in given sequence

// IF first and last characters are not same
If (X[i] != X[j])  L(i, j) =  max{L(i + 1, j),L(i, j - 1)}

// If there are only 2 characters and both are same
Else if (j == i + 1) L(i, j) = 2

// If there are more than two characters, and first and last
// characters are same
Else L(i, j) =  L(i + 1, j - 1) + 2
*/




// A utility function to get max of two integers
int max (int x, int y) { return (x > y)? x : y; }

// Returns the length of the longest palindromic subsequence in seq
int lps_Recursion(char *seq, int i, int j) {

   // Base Case 1: If there is only 1 character
   if (i == j)
     return 1;

   // Base Case 2: If there are only 2 characters and both are same
   if (seq[i] == seq[j] && i + 1 == j)
     return 2;

   // If the first and last characters match
   if (seq[i] == seq[j])
      return lps_Recursion(seq, i+1, j-1) + 2;

   // If the first and last characters do not match
   // Then check if there is a longest palindrome in rest of the characters
   // Compare and take the max of the 2
   return max( lps_Recursion(seq, i, j-1), lps_Recursion(seq, i+1, j) );
}

/*
DYNAMIC PROGRAMMING:

Following is a partial recursion tree for a sequence of length 6 with all different characters.


               L(0, 5)
             /        \
            /          \
        L(1,5)          L(0,4)
       /    \            /    \
      /      \          /      \
  L(2,5)    L(1,4)  L(1,4)  L(0,3)

In the above partial recursion tree,
L(1, 4) is being solved twice.

If we draw the complete recursion tree,
then we can see that there are many subproblems which are solved again and again.

Since same subproblems are called again, this problem has Overlapping Subproblems property.
*/


// Returns the length of the longest palindromic subsequence in seq
int lps(char *str){
   int n = strlen(str);
   int i, j, cl;  // cl = Length of the Substring
   int L[n][n];  // Create a table to store results of subproblems


   // Strings of length 1 are palindrome of length 1
   for (i = 0; i < n; i++)
      L[i][i] = 1;

    // Build the table. Note that the lower diagonal values of table are
    // useless and not filled in the process.
    // The values are filled in a manner similar to Matrix Chain Multiplication DP
    // solution (See https://www.geeksforgeeks.org/archives/15553).
    // cl is length of substring
    for (cl=2; cl<=n; cl++) {
        for (i=0; i<n-cl+1; i++) {
            j = i+cl-1;
            if (str[i] == str[j] && cl == 2)
               L[i][j] = 2;
            else if (str[i] == str[j])
               L[i][j] = L[i+1][j-1] + 2;
            else
               L[i][j] = max(L[i][j-1], L[i+1][j]);
        }
    }

    return L[0][n-1];
}

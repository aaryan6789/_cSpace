/*
 * is_subsequence.c
 *
 *  Created on: May 3, 2018
 *      Author: Harsh
 */
#define bool int
#define true 1;
#define false 0

// Returns true if str1[] is a subsequence of str2[]. m is
// length of str1 and n is length of str2
bool isSubSequence(char str1[], char str2[], int m, int n) {
   int j = 0; // For index of str1 (or subsequence

   // Traverse str2 and str1, and compare current character
   // of str2 with first unmatched char of str1, if matched
   // then move ahead in str1
   for (int i=0; i<n && j<m; i++)
       if (str1[j] == str2[i])
         j++;

   // If all characters of str1 were found in str2
   return (j==m);
}

/* The idea is simple, we traverse both strings from one side to other side
 * (say from rightmost character to leftmost).
 *
 * If we find a matching character, we move ahead in both strings.
 * Otherwise we move ahead only in str2.
 */
// Returns true if str1[] is a subsequence of str2[].
// m is length of str1 and n is length of str2
bool isSubSequenceRecursive(char str1[], char str2[], int m, int n)
{
    // Base Cases
    if (m == 0)
    	return true;
    if (n == 0)
    	return false;

    // If last characters of two strings are matching then
    // check for the rest of the characters in both strings
    if (str1[m-1] == str2[n-1])
        return isSubSequence(str1, str2, m-1, n-1);

    // If last characters are not matching then check for the rest of the characters in the
    // bigger string
    return isSubSequence(str1, str2, m, n-1);
}



bool isSubsequencePointers(char* s, char* t){
    if (*s == '\0')
        return true;

    char *p = s;
    // Iterate through the string s untill t becomes null
    while(*t != '\0') {
        // If the characters are matching then keep on iterating
        while (*p != '\0' && *t != '\0' && *p == *t){
            t++;
            p++;
        }
        // If all the characters in s matches then it would be null here
        if (*p == '\0')
            return true;

        // Else move on in t
        t++;
    }

    return false;

}

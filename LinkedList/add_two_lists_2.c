/*
 * add_two_lists_2.c
 *
 *  Created on: Apr 29, 2018
 *      Author: Harsh
 */

/*
Recursion is used here to calculate sum from right to left.

Following are the steps.
1) Calculate sizes of given two linked lists.
2) If sizes are same, then calculate sum using recursion.
	Hold all nodes in recursion call stack till the rightmost node,
	calculate sum of rightmost nodes and forward carry to left side.
3) If size is not same, then follow below steps:
	a) Calculate difference of sizes of two linked lists.
		Let the difference be diff
	b) Move diff nodes ahead in the bigger linked list.
		Now use step 2 to calculate sum of smaller list and right sub-list(of same size) of larger list.
		Also, store the carry of this sum.
	c) Calculate sum of the carry (calculated in previous step)
		with the remaining left sub-list of larger list.
		Nodes of this sum are added at the beginning of sum list obtained previous step.
*/



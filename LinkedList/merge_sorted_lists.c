/* merge_sorted_lists.c *  Created on: Apr 28, 2018 *      Author: Harsh */
#include <stdio.h>
#include <stdlib.h>

#include "_linked_list.h"

/* Merge 2 Sorted Lists
 * CTCI 6.5.2 | LeetCode Easy
 * Given 2 sorted Linked Lists. Merge them in order.
 * Example:
 * 1->2->4		== 1->1->2->3->4->4
 * 1->3->4
 *
 * Algorithm:
 * 1. Set up a false "resultHead" node that allows us to easily return the head of the merged list later.
 *    Maintain a prev pointer, which points to the current node for which we are considering
 *    adjusting its next pointer.
 *
 * 2. Then, we do the following until at least one of l1 and l2 points to null:
 *    if the value at l1 is less than or equal to the value at l2,
 *        then we connect l1 to the previous node and increment l1.
 *    Otherwise, we do the same, but for l2.
 *
 * 3. Then, regardless of which list we connected, we increment prev to keep it one step behind
 *    one of our list heads.
 *
 * 4. After the loop terminates, at most one of l1 and l2 is non-null.
 * Therefore (because the input lists were in sorted order),
 * if either list is non-null, it contains only elements greater than all of the
 * previously-merged elements.
 *
 * This means that we can simply connect the non-null list to the merged list and return it.
 */

/* Time Complexity:
 * O(m + n) == Length of both the lists
 * O(1) Space complexity
 */

// Iterative Solution
struct node* mergeTwoLists(struct node* l1, struct node* l2) {
    if(l1 == NULL && l2 == NULL)
        return NULL;

    if(l2 == NULL)
        return l1;

    if(l1 == NULL)
        return l2;

    // Declare a node with the resulting linked list
    struct node resultHead;
    struct node* prev = &resultHead;		// Keep the address of the resultHead in the prev

    while(l1 != NULL && l2 != NULL) {
        if(l1->data <= l2->data){
            prev->next = l1;
            l1 = l1->next;
        }
        else{
            prev->next = l2;
            l2 = l2->next;
        }
        // Move prev pointer ahead
        prev = prev->next;
    }

    // Exactly one of l1 and l2 can be non-null at this point, so connect
    // the non-null list to the end of the merged list.
    prev->next = (l1 == NULL ? l2 : l1);

    return resultHead.next;
}

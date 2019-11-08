/* pair_wise_swap.c  * Created on: Jul 17, 2018 * Author: Harsh */
#include "_linked_list.h"

/* LeetCode | M
 * Given a linked list, swap every two adjacent nodes and return its head.

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
Note:

Your algorithm should use only constant extra space.
You may not modify the values in the list's nodes, only nodes itself may be changed.
 */

struct node* swapPairs(struct node* head) {
    // Return early if no nodes or 1 node
    if(head == NULL || head->next == NULL)
        return head;

    struct node *first = head;
    struct node *second = head->next;
    head = second;

    while (second != NULL){

        struct node *temp = second->next;
        second->next = first;

        if(temp==NULL || temp->next==NULL){
            first->next = temp;
            return head;
        }

        first->next = temp->next;
        first = temp;
        second = first->next;
    }
    return head;
}

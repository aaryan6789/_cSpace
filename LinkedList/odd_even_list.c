/* odd_even_list.c  * Created on: Jul 17, 2018 * Author: Harsh */
#include "_linked_list.h"
/* LeetCode | M | 328
 * Given a singly linked list, group all odd nodes together followed by the even nodes.
 * Please note here we are talking about the node number and not the value in the nodes.
 *
 * You should try to do it in place.
 * The program should run in O(1) space complexity and O(nodes) time complexity.
 *
 * Example 1:
 * Input: 1->2->3->4->5->NULL
 * Output: 1->3->5->2->4->NULL
 *
 * Example 2:
 * Input: 2->1->3->5->6->4->7->NULL
 * Output: 2->3->6->7->1->5->4->NULL
 *
 * Note:
 * The relative order inside both the even and odd groups should remain as it was in the input.
 * The first node is considered odd, the second node even and so on ...
 */
struct node* oddEvenList(struct node* head) {
    printf("-------  %s  --------- \n", __func__);
    // Return early
    if(head == NULL || head->next == NULL || (head->next)->next == NULL){
        return head;
    }

    // Following the same approach as the linked list value separation
    struct node* evenHead = NULL;
    struct node* oddHead = NULL;
    struct node* evenTail;
    struct node* oddTail;
    struct node* current = head;
    struct node* next;

    while(current != NULL) {            //<-- Pay Attention here
        if(current->next){
            next = current->next;
        }
        //else{
        //    next = NULL;
        //}

        // Populate the OddList
        if(oddHead == NULL){
            oddHead = oddTail = current;
        }
        else{
            oddTail->next = current;
            oddTail = current;
        }

        if(next){
            // Populate the even List
            if(evenHead == NULL){
                evenHead = evenTail = next;
            }
            else{
                evenTail->next = next;
                evenTail = next;
            }
        }

        // Move to the next Curent node
        if((current->next != NULL) && ((current->next)->next != NULL)){
            current = current->next->next;
        }
        else{
            current = NULL;         // <--- Pay Attention here, loop terminating condition
        }

    }

    // Now make the List connections
    // List Termination
    if(evenTail != NULL){
        evenTail->next = NULL;
    }

    if(oddHead){
        oddTail->next = evenHead;
    }
    else{
        return evenHead;
    }

    return oddHead;
}

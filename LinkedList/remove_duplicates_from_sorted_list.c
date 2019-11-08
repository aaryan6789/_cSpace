/*
 * remove_duplicates_from_sorted_list.c
 *
 *  Created on: Apr 28, 2018
 *      Author: Harsh
 */
#include <stdio.h>
#include <stdlib.h>

#include "_linked_list.h"

/* LeetCode Easy
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
Example 1:
Input: 1->1->2
Output: 1->2

Example 2:
Input: 1->1->2->3->3
Output: 1->2->3
 */
struct node* deleteDuplicatesI(struct node* head) {
    struct node* current = head;
    struct node* next_next = NULL;

    if(head == NULL || head->next == NULL)
        return head;

    // Since its a Sorted Linked list so we just have to
    // traverse the list and compare the data item with the next nodes data.
    while(current->next != NULL) {
        // Compare the data with the next nodes data
        if( current->data == current->next->data){
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }
        else {
            // If the data is not equal then move forward
            current = current->next;
        }
    }

    return head;
}

/* LeetCode Medium
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 * Example 1:
 * Input: 1->2->3->3->4->4->5 -------->>>>> Output: 1->2->5
 *
 * Example 2:
 * Input: 1->1->1->2->3    ----------->>>>> Output: 2->3
 *
 */
void removeAllDuplicates(struct node* head) {
   /* create a dummy node that acts like a fake
	  head of list pointing to the original head*/
	struct node dummy;

	/* dummy node points to the original head*/
	dummy.next = head;
	struct node* prev = &dummy;		// Address of dummy node in the prev pointer
	struct node* current = head;

	while (current != NULL) {
		/* Until the current and previous values
		   are same, keep updating current */
		while (current->next != NULL && (prev->next->data == current->next->data)){
			current = current->next;
		}

		/* if current has unique value i.e current is not updated,
		 * Move the prev pointer to next node*/
		if (prev->next == current){
			prev = prev->next;
		}
		else{
			/* when current is updated to the last duplicate value of that segment,
			 * make prev the next of current*/
			prev->next = current->next;
		}
		current = current->next;
	}

	/* update original head to the next of dummy node */
	head = dummy.next;
}



// Function to free the deleted nodes from memory
void freeNodes(struct node *strt, struct node *end){

	if(strt->next != end)
		freeNodes(strt->next, end);

	free(strt);
}

// Function to delete all occurrences of duplicate nodes
void deleteDuplicateII(struct node **head_ref){

    struct node dummy;					// Fake Head
    struct node* prev = &dummy;         // Get the address of the dummy node in the prev
    struct node* curr = (*head_ref);        // current

	dummy.next = (*head_ref);	// Adding a node (named dummy) before head of Linked List

	while((curr != NULL) && (curr->next != NULL)){
		// If duplicate nodes found
		if(curr->data == curr->next->data){
			curr = curr->next;
		}
		else if(prev->next == curr){
		    prev = curr;
			curr = curr->next;
		}
		else{
		    curr = curr->next;
			freeNodes(prev->next, curr);
			prev->next = curr;
		}
	}

	if(prev->next != curr){
	    curr = curr->next;
		freeNodes(prev->next, curr);
		prev->next = curr;
	}

	*head_ref = dummy.next;
}

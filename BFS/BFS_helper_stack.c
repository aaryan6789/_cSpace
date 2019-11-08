/* BFS_helper_stack.c  * Created on: Jun 10, 2018 * Author: Harsh */
#include "BFS.h"
/* Structure to represent a Stack (by a Linked List)
struct Lstack{
	int data;
	struct Lstack *next;
};
*/

/**
 * Lpush - Push an item on the Stack by Linked List
 * Since we are using a Linked List every time we push an item we have to move
 * the head pointer to point to this new node as this will be the item that will
 * be popped off first.
 */
void Lpush(struct Lstack** head_ref, int data){
	// Allocate memory for a new Stack node
	struct Lstack* newstackNode = (struct Lstack*)malloc(sizeof(struct Lstack));

	//Fill in the data
	newstackNode->data = data;

	// Make Links now
	// 1. the next of the new stack node will be the previous top_node/head
	newstackNode->next = (*head_ref);

	// 2. The New Stack node will be the new Head now.
	*head_ref = newstackNode;

	printf("Pushed %d on Stack by Linked List.\n", data);
	return;
}

/**
 * Lpop - Pop an item from the Stack by Linked List
 * Popping an item from the Stack will not only change the the Head pointer
 * but also removes the node.
 * We should also make sure we are freeing up the node on popping.
 */
int Lpop(struct Lstack** head_ref){

	if((*head_ref) == NULL){
		printf("Stack is Empty. Can't pop anything.\n");
		return -1;
	}

	// Get the head in a temp node as head is gonna change
	struct Lstack *temp = *head_ref;

	int top = temp->data;
	*head_ref = temp->next;
	free(temp);

	printf("Popping %d from Stack.\n", top);
	return top;
}

/**
 * Ltop - Get the top element of the stack
 */
int Ltop(struct Lstack* head) {
	// LStack's head always points to the top most element in the stack.
    if (head == NULL){
    	printf("LStack is empty. No top element to retrieve.\n");
    	return INT_MIN;
    }
    else {
    	return head->data;
    }
}

/**
 * isLStackEmpty - check if the Stack by LL is empty or not.
 * @head: head/top of the Stack
 * @return: 0 if its empty or 1 if its not
 */
int isLStackEmpty(struct Lstack *head){
	if(head == NULL){
		return 1;
	}
	else{
		return 0;
	}
}

/**
 * print_Lstack - Print the Stack by LL
 */
void print_Lstack(struct Lstack* top){
	printf("\n");
	while(top != NULL){
		printf("%d\n |\n v\n", top->data);
		top = top->next;
	}
	return;
}

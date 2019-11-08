#include "_linked_list.h"


void p_deleteN_afterM(struct node* head, int n, int m){
    struct node* current = head;

    for(int i =0; i< m-1 && current != NULL; i++){
        current = current->next;
    }

    struct node* mth = current;
    printf("mth = %d\n", mth->data);
    struct node* mplus1 = current->next;

    current = mplus1;
    for(int i = 0; i<n; i++){
        printf("current = %d\n", current->data);
        struct node* temp = current->next;
        free(current);
        current = temp;
    }

    struct node* nplus1 = current;
    printf("nplus1 = %d\n", nplus1->data);

    mth->next = nplus1;

}






/* Rotate a SLL counter clockwise by K nodes, where k is a Positive integer.
 * I/p= 10->20->30->40->50->60 K = 4
 * O/p= 50->60->10->20->30->40
 */
void p_rotateList(struct node** head_ref, int k){
    // Rotate a Linked List by K nodes
    struct node* kplus1;
    struct node* kth;
    struct node* current = *head_ref;
    struct node* first = *head_ref;

    for(int i = 0; i<k-1 && current!= NULL; i++){
        current = current->next;
        printf("current = %d\n", current->data);
    }

    kth = current;
    kplus1 = current->next;

    printf("1 current = %d\n", current->data);
    while(current->next != NULL){
        current = current->next;
    }
    printf("2 current = %d\n", current->data);
    current->next = first;
    kth->next = NULL;

    *head_ref = kplus1;
}

// Remove Duplicates from the List
// Dummy Node Concept
struct node* p_removeDuplicates(struct node* head){

    struct node resultHead;
    resultHead.next = head;

    struct node* prev = &resultHead;
    struct node* current = head;

    while( current != NULL){
        // Duplicates can be in the Front itself
        // So keep moving the current node to the first not duplicate value
        while( (current->next != NULL) &&
               (prev->next->data == current->next->data)){
            current = current->next;
        }

        // If the duplicate was not present in the front, so check here
        if(prev->next == current){
            prev = prev->next;
            current = current->next;
        }
        else{
            prev->next = current->next;
            current = current->next;
        }

    }

    head = resultHead.next;
    return head;


}

// Merge 2 Sorted Lists
// Dummy Node concept in which a node is created to keep the address of the resultant list head in the beginning itself
struct node* p_mergeSortedLists(struct node* l1, struct node* l2){
    if(l1 == NULL && l2 == NULL)
        return NULL;

    if(l1 == NULL)
        return l2;

    if(l2 == NULL)
        return l1;

    struct node resultHead;     // Thisis pointing to the head of the resultant list
    struct node* prev = &resultHead;    // Store the address of the result list head in this

    // Since both the lists are sorted so we have to chose which one to pick first
    while( l1 != NULL && l2 != NULL){
        if(l1->data < l2->data){
            prev->next = l1;
            l1 = l1->next;
        }
        else{
            prev->next = l2;
            l2 = l2->next;
        }
        prev = prev->next;
    }

    prev->next = (l1 == NULL) ? l2 : l1;

    return resultHead.next;
}

// Insert in a sorted List
void insertSortedP(struct node** head_ref, int val){
    printf("Practice: Insert in sorted List");
    struct node* current = *head_ref;
    struct node* next = NULL;
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;

    // If its in the head itself
    if(current == NULL || current->data >= val){
        newNode->next = current;
        *head_ref = newNode;
        return;
    }

    // In the middle or in the end
    while(current->next != NULL && current->next->data <= val){
        current = current->next;
    }

    // current is the place where you need to put the newNode
    next = current->next;
    newNode->next = next;
    current->next = newNode;
}

// Delete a node given only pointer to that node
void deleteNodeP(struct node* node_ptr){
    struct node* temp;

    temp = node_ptr->next;
    node_ptr->data = temp->data;
    node_ptr->next = temp->next;
    free(temp);
}

// Cycle in a Linked list or not
void detectCycleP(struct node** head_ref){
    // Floyd Cycle Algorithm

    if(*head_ref == NULL || (*head_ref)->next == NULL){
        printf("Cycle not present\n");
        return;
    }

    struct node* slow = *head_ref;
    struct node* fast = *head_ref;

    while(fast != NULL || fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            printf("There is a Cycle in the List\n");
            break;
        }
    }
    printf("Cycle not present\n");
}

// Reverse a Singly Linked list
void reverseListP(struct node** head_ref){
    struct node* current = *head_ref;
    struct node* prev = NULL;
    struct node* next;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head_ref = prev;
}

// Sorted Linked List
// Delete Duplicate elements and they appear only once
void removeDupElementsP1(struct node** head_ref){
    if(*head_ref == NULL || (*head_ref)->next == NULL){
        return;
    }

    struct node* current = *head_ref;
    struct node* next_next = NULL;

    while(current->next != NULL){
        if(current->data == current->next->data){
            next_next = current->next->next;        // Cache the next next node
            current->next->data = next_next->data;
            current->next->next = next_next->next;
            free(next_next);
        }
        else{
            current = current->next;
        }
    }

    return;
}

/** Remove Elements of a given value from a linked list */
struct node* removeElementsP(struct node* head, int val){
    if(head == NULL){
        return head;
    }

    struct node* current = head;
    struct node* prev;
    struct node* temp = NULL;       // Important if we want to free the memory location

    // Case 1: When the node is at head itself
    // Case 2: When the node is in the end
    // Case 3: When the node is in the middle somewhere

    // Case 1: 1->1->1->2->3
    while(current != NULL && current->data == val){
        if (current->next == NULL)      // If linked list is just full of val nodes
            return NULL;

        temp = current->next;       // Cache the next node to free it later gracefully
        current->data = temp->data;
        current->next = temp->next;
        free(temp);
        head = current;             // Update head so we can return it
    }

    // Case 2 and 3
    while(current != NULL){
        while(current !=NULL && current->data != val){
            prev = current;
            current = current->next;
        }

        // I freached to the end of the list return then
        if(current == NULL){
            return head;
        }

        // Here current->data = val
        prev->next = current->next;
        free(current);
        current = prev->next;
    }

    return head;
}
/* reverse_list.c  * Created on: Jul 19, 2018 * Author: Harsh */
#include "_linked_list.h"

//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* next;
    struct ListNode* current = head;

    while (current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    if(head == NULL || head->next == NULL)
        return head;

    struct ListNode* current = head;
    struct ListNode* before_m = NULL;
    struct ListNode* mth;
    struct ListNode* after_n;
    struct ListNode* nth;

    // Populate the mth and nth nodes
    // Observe how in just one while node we can populate all the needed nodes
    int i = 1;
    while(current && i<=n){
        if(i<m)
            before_m = current;

        if(i==m)
            mth = current;

        if(i==n){
            nth = current;
            after_n = current->next;
        }

        current = current->next;
        i++;
    }

    // Disconnect the Sub List nth->next -- X
    nth->next = NULL;

    // Reverse the SubList
    nth = reverseList(mth);

    // If the Sub list is in the middle of a linked List
    if(before_m)
        before_m->next = nth;
    else
        head = nth;     // If the sublist starts from the head node itslef

    mth->next = after_n;

    return head;
}

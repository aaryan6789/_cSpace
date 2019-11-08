/*
 * plus_one.c
 *
 *  Created on: Apr 29, 2018
 *      Author: Harsh
 */
#include <stdio.h>
#include <stdlib.h>

#include "_linked_list.h"

/**
 * Definition for singly-linked list.*/
 struct ListNode {
     int val;
     struct ListNode *next;
 };

/*
Method 1: Iterative + Reversal
1. Reverse the linked list
2. Add 1 and carry forward the carry to reset of the linke dlist
3. Reverse the result list again

Time Complexity = 3*O(n) ~~ O(n)

Method 2 : Recursion
*/



typedef struct ListNode node;

node* plusOneRecursively(node* head, int* carry){
    if (head == NULL){
        return NULL;
    }

    int sum;
    int add;

    node* result = (node*)malloc(sizeof(node));

    result->next = plusOneRecursively(head->next, carry);

    // add 1 to current node and propagated carry
    sum = head->val + *carry;
    *carry = sum / 10;
    sum = sum % 10;

    result->val = sum;
    //printf("Carry = %d\n", *carry);

    return result;
}



struct ListNode* plusOne(struct ListNode* head) {
    int carry = 1;
    node* res =  plusOneRecursively(head, &carry);

    if(head->val != 0 && res->val == 0){
        node* newNode = (node*)malloc(sizeof(node));
        newNode->val = 1;
        newNode->next = res;
        return newNode;

    }
    else{
        return res;
    }
}

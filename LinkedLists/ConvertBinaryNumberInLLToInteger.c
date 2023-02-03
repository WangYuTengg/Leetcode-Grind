/** 
Given head which is a reference node to a singly-linked list. 
The value of each node in the linked list is either 0 or 1. 
The linked list holds the binary representation of a number.
Return the decimal value of the number in the linked list.
The most significant bit is at the head of the linked lis
*/

#include <stdio.h>
#include <math.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

int getDecimalValue(struct ListNode* head){
    int result;
    while (head != NULL)
    {
        result = result*2;
        result += head->val;
        head = head->next;
    }
    return result;
}
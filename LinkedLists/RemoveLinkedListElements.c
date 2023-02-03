/**
 * Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
*/

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode* temp;
    // remove head if same element as val until we start on a diff val
    while (head != NULL && head->val == val){
        temp = head;
        head = head->next;
        free(temp);
    }
    
    struct ListNode* cur=head;

    // main loop, does not check for head
    while (cur != NULL && cur->next != NULL) {
        if (cur->next->val == val){
            temp = cur->next;
            cur->next = temp->next;
            free(temp);
        }
        else {
            cur = cur->next;
        }
    }
    
    return head;
}
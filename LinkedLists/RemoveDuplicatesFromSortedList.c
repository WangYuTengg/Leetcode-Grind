/**
 * Given the head of a sorted linked list, 
 * delete all duplicates such that each element appears only once. 
 * Return the linked list sorted as well.
*/
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode * curr = head;
    struct ListNode * temp;
    while (curr != NULL && curr->next != NULL)
    {
        if (curr->next->val == curr->val)
        {
            temp = curr->next;
            curr->next = temp->next;
            free(temp);
        }
        else {
            curr = curr->next;
        }
    }
    return head;
}
#include <stdio.h>
/**
Given the head of a linked list, return the node where the cycle begins. 
If there is no cycle, return null.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed).
It is -1 if there is no cycle. Note that pos is not passed as a parameter.
Do not modify the linked list.
*/
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *head){
    struct ListNode * fast=head;
    struct ListNode * slow=head;
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast) return slow;
    }
    return NULL;
}
struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) return NULL;
    struct ListNode* intersect = getIntersectionNode(head);
    if (intersect == NULL) return NULL;
    while (intersect != head) {
        head = head->next;
        intersect = intersect->next;
    }
    return intersect;

/**
 * Explanation: https://leetcode.com/problems/intersection-of-two-linked-lists/solutions/1092898/js-python-java-c-easy-o-1-extra-space-solution-w-visual-explanation/
 * Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect.
 * If the two linked lists have no intersection at all, return null.
*/

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* curA = headA;
    struct ListNode* curB = headB;

    while (curA != curB){
        if (curA == NULL) curA = headB;
        else if (curA != NULL) curA = curA->next;
        if (curB == NULL) curB = headA;
        else if (curB !=NULL) curB = curB->next;
    }
    return curA;
}
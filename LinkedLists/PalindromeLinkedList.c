#include <stdio.h>
#include <stdbool.h>
/**
Given the head of a singly linked list, return true if it is a 
palindrome or false otherwise.
*/
struct ListNode {
    int val;
    struct ListNode *next;
};

bool isPalindrome(struct ListNode* head){
	struct ListNode* fast = head;
    struct ListNode* slow = head;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    //reverse second half
    struct ListNode* prev = NULL;
    struct ListNode* next;
    while(slow != NULL){
        next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }

    //check palindrome
    fast = head; // fast as left starting pointer
    slow = prev; // slow as right starting pointer
    while (fast != NULL && slow != NULL){
        if (fast->val != slow->val) return false;
        fast = fast->next;
        slow = slow->next;
    }
    return true;
}
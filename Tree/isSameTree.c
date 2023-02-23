/**
Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
*/

#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    // case 1 -> where both reach the end of a branch
    if (p == NULL && q == NULL) return true;

    // case 2 -> check for equal value -> recursively call on left and right subtree
    if ((p != NULL && q != NULL) && (p->val == q->val)) {
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    } else {
        return false;
    }
}
/**
Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

 // recursive DFS
int maxDepth(struct TreeNode* root){
    // base case
    if (root == NULL) return 0; 

    // recursively call the function on left and right branches
    int maxDepthLeft = maxDepth(root->left);
    int maxDepthRight = maxDepth(root->right);
    int max;
    if (maxDepthLeft > maxDepthRight){
        max = maxDepthLeft + 1; // increment depth
    } else{
        max = maxDepthRight + 1; // increment depth
    }
    return max;
}
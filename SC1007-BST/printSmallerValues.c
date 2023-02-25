
// #define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////

typedef struct _btnode
{
    int item;
    struct _btnode *left;
    struct _btnode *right;

} BTNode;

////////////////////////////////////////////////////////////////////

void mirrorTree(BTNode *node);
void printSmallerValues(BTNode *node, int m);
int smallestValue(BTNode *node);
int hasGreatGrandchild(BTNode *node);
void printTree_InOrder(BTNode *node);

////////////////////////////////////////////////////////////////////

int main(int argc, const char *argv[])
{

    int i;
    // char reply;

    BTNode *root, *root2;
    BTNode btn[15];

    // Create the tree in Q1
    // Using manual dynamic allocation of memory for BTNodes

    root = malloc(sizeof(BTNode));
    root->item = 4;

    root->left = malloc(sizeof(BTNode));
    root->left->item = 5;

    root->right = malloc(sizeof(BTNode));
    root->right->item = 2;

    root->left->left = NULL;

    root->left->right = malloc(sizeof(BTNode));
    root->left->right->item = 6;

    root->left->right->left = NULL;
    root->left->right->right = NULL;

    root->right->left = malloc(sizeof(BTNode));
    root->right->left->item = 3;

    root->right->right = malloc(sizeof(BTNode));
    root->right->right->item = 1;

    root->right->left->left = NULL;

    root->right->left->right = NULL;

    root->right->right->left = NULL;

    root->right->right->right = NULL;

    // question 2
    printf("\n input m for question 2:");
    scanf("%d", &i);
    printf("the values smaller than %d are:", i);
    printSmallerValues(root, i);
    printf("\n\n");
}

//////////////////////////////////////////////////////////////////////////////////////////////////

void printSmallerValues(BTNode *node, int m)
{
    if (node == NULL)
        return;
    if (node->item < m)
        printf("%d ", node->item);
    printSmallerValues(node->right, m);
    printSmallerValues(node->left, m);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void printTree_InOrder(BTNode *node)
{

    if (node == NULL)
        return;
    printTree_InOrder(node->left);
    printf("%d, ", node->item);
    printTree_InOrder(node->right);
    return;
}

///////////////////////////////////////
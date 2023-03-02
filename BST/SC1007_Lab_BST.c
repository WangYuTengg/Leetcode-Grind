//////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////////

typedef struct _btnode
{
    int item;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

///////////////////////////////////////////////////////////////////////

void insertBSTNode(BTNode **node, int value);
void printBSTInOrder(BTNode *node);
int isBST(BTNode *node, int min, int max);
BTNode *removeBSTNode(BTNode *node, int value);
BTNode *findMin(BTNode *p);

///////////////////////////////////////////////////////////////////////

int main()
{
    int i = 0;

    BTNode *root = NULL;

    // question 1
    do
    {
        printf("input a value you want to insert(-1 to quit):");

        scanf("%d", &i);
        if (i != -1)
            insertBSTNode(&root, i);
    } while (i != -1);

    // question 2
    printf("\n");
    printBSTInOrder(root);

    // question 3
    if (isBST(root, -1000000, 1000000) == 1)
        printf("It is a BST!\n");
    else
        printf("It is not a BST!\n");

    // question 4
    do
    {
        printf("\ninput a value you want to remove(-1 to quit):");
        scanf("%d", &i);
        if (i != -1)
        {
            root = removeBSTNode(root, i);
            printBSTInOrder(root);
        }
    } while (i != -1);

    return 0;
}

//////////////////////////////////////////////////////////////////////

void insertBSTNode(BTNode **node, int value)
{
    // base case / empty tree
    if (*node == NULL)
    {
        *node = malloc(sizeof(BTNode));
        (*node)->item = value;
        (*node)->right = NULL;
        (*node)->left = NULL;
        return;
    }
    else
    {
        if (value < (*node)->item)
        {
            insertBSTNode(&((*node)->left), value);
        }
        else if (value > (*node)->item)
        {
            insertBSTNode(&((*node)->right), value);
        }
        else
        {
            return;
        }
    }
}

//////////////////////////////////////////////////////////////////////

void printBSTInOrder(BTNode *node)
{
    if (node != NULL)
    {
        printBSTInOrder(node->left);
        printf("%d ", node->item);
        printBSTInOrder(node->right);
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int isBST(BTNode *node, int min, int max) // the item stored in node has to be smaller than max and larger than min
{
    if (node == NULL)
        return 1;
    if (node->item > max || node->item < min)
        return 0;
    return isBST(node->left, min, node->item) && isBST(node->right, node->item, max);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BTNode *removeBSTNode(BTNode *node, int value)
{
    // 3 cases
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BTNode *findMin(BTNode *p)
{
    // recur down the left subtree
    if (p->left != NULL)
        return findMin(p->left);
    // if p= null, return null, if p->left=null, means p is smallest
    else
        return p;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
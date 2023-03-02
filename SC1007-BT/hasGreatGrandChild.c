
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

	// question 4
	//  Create a tree for Q4: Tall enough so some nodes have great-grandchildren
	//  Use array of BTNodes, create tree by linking nodes together
	for (i = 0; i <= 6; i++)
	{
		btn[i].item = i;
		btn[i].left = &(btn[i * 2 + 1]);
		btn[i].right = &(btn[i * 2 + 2]);
	}

	for (i = 7; i <= 14; i++)
	{
		btn[i].item = i;
		btn[i].left = NULL;
		btn[i].right = NULL;
	}
	root2 = &btn[0];

	printf("The tree for question 4 visited by in-order is \n");
	printTree_InOrder(root2);
	printf("\nthe values stored in all nodes of the tree that have at least one great-grandchild are: ");
	hasGreatGrandchild(root2);
}

//////////////////////////////////////////////////////////////////////////////////////////////////

int hasGreatGrandchild(BTNode *node)
{
	if (node == NULL)
	{
		return -1;
	}
	int l = hasGreatGrandchild(node->left);
	int r = hasGreatGrandchild(node->right);
	if (r > 1)
	{
		l = r;
	}
	if (l > 1)
	{
		printf("%d ", node->item);
	}
	return l + 1;
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

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left, *right;
} node;

// function to create new node
struct node *newNode(int item)
{
    struct node *temp = malloc(sizeof(node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// function to insert node into BST
// time complexity O(N) , N is number of nodes in BST
struct node *insert(struct node *node, int key)
{
    // if tree is empty
    if (node == NULL)
        return newNode(key);

    // otherwise, recur down the tree
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }

    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    return node;
}

// function for inorder traversal of BST -> visit left child, then root, then right child
// in the case of BST, inorder traversals give nodes in ascending order
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// preorder traversal -> visit root, then left child, then right child
// used to create a copy of the tree + prefix esxpression on an expression tree
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

// postorder traversal -> visit left, then right, then root
// used to delete the tree -> visit the root of every subtree last
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

// main driver code
int main()
{
    /* Let us create following BST
             50
          /     \
         30      70
        /  \    /  \
      20   40  60   80
  */
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("\nIn order: ");
    inorder(root);
    printf("\nPre order: ");
    preorder(root);
    printf("\nPost oder: ");
    postorder(root);

    return 0;
}
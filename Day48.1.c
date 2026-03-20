#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct node {
    int data;
    struct node *left, *right;
};

// Create new node
struct node* createNode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

// Count leaf nodes
int countLeaf(struct node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeaf(root->left) + countLeaf(root->right);
}

// Example tree
int main() {
    /*
            1
          /   \
         2     3
        / \     \
       4   5     6
    */

    struct node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    int leafCount = countLeaf(root);

    printf("Number of leaf nodes = %d\n", leafCount);

    return 0;
}
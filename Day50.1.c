#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// BST Search function (recursive)
struct Node* search(struct Node* root, int key) {
    // Base case
    if (root == NULL || root->data == key)
        return root;

    // Search in left subtree
    if (key < root->data)
        return search(root->left, key);

    // Search in right subtree
    return search(root->right, key);
}
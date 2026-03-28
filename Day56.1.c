#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Function to check mirror
int isMirror(struct TreeNode* left, struct TreeNode* right) {
    if (left == NULL && right == NULL) return 1;
    if (left == NULL || right == NULL) return 0;

    return (left->val == right->val) &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

// Main symmetric check
int isSymmetric(struct TreeNode* root) {
    if (root == NULL) return 1;
    return isMirror(root->left, root->right);
}
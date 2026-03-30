/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int findIndex(int* inorder, int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

struct TreeNode* buildHelper(int* preorder, int* inorder, int start, int end, int* preIndex) {
    if (start > end)
        return NULL;

    // Create root node
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[*preIndex];
    root->left = root->right = NULL;

    (*preIndex)++;

    // If only one node
    if (start == end)
        return root;

    // Find root in inorder
    int inIndex = findIndex(inorder, start, end, root->val);

    // Build left and right subtrees
    root->left = buildHelper(preorder, inorder, start, inIndex - 1, preIndex);
    root->right = buildHelper(preorder, inorder, inIndex + 1, end, preIndex);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    int preIndex = 0;
    return buildHelper(preorder, inorder, 0, inorderSize - 1, &preIndex);
}
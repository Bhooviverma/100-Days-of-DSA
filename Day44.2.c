void preorder(struct TreeNode* root, int* arr, int* size){
    if(root == NULL)
        return;

    arr[*size] = root->val;
    (*size)++;
    
    preorder(root->left, arr, size);
    preorder(root->right, arr, size);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* arr = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;
    preorder(root, arr, returnSize);
    return arr;
}
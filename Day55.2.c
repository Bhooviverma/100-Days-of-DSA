int* rightSideView(struct TreeNode* root, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    struct TreeNode* queue[10000];
    int front = 0, rear = 0;

    int* result = (int*)malloc(sizeof(int) * 10000);
    *returnSize = 0;

    // push root
    queue[rear++] = root;

    while (front < rear) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];

            // last node of this level
            if (i == size - 1) {
                result[*returnSize] = node->val;
                (*returnSize)++;
            }

            if (node->left)
                queue[rear++] = node->left;
            if (node->right)
                queue[rear++] = node->right;
        }
    }

    return result;
}
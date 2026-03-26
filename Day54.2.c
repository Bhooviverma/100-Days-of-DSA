/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    // Queue for BFS
    struct TreeNode* queue[2000];
    int front = 0, rear = 0;
    
    queue[rear++] = root;

    int** result = (int**)malloc(sizeof(int*) * 1000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 1000);

    int level = 0;
    int leftToRight = 1;

    while (front < rear) {
        int size = rear - front;

        int* row = (int*)malloc(sizeof(int) * size);

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];

            // Zigzag index logic
            int index;
            if (leftToRight)
                index = i;
            else
                index = size - 1 - i;

            row[index] = node->val;

            if (node->left)
                queue[rear++] = node->left;

            if (node->right)
                queue[rear++] = node->right;
        }

        result[level] = row;
        (*returnColumnSizes)[level] = size;

        level++;
        leftToRight = !leftToRight;
    }

    *returnSize = level;
    return result;
}
#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Queue structure
struct Queue {
    struct TreeNode* arr[100];
    int front, rear;
};

// Initialize queue
void initQueue(struct Queue* q) {
    q->front = q->rear = -1;
}

// Check if queue is empty
int isEmpty(struct Queue* q) {
    return q->front == -1;
}

// Enqueue
void enqueue(struct Queue* q, struct TreeNode* node) {
    if (q->rear == 99) return;
    
    if (q->front == -1)
        q->front = 0;
    
    q->arr[++q->rear] = node;
}

// Dequeue
struct TreeNode* dequeue(struct Queue* q) {
    if (isEmpty(q))
        return NULL;
    
    struct TreeNode* temp = q->arr[q->front];
    
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    
    return temp;
}

// Level Order Traversal
void levelOrder(struct TreeNode* root) {
    if (root == NULL)
        return;
    
    struct Queue q;
    initQueue(&q);
    
    enqueue(&q, root);
    
    while (!isEmpty(&q)) {
        struct TreeNode* temp = dequeue(&q);
        printf("%d ", temp->data);
        
        if (temp->left != NULL)
            enqueue(&q, temp->left);
        
        if (temp->right != NULL)
            enqueue(&q, temp->right);
    }
}

// Driver code
int main() {
    // Creating tree:
    //        3
    //       / \
    //      9  20
    //         / \
    //        15  7
    
    struct TreeNode* root = createNode(3);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);
    
    printf("Level Order Traversal: ");
    levelOrder(root);
    
    return 0;
}
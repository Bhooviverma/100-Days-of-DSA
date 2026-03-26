#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Queue implementation
struct Node* queue[MAX];
int front = 0, rear = 0;

// Enqueue
void enqueue(struct Node* node) {
    queue[rear++] = node;
}

// Dequeue
struct Node* dequeue() {
    return queue[front++];
}

// Check if queue empty
int isEmpty() {
    return front == rear;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = newNode(arr[0]);
    enqueue(root);

    int i = 1;
    while (!isEmpty() && i < n) {
        struct Node* curr = dequeue();

        // Left child
        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(curr->left);
        }
        i++;

        if (i >= n) break;

        // Right child
        if (arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(curr->right);
        }
        i++;
    }

    return root;
}

// Zigzag traversal
void zigzagTraversal(struct Node* root) {
    if (!root) return;

    front = rear = 0;  // reset queue
    enqueue(root);

    int leftToRight = 1;

    while (!isEmpty()) {
        int size = rear - front;
        int level[MAX];

        for (int i = 0; i < size; i++) {
            struct Node* node = dequeue();

            // Fill normally or in reverse index
            int index = leftToRight ? i : (size - 1 - i);
            level[index] = node->data;

            if (node->left)
                enqueue(node->left);
            if (node->right)
                enqueue(node->right);
        }

        // Print current level
        for (int i = 0; i < size; i++) {
            printf("%d ", level[i]);
        }

        // Toggle direction
        leftToRight = !leftToRight;
    }
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    zigzagTraversal(root);

    return 0;
}
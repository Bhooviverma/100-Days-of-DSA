#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Queue for level order
struct Node* queue[100];
int front = 0, rear = 0;

// Enqueue
void enqueue(struct Node* node) {
    queue[rear++] = node;
}

// Dequeue
struct Node* dequeue() {
    return queue[front++];
}

// Check if empty
int isEmpty() {
    return front == rear;
}

// Function to print right view
void rightView(struct Node* root) {
    if (root == NULL) return;

    enqueue(root);

    while (!isEmpty()) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            struct Node* temp = dequeue();

            // Print last node of this level
            if (i == size - 1)
                printf("%d ", temp->data);

            if (temp->left)
                enqueue(temp->left);
            if (temp->right)
                enqueue(temp->right);
        }
    }
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Node* q[100];
    int f = 0, r = 0;

    q[r++] = root;
    int i = 1;

    while (i < n) {
        struct Node* curr = q[f++];

        // Left child
        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            q[r++] = curr->left;
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            q[r++] = curr->right;
        }
        i++;
    }

    return root;
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[100];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    rightView(root);

    return 0;
}
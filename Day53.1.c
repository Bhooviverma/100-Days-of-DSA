#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue Node (for BFS)
struct QNode {
    struct Node* node;
    int hd;
    struct QNode* next;
};

// Queue
struct Queue {
    struct QNode *front, *rear;
};

// Create new tree node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Create queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue
void enqueue(struct Queue* q, struct Node* node, int hd) {
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->node = node;
    temp->hd = hd;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// Dequeue
struct QNode* dequeue(struct Queue* q) {
    if (q->front == NULL)
        return NULL;

    struct QNode* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    return temp;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = newNode(arr[0]);
    struct Queue* q = createQueue();
    enqueue(q, root, 0);

    int i = 1;
    while (i < n) {
        struct QNode* curr = dequeue(q);
        struct Node* temp = curr->node;
        free(curr);

        // Left child
        if (arr[i] != -1) {
            temp->left = newNode(arr[i]);
            enqueue(q, temp->left, 0);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            temp->right = newNode(arr[i]);
            enqueue(q, temp->right, 0);
        }
        i++;
    }

    return root;
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (root == NULL)
        return;

    // Range of HD
    int min = 0, max = 0;

    // Temporary storage (array of lists)
    int arr[100][100]; // arr[HD][elements]
    int count[100] = {0};

    struct Queue* q = createQueue();
    enqueue(q, root, 50); // shift index to avoid negative

    while (q->front != NULL) {
        struct QNode* temp = dequeue(q);
        struct Node* node = temp->node;
        int hd = temp->hd;
        free(temp);

        arr[hd][count[hd]++] = node->data;

        if (hd < min) min = hd;
        if (hd > max) max = hd;

        if (node->left)
            enqueue(q, node->left, hd - 1);

        if (node->right)
            enqueue(q, node->right, hd + 1);
    }

    // Print result
    for (int i = min; i <= max; i++) {
        for (int j = 0; j < count[i]; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// Driver Code
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}
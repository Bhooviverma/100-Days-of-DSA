#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure for adjacency list
struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];

// Create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected graph)
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// BFS function
void BFS(int s, int n) {
    int queue[MAX];
    int front = 0, rear = 0;

    // Initialize visited array
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    // Enqueue source
    queue[rear++] = s;
    visited[s] = 1;

    printf("BFS Traversal: ");

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        struct Node* temp = adj[current];
        while (temp != NULL) {
            int adjNode = temp->data;
            if (!visited[adjNode]) {
                queue[rear++] = adjNode;
                visited[adjNode] = 1;
            }
            temp = temp->next;
        }
    }
}
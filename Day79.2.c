#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int V;

// Adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adj[MAX];
Node* revAdj[MAX];
int visited[MAX];
int stack[MAX], top = -1;

// Create new node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge
void addEdge(Node* graph[], int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = graph[u];
    graph[u] = newNode;
}

// DFS for ordering
void dfs1(int v) {
    visited[v] = 1;
    for (Node* temp = adj[v]; temp != NULL; temp = temp->next) {
        if (!visited[temp->vertex])
            dfs1(temp->vertex);
    }
    stack[++top] = v;
}

// DFS on reversed graph
void dfs2(int v) {
    visited[v] = 1;
    for (Node* temp = revAdj[v]; temp != NULL; temp = temp->next) {
        if (!visited[temp->vertex])
            dfs2(temp->vertex);
    }
}

int kosaraju() {
    // Step 1: fill stack
    for (int i = 0; i < V; i++) {
        if (!visited[i])
            dfs1(i);
    }

    // Step 2: reverse graph
    for (int i = 0; i < V; i++) {
        for (Node* temp = adj[i]; temp != NULL; temp = temp->next) {
            addEdge(revAdj, temp->vertex, i);
        }
    }

    // Step 3: process stack
    for (int i = 0; i < V; i++)
        visited[i] = 0;

    int sccCount = 0;

    while (top >= 0) {
        int v = stack[top--];
        if (!visited[v]) {
            dfs2(v);
            sccCount++;
        }
    }

    return sccCount;
}

int main() {
    int E;
    scanf("%d %d", &V, &E);

    // Initialize
    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
        revAdj[i] = NULL;
        visited[i] = 0;
    }

    // Input edges
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    int result = kosaraju();
    printf("%d\n", result);

    return 0;
}
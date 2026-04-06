#include <stdbool.h>
#include <stdlib.h>

// DFS
bool dfs(int node, int parent, int visited[], int** adj, int* size) {
    visited[node] = 1;

    for (int i = 0; i < size[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, node, visited, adj, size))
                return true;
        }
        else if (neighbor != parent) {
            return true;
        }
    }
    return false;
}

bool isCycle(int edges[][2], int E, int V) {

    int* size = (int*)calloc(V, sizeof(int));

    // Step 1: Count degree
    for (int i = 0; i < E; i++) {
        size[edges[i][0]]++;
        size[edges[i][1]]++;
    }

    // Step 2: Allocate exact memory
    int** adj = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        adj[i] = (int*)malloc(size[i] * sizeof(int));
    }

    // Reset to reuse as index
    for (int i = 0; i < V; i++) size[i] = 0;

    // Step 3: Fill adjacency list
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
    }

    int* visited = (int*)calloc(V, sizeof(int));

    // Step 4: DFS on all components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, adj, size))
                return true;
        }
    }

    return false;
}
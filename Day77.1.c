#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];

void dfs(int node, int n) {
    visited[node] = 1;
    for(int i = 1; i <= n; i++) {
        if(adj[node][i] == 1 && visited[i] == 0) {
            dfs(i, n);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // initialize adjacency matrix
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
        visited[i] = 0;
    }

    // input edges
    int u, v;
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected graph
    }

    // start DFS from node 1
    dfs(1, n);

    // check if all nodes visited
    for(int i = 1; i <= n; i++) {
        if(visited[i] == 0) {
            printf("NOT CONNECTED");
            return 0;
        }
    }

    printf("CONNECTED");
    return 0;
}
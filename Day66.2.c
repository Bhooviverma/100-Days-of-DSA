bool dfs(int node, int* visited, int* recStack, int** adj, int* size) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < size[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, visited, recStack, adj, size))
                return true;
        }
        else if (recStack[neighbor]) {
            return true; // cycle found
        }
    }

    recStack[node] = 0;
    return false;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {

    // Step 1: Count degrees
    int* size = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < prerequisitesSize; i++) {
        int u = prerequisites[i][1];
        int v = prerequisites[i][0];
        size[u]++;
    }

    // Step 2: Allocate adjacency list
    int** adj = (int**)malloc(numCourses * sizeof(int*));
    for (int i = 0; i < numCourses; i++) {
        adj[i] = (int*)malloc(size[i] * sizeof(int));
    }

    // Reset size for indexing
    for (int i = 0; i < numCourses; i++) size[i] = 0;

    // Step 3: Fill adjacency list
    for (int i = 0; i < prerequisitesSize; i++) {
        int u = prerequisites[i][1];
        int v = prerequisites[i][0];
        adj[u][size[u]++] = v;
    }

    int* visited = (int*)calloc(numCourses, sizeof(int));
    int* recStack = (int*)calloc(numCourses, sizeof(int));

    // Step 4: DFS
    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, recStack, adj, size))
                return false; // cycle exists
        }
    }

    return true;
}
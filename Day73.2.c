// Find with path compression
int find(int* parent, int x) {
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

// Union operation
void unionSet(int* parent, int x, int y) {
    int px = find(parent, x);
    int py = find(parent, y);
    if (px != py)
        parent[px] = py;
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    int* parent = (int*)malloc((edgesSize + 1) * sizeof(int));

    // Initialize parent array
    for (int i = 1; i <= edgesSize; i++) {
        parent[i] = i;
    }

    // Process edges
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        // If same parent → cycle
        if (find(parent, u) == find(parent, v)) {
            int* res = (int*)malloc(2 * sizeof(int));
            res[0] = u;
            res[1] = v;
            *returnSize = 2;
            return res;
        }

        unionSet(parent, u, v);
    }

    return NULL;
}
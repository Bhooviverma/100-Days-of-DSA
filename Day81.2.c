int findTheCity(int n, int** edges, int edgesSize, int* edgesColSize, int distanceThreshold) {
    
    int INF = 1e9;
    int dist[n][n];

    // Initialize distance matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    // Fill edges
    for(int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        dist[u][v] = w;
        dist[v][u] = w; // undirected graph
    }

    // Floyd-Warshall
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Find city with minimum reachable cities
    int minCount = INF, ans = -1;

    for(int i = 0; i < n; i++) {
        int count = 0;
        for(int j = 0; j < n; j++) {
            if(i != j && dist[i][j] <= distanceThreshold) {
                count++;
            }
        }

        // Tie → take larger index
        if(count <= minCount) {
            minCount = count;
            ans = i;
        }
    }

    return ans;
}
#include <limits.h>

#define MAX 101

int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k) {
    
    int graph[MAX][MAX];
    
    // Initialize graph with INF
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INT_MAX;
        }
    }
    
    // Fill graph
    for (int i = 0; i < timesSize; i++) {
        int u = times[i][0];
        int v = times[i][1];
        int w = times[i][2];
        graph[u][v] = w;
    }
    
    int dist[MAX];
    int visited[MAX] = {0};
    
    // Initialize distances
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }
    
    dist[k] = 0;
    
    // Dijkstra
    for (int i = 1; i <= n; i++) {
        int u = -1, min = INT_MAX;
        
        // Find min distance node
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }
        
        if (u == -1) break;
        
        visited[u] = 1;
        
        // Relax edges
        for (int v = 1; v <= n; v++) {
            if (!visited[v] && graph[u][v] != INT_MAX) {
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }
    
    // Find max distance
    int max = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            return -1;
        if (dist[i] > max)
            max = dist[i];
    }
    
    return max;
}
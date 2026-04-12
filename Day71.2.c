#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int absVal(int x) {
    return x < 0 ? -x : x;
}

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    int n = pointsSize;
    
    int minDist[n];
    bool visited[n];
    
    // Initialize
    for(int i = 0; i < n; i++) {
        minDist[i] = INT_MAX;
        visited[i] = false;
    }
    
    minDist[0] = 0; // Start from point 0
    int totalCost = 0;
    
    for(int i = 0; i < n; i++) {
        int u = -1;
        
        // Pick minimum distance node not visited
        for(int j = 0; j < n; j++) {
            if(!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                u = j;
            }
        }
        
        visited[u] = true;
        totalCost += minDist[u];
        
        // Update distances
        for(int v = 0; v < n; v++) {
            if(!visited[v]) {
                int cost = absVal(points[u][0] - points[v][0]) +
                           absVal(points[u][1] - points[v][1]);
                
                minDist[v] = min(minDist[v], cost);
            }
        }
    }
    
    return totalCost;
}
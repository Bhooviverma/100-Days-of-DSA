int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int k) {
    int dist[n], temp[n];
    
    // Initialize
    for (int i = 0; i < n; i++)
        dist[i] = 1000000;
    
    dist[src] = 0;
    
    // Relax edges k+1 times
    for (int i = 0; i <= k; i++) {
        // Snapshot current distances
        for (int j = 0; j < n; j++)
            temp[j] = dist[j];
        
        for (int j = 0; j < flightsSize; j++) {
            int from  = flights[j][0];
            int to    = flights[j][1];
            int price = flights[j][2];
            
            if (dist[from] != 1000000 && dist[from] + price < temp[to])
                temp[to] = dist[from] + price;
        }
        
        for (int j = 0; j < n; j++)
            dist[j] = temp[j];
    }
    
    return dist[dst] == 1000000 ? -1 : dist[dst];
}
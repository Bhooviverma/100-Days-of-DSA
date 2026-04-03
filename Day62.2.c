bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool visited[roomsSize];
    
    for (int i = 0; i < roomsSize; i++) {
        visited[i] = false;
    }

    int queue[roomsSize];
    int front = 0, rear = 0;

    // Start from room 0
    queue[rear++] = 0;
    visited[0] = true;

    while (front < rear) {
        int room = queue[front++];

        for (int i = 0; i < roomsColSize[room]; i++) {
            int next = rooms[room][i];

            if (!visited[next]) {
                visited[next] = true;
                queue[rear++] = next;
            }
        }
    }

    // Check all visited
    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i]) return false;
    }

    return true;
}
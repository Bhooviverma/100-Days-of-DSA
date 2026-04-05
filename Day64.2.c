int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = gridColSize[0];

    int queue[10000][2];
    int front = 0, rear = 0;

    int fresh = 0;

    // Step 1: Push all rotten oranges & count fresh
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 2) {
                queue[rear][0] = i;
                queue[rear][1] = j;
                rear++;
            }
            if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    // If no fresh oranges
    if (fresh == 0) return 0;

    int minutes = 0;
    int directions[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

    // BFS
    while (front < rear) {
        int size = rear - front;
        int rottenThisRound = 0;

        for (int i = 0; i < size; i++) {
            int x = queue[front][0];
            int y = queue[front][1];
            front++;

            for (int d = 0; d < 4; d++) {
                int nx = x + directions[d][0];
                int ny = y + directions[d][1];

                if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    queue[rear][0] = nx;
                    queue[rear][1] = ny;
                    rear++;
                    fresh--;
                    rottenThisRound = 1;
                }
            }
        }

        if (rottenThisRound)
            minutes++;
    }

    return (fresh == 0) ? minutes : -1;
}
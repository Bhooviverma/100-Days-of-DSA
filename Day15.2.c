void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int rows = matrixSize;
    int cols = matrixColSize[0];
    
    int firstRow = 0, firstCol = 0;

    // Check if first row has zero
    for(int j = 0; j < cols; j++) {
        if(matrix[0][j] == 0) {
            firstRow = 1;
            break;
        }
    }

    // Check if first column has zero
    for(int i = 0; i < rows; i++) {
        if(matrix[i][0] == 0) {
            firstCol = 1;
            break;
        }
    }

    // Use first row and column as markers
    for(int i = 1; i < rows; i++) {
        for(int j = 1; j < cols; j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Set elements to zero based on markers
    for(int i = 1; i < rows; i++) {
        for(int j = 1; j < cols; j++) {
            if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Handle first row
    if(firstRow) {
        for(int j = 0; j < cols; j++) {
            matrix[0][j] = 0;
        }
    }

    // Handle first column
    if(firstCol) {
        for(int i = 0; i < rows; i++) {
            matrix[i][0] = 0;
        }
    }
}


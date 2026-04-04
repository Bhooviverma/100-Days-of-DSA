void dfs(int** image, int rows, int cols, int r, int c, int oldColor, int newColor) {
    // Boundary + color check
    if (r < 0 || r >= rows || c < 0 || c >= cols || image[r][c] != oldColor)
        return;

    // Fill color
    image[r][c] = newColor;

    // 4 directions
    dfs(image, rows, cols, r+1, c, oldColor, newColor);
    dfs(image, rows, cols, r-1, c, oldColor, newColor);
    dfs(image, rows, cols, r, c+1, oldColor, newColor);
    dfs(image, rows, cols, r, c-1, oldColor, newColor);
}

int** floodFill(int** image, int imageSize, int* imageColSize,
                int sr, int sc, int color,
                int* returnSize, int** returnColumnSizes) {

    int oldColor = image[sr][sc];

    // Edge case
    if (oldColor == color) {
        *returnSize = imageSize;
        *returnColumnSizes = imageColSize;
        return image;
    }

    dfs(image, imageSize, imageColSize[0], sr, sc, oldColor, color);

    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;
    return image;
}
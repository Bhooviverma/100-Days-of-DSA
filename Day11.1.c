#include <stdio.h>

int main() {
    int m, n, i, j;

    // Read dimensions
    printf("Enter dimensions of a 2D matrix: ");
    scanf("%d %d", &m, &n);

    int A[m][n], B[m][n], Sum[m][n];

    // Read first matrix
    printf("Enter values of 1st matrix: ");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Read second matrix
    printf("Enter values of 2nd matrix: ");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Add matrices
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            Sum[i][j] = A[i][j] + B[i][j];
        }
    }
    
    // Print result matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", Sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}

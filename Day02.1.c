// Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

#include <stdio.h>

int main() {
    int n, pos, i;
    int arr[100];

    // Input size
    printf("Enter number of elements in an array: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter elements of array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input position (1-based)
    printf("Enter position that you want to delete: ");
    scanf("%d", &pos);

    // Check valid position
    if (pos < 1 || pos > n) {
        printf("Invalid position");
        return 0;
    }

    // Shift elements to the left
    for (i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Print updated array
    printf("Updated array is:\n");
    for (i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
#include <stdio.h>

int main() {
    int n, k;

    // Input size
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter elements of array: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input k
    printf("Enter the value of k: ");
    scanf("%d", &k);

    // Handle k greater than n
    k = k % n;

    int temp[k];

    // Store last k elements
    for(int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }

    // Shift remaining elements right
    for(int i = n - k - 1; i >= 0; i--) {
        arr[i + k] = arr[i];
    }

    // Place stored elements at beginning
    for(int i = 0; i < k; i++) {
        arr[i] = temp[i];
    }

    // Print rotated array
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
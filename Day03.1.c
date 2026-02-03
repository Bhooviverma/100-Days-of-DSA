#include <stdio.h>

int main() {
    int n, k, i;
    int comparisons = 0;

    // Input size
    printf("Enter size of an array: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter elements of array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input key
    printf("Enter key: ");
    scanf("%d", &k);

    // Linear search
    for (i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == k) {
            printf("Found at index %d\n", i);
            printf("Comparisons = %d", comparisons);
            return 0;
        }
    }
}
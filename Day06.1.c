#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements in an array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements of an array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Edge case
    if (n == 0) return 0;

    int j = 0;  // index of last unique element

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }

    // Print unique elements
    printf("Unique elements of the array: ");
    for (int i = 0; i <= j; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

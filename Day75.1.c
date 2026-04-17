#include <stdio.h>

int maxLen(int arr[], int n) {
    int sum = 0, max_length = 0;

    // Hash map using array (for simplicity)
    // Assuming sum range is manageable
    int hash[10000];
    for (int i = 0; i < 10000; i++) hash[i] = -2;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // Case 1: sum becomes 0
        if (sum == 0) {
            max_length = i + 1;
        }

        // Case 2: sum seen before
        if (hash[sum + 5000] != -2) {
            int len = i - hash[sum + 5000];
            if (len > max_length)
                max_length = len;
        } else {
            hash[sum + 5000] = i; // store first occurrence
        }
    }

    return max_length;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d", maxLen(arr, n));
    return 0;
}
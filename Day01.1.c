// Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

#include <stdio.h>

int main(){
    int n, i, x, a;
    
    printf("Enter number of elements in an array: ");
    scanf("%d", &n);
    
    int arr[n + 1];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter position where you want to insert (1 to %d): ", n + 1);
    scanf("%d", &x);

    printf("Enter element that you want to insert: ");
    scanf("%d", &a);
    
    // shift elements to the right
    for (i = n; i >= x; i--) {
        arr[i] = arr[i - 1];
    }

    arr[x - 1] = a;
    n++;

    printf("Array after insertion:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
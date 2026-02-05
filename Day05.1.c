#include <stdio.h>

int main() {
    int p, q;
    printf("number of entries in server log 1: ");
    scanf("%d", &p);

    int a[p];
    printf("p sorted integers representing arrival times from server 1: ");
    for (int i = 0; i < p; i++) {
        scanf("%d", &a[i]);
    }

    printf("number of entries in server log 2: ");
    scanf("%d", &q);
    int b[q];
    printf("q sorted integers representing arrival times from server 2: ");
    for (int i = 0; i < q; i++) {
        scanf("%d", &b[i]);
    }

    int i = 0, j = 0;

    printf("all arrival times in chronological order: \n");
    while (i < p && j < q) {
        if (a[i] <= b[j]) {
            printf("%d ", a[i++]);
        } else {
            printf("%d ", b[j++]);
        }
    }

    while (i < p) {
        printf("%d ", a[i++]);
    }

    while (j < q) {
        printf("%d ", b[j++]);
    }

    return 0;
}
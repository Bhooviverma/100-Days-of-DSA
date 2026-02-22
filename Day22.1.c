#include <stdio.h>
#include <stdlib.h>

struct node {
    int no;
    struct node *next;
} *new, *first = NULL, *ptr;

int main() {
    int n, i, count = 0;

    printf("Enter number of elements you want to insert: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        new = (struct node*)malloc(sizeof(struct node));
        printf("Enter elements you want to insert: ");
        scanf("%d", &new->no);
        new->next = NULL;

        if(first == NULL) {
            first = new;
        } else {
            ptr = first;
            while(ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = new;
        }
    }

    // Counting nodes
    ptr = first;
    while(ptr != NULL) {
        count++;
        ptr = ptr->next;
    }

    printf("%d", count);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *first = NULL, *newnode, *ptr;

int main() {
    int n, i, key, count = 0;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create Linked List
    for (i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &newnode->data);
        
        newnode->next = NULL;

        if (first == NULL) {
            first = newnode;
        } else {
            ptr = first;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = newnode;
        }
    }

    printf("Enter key to count: ");
    scanf("%d", &key);

    // Count occurrences
    ptr = first;
    while (ptr != NULL) {
        if (ptr->data == key) {
            count++;
        }
        ptr = ptr->next;
    }

    printf("Number of occurrences of %d = %d\n", key, count);

    return 0;
}
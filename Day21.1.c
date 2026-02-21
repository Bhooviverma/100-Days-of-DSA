#include <stdio.h>
#include <stdlib.h>

struct node{
    int no;
    struct node *next;
} *new, *first = NULL, *ptr;

int main() {
    int n;
    printf("Enter number of items to be inserted: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {

        // Create new node
        new = (struct node*)malloc(sizeof(struct node));
        printf("Enter data to be inserted: ");
        scanf("%d", &new->no);
        new->next = NULL;

        // Insert at end
        if(first == NULL)
            first = new;
        else {
            for(ptr = first; ptr->next != NULL; ptr = ptr->next);
            ptr->next = new;
        }
    }

    // Traverse and print
    for(ptr = first; ptr != NULL; ptr = ptr->next)
        printf("%d ", ptr->no);

    return 0;
}
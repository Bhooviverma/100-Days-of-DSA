#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int exp;
    struct node* next;
} *first = NULL, *new, *ptr;

// Create Polynomial
void create(int n) {
    int c, e;

    printf("Creating Polynomial...\n");

    for (int i = 0; i < n; i++) {

        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &c, &e);

        new = (struct node*)malloc(sizeof(struct node));
        if (new == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }

        new->coeff = c;
        new->exp = e;
        new->next = NULL;

        printf("Node Created: %dx^%d\n", c, e);

        if (first == NULL) {
            first = new;
            printf("Inserted as first node.\n");
        } else {
            ptr = first;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = new;
            printf("Inserted at end of list.\n");
        }
    }
}

// Display Polynomial
void display() {
    if (first == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }

    printf("\nTraversing Polynomial...\n");
    printf("Polynomial: ");

    ptr = first;

    while (ptr != NULL) {

        if (ptr->exp == 0)
            printf("%d", ptr->coeff);
        else if (ptr->exp == 1)
            printf("%dx", ptr->coeff);
        else
            printf("%dx^%d", ptr->coeff, ptr->exp);

        if (ptr->next != NULL)
            printf(" + ");

        ptr = ptr->next;
    }

    printf("\nTraversal Completed.\n");
}

int main() {
    int n;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    create(n);
    display();

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *first = NULL, *new, *ptr, *temp;

/* Create normal singly linked list */
void create(int n) {
    int value;

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);

        new = (struct node*)malloc(sizeof(struct node));
        new->data = value;
        new->next = NULL;

        if (first == NULL) {
            first = new;
        } else {
            ptr = first;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = new;
        }
    }
}

/* Count nodes */
int countNodes() {
    int count = 0;
    temp = first;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

/* Rotate Right by k */
void rotateRight(int k) {

    int n = countNodes();

    if (n == 0 || k == 0)
        return;

    k = k % n;
    if (k == 0)
        return;

    /* Step 1: Go to last node */
    ptr = first;
    while (ptr->next != NULL)
        ptr = ptr->next;

    /* Step 2: Make circular */
    ptr->next = first;

    /* Step 3: Move to (n-k)th node */
    temp = first;
    for (int i = 1; i < n - k; i++)
        temp = temp->next;

    /* Step 4: Update head */
    first = temp->next;

    /* Step 5: Break circular link */
    temp->next = NULL;
}

/* Display list */
void display() {
    temp = first;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, k;

    printf("Enter value of n: ");
    scanf("%d", &n);

    create(n);

    printf("Enter value of k: ");
    scanf("%d", &k);

    rotateRight(k);

    printf("List after rotation: ");
    display();

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *first1 = NULL, *first2 = NULL, *newfirst = NULL;

// Create node
struct node* createNode(int value) {
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = value;
    new->next = NULL;
    return new;
}

// Insert at end
struct node* insertEnd(struct node* first, int value) {
    struct node* new = createNode(value);

    if (first == NULL)
        return new;

    struct node* ptr = first;
    while (ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = new;
    return first;
}

// Merge two sorted lists
void mergeLists() {
    struct node *ptr1 = first1;
    struct node *ptr2 = first2;
    struct node *tail = NULL;

    if (ptr1 == NULL)
        newfirst = ptr2;
    else if (ptr2 == NULL)
        newfirst = ptr1;
    else {
        if (ptr1->data <= ptr2->data) {
            newfirst = ptr1;
            ptr1 = ptr1->next;
        } else {
            newfirst = ptr2;
            ptr2 = ptr2->next;
        }

        tail = newfirst;

        while (ptr1 != NULL && ptr2 != NULL) {
            if (ptr1->data <= ptr2->data) {
                tail->next = ptr1;
                ptr1 = ptr1->next;
            } else {
                tail->next = ptr2;
                ptr2 = ptr2->next;
            }
            tail = tail->next;
        }

        if (ptr1 != NULL)
            tail->next = ptr1;
        else
            tail->next = ptr2;
    }
}

// Display list
void display(struct node* first) {
    struct node* ptr = first;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int main() {
    int n, m, value;

    // First list
    printf("Enter number of values to insert in list 1: ");
    scanf("%d", &n);
    printf("Enter data to insert: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        first1 = insertEnd(first1, value);
    }

    // Second list
    printf("Enter number of values to insert in list 2: ");
    scanf("%d", &m);
    printf("Enter data to insert: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        first2 = insertEnd(first2, value);
    }

    mergeLists();

    display(newfirst);

    return 0;
}
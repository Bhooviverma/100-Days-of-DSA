#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *first = NULL, *newnode, *ptr, *prev;

// Create Linked List
void create(int n) {
    for(int i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(first == NULL) {
            first = newnode;
        } else {
            ptr = first;
            while(ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = newnode;
        }
    }
}

// Delete first occurrence of key
void deleteKey(int key) {

    // Case 1: Empty list
    if(first == NULL) {
        return;
    }

    // Case 2: Key at first node
    if(first->data == key) {
        ptr = first;
        first = first->next;
        free(ptr);
        return;
    }

    // Case 3: Key in middle or end
    prev = first;
    ptr = first->next;

    while(ptr != NULL) {
        if(ptr->data == key) {
            prev->next = ptr->next;
            free(ptr);
            return;
        }
        prev = ptr;
        ptr = ptr->next;
    }
}

// Display list
void display() {
    ptr = first;
    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int main() {
    int n, key;

    scanf("%d", &n);
    create(n);

    scanf("%d", &key);
    deleteKey(key);

    display();

    return 0;
}
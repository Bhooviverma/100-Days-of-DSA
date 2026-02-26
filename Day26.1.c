#include <stdio.h>
#include <stdlib.h>

// Structure of Doubly Linked List Node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

int main() {
    int n, value;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);

        // Create new node
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;

        printf("Creating node with data = %d\n", value);

        if(head == NULL) {
            head = newNode;
            temp = newNode;
            printf("This is the first node. Head initialized.\n");
        }
        else {
            temp->next = newNode;
            newNode->prev = temp;
            printf("Inserted %d after %d\n", newNode->data, temp->data);
            temp = newNode;
        }
    }

    // Traverse forward
    printf("\nTraversing Doubly Linked List in forward direction:\n");

    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\nTraversal completed.\n");

    return 0;
}
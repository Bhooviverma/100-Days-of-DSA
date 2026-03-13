#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x) {
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = x;
    new->next = NULL;

    if (rear == NULL) {
        front = rear = new;
    } else {
        rear->next = new;
        rear = new;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("-1\n");
        return;
    }

    struct node *temp = front;
    printf("%d\n", front->data);
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

int main() {
    int n, x;
    char op[20];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (strcmp(op, "enqueue") == 0) {
            scanf("%d", &x);
            enqueue(x);
        }
        else if (strcmp(op, "dequeue") == 0) {
            dequeue();
        }
    }

    return 0;
}
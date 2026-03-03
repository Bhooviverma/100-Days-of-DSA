#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = value;
    printf("%d pushed into stack\n", value);
}

// Pop operation
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d popped from stack\n", stack[top]);
    top--;
}

// Display operation
void display() {
    if (top == -1) {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack elements (Top to Bottom): ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n, operation, value;

    printf("Enter number of operations: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter operation (1-Push, 2-Pop, 3-Display): ");
        scanf("%d", &operation);

        if (operation == 1) {
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
        }
        else if (operation == 2) {
            pop();
        }
        else if (operation == 3) {
            display();
        }
        else {
            printf("Invalid Operation\n");
        }
    }

    return 0;
}
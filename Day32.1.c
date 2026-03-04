#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    top++;
    stack[top] = value;
    printf("%d pushed into stack\n", value);
}

// Pop operation
void pop() {
    if (top == -1) {
        printf("Stack Underflow! Cannot pop\n");
        return;
    }
    printf("%d popped from stack\n", stack[top]);
    top--;
}

// Display stack
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }

    printf("Remaining stack elements (Top to Bottom): ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n, m, value;

    printf("Enter number of elements to push: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    printf("Enter number of elements to pop: ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        pop();
    }

    display();

    return 0;
}
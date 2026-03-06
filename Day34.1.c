#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
    int data;
    struct node *next;
} *top = NULL, *newnode, *ptr;

/* Push operation */
void push(int value) {
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = top;
    top = newnode;

    printf("Push: %d\n", value);
}

/* Pop operation */
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }

    int value = top->data;
    ptr = top;
    top = top->next;
    free(ptr);

    printf("Pop: %d\n", value);
    return value;
}

int main() {
    char exp[100];
    int i = 0, op1, op2, result;

    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);

    while (exp[i] != '\0') {

        /* If operand */
        if (isdigit(exp[i])) {
            int num = exp[i] - '0';
            printf("\nReading operand: %d\n", num);
            push(num);
        }

        /* If operator */
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {

            printf("\nOperator found: %c\n", exp[i]);

            op2 = pop();
            op1 = pop();

            printf("Operands: %d %c %d\n", op1, exp[i], op2);

            switch (exp[i]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
            }

            printf("Result after operation: %d\n", result);
            push(result);
        }

        i++;
    }

    printf("\nFinal Result: %d\n", pop());

    return 0;
}
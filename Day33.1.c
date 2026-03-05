#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
    printf("Pushed %c to stack\n", x);
}

char pop() {
    if(top == -1)
        return -1;
    else {
        char x = stack[top--];
        printf("Popped %c from stack\n", x);
        return x;
    }
}

int priority(char x) {
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

void displayStack() {
    printf("Current Stack: ");
    if(top == -1) {
        printf("Empty");
    } else {
        for(int i = 0; i <= top; i++)
            printf("%c ", stack[i]);
    }
    printf("\n");
}

int main() {

    char infix[100], postfix[100];
    int i, j = 0;

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    printf("\n--- Conversion Steps ---\n");

    for(i = 0; infix[i] != '\0'; i++) {

        printf("\nReading: %c\n", infix[i]);

        if(isalnum(infix[i])) {
            postfix[j++] = infix[i];
            printf("Operand detected → Added to postfix\n");
        }

        else if(infix[i] == '(') {
            push(infix[i]);
        }

        else if(infix[i] == ')') {
            printf("Closing bracket detected\n");
            while(stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); 
        }

        else {  
            printf("Operator detected\n");

            while(top != -1 && priority(stack[top]) >= priority(infix[i])) {
                postfix[j++] = pop();
            }

            push(infix[i]);
        }

        printf("Current Postfix: ");
        for(int k = 0; k < j; k++)
            printf("%c", postfix[k]);
        printf("\n");

        displayStack();
    }

    printf("\nEmptying remaining stack...\n");

    while(top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("\nFinal Postfix Expression: %s\n", postfix);

    return 0;
}
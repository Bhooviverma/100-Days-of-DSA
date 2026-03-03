bool isValid(char* s) {
    int len = strlen(s);
    
    // Create stack
    char stack[len];
    int top = -1;

    for (int i = 0; i < len; i++) {
        char ch = s[i];

        // If opening bracket → push
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        }
        // If closing bracket → check
        else {
            if (top == -1)   // stack empty
                return false;

            char popped = stack[top--];

            if ((ch == ')' && popped != '(') ||
                (ch == '}' && popped != '{') ||
                (ch == ']' && popped != '[')) {
                return false;
            }
        }
    }

    // If stack empty → valid
    return (top == -1);
}
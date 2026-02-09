#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, len;
    char temp;

    // Input
    printf("Enter a word: ");
    scanf("%s", str);

    len = strlen(str);

    // Mirror (reverse) the string
    for (i = 0; i < len / 2; i++) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }

    // Output
    printf("%s", str);

    return 0;
}

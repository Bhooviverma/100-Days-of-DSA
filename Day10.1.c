#include <stdio.h>
#include <string.h>

int main() {
    int left, right;
    int ans = 1;
    char arr[100];

    printf("Enter a word (without gap): ");
    scanf("%s", arr);

    left = 0;
    right = strlen(arr) - 1;   

    while (left < right) {
        if (arr[left] != arr[right]) {
            ans = 0;
            break;            
        }
        left++;
        right--;
    }

    if (ans == 0)
        printf("NO");
    else
        printf("YES");

    return 0;
} 
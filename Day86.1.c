#include <stdio.h>

int integerSqrt(int n) {
    int left = 0, right = n, ans = 0;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        if (mid * mid == n) {
            return mid;
        }
        else if (mid * mid < n) {
            ans = mid;        // store possible answer
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d", integerSqrt(n));
    return 0;
}
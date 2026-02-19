#include <limits.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int maxSubarraySumCircular(int* nums, int numsSize) {
    int total = 0;
    
    int currMax = 0, maxSum = INT_MIN;
    int currMin = 0, minSum = INT_MAX;
    
    for(int i = 0; i < numsSize; i++) {
        total += nums[i];
        
        currMax = max(nums[i], currMax + nums[i]);
        maxSum = max(maxSum, currMax);
        
        currMin = min(nums[i], currMin + nums[i]);
        minSum = min(minSum, currMin);
    }
    
    // If all numbers are negative
    if(maxSum < 0)
        return maxSum;
    
    return max(maxSum, total - minSum);
}
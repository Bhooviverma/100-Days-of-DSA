int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    
    *returnSize = numsSize;
    
    int* result = (int*)malloc(numsSize * sizeof(int));
    
    // Step 1: Store left products
    result[0] = 1;
    for(int i = 1; i < numsSize; i++) {
        result[i] = result[i - 1] * nums[i - 1];
    }
    
    // Step 2: Multiply with right products
    int rightProduct = 1;
    for(int i = numsSize - 1; i >= 0; i--) {
        result[i] = result[i] * rightProduct;
        rightProduct *= nums[i];
    }
    
    return result;
}

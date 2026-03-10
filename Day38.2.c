int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    
    int *result = (int*)malloc(sizeof(int) * (numsSize - k + 1));
    int *deque = (int*)malloc(sizeof(int) * numsSize);
    
    int front = 0, rear = -1;
    *returnSize = numsSize - k + 1;
    
    int index = 0;

    for(int i = 0; i < numsSize; i++) {

        // Remove indices outside window
        if(front <= rear && deque[front] <= i - k)
            front++;

        // Remove smaller elements from rear
        while(front <= rear && nums[deque[rear]] < nums[i])
            rear--;

        // Insert current index
        deque[++rear] = i;

        // Window ready
        if(i >= k - 1)
            result[index++] = nums[deque[front]];
    }

    free(deque);
    return result;
}
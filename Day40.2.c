int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    
    int* ans = (int*)calloc(temperaturesSize, sizeof(int));
    int* stack = (int*)malloc(sizeof(int) * temperaturesSize);
    
    int top = -1;
    *returnSize = temperaturesSize;

    for(int i = 0; i < temperaturesSize; i++)
    {
        while(top >= 0 && temperatures[i] > temperatures[stack[top]])
        {
            int idx = stack[top--];
            ans[idx] = i - idx;
        }

        stack[++top] = i;
    }

    free(stack);
    return ans;
}
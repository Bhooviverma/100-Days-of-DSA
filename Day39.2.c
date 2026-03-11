#include <stdlib.h>

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    
    int freq[20001] = {0};   // frequency array
    int offset = 10000;      // to handle negative numbers
    
    // Count frequency
    for(int i = 0; i < numsSize; i++){
        freq[nums[i] + offset]++;
    }

    int* result = (int*)malloc(sizeof(int) * k);
    int index = 0;

    // Find top k elements
    for(int i = 0; i < k; i++){
        int maxFreq = 0;
        int num = 0;

        for(int j = 0; j < 20001; j++){
            if(freq[j] > maxFreq){
                maxFreq = freq[j];
                num = j;
            }
        }

        result[index++] = num - offset;
        freq[num] = 0; // remove so next max can be found
    }

    *returnSize = k;
    return result;
}
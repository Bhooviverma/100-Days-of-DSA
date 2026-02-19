void moveZeroes(int* nums, int numsSize) {
    int j = 0;  // index for non-zero elements

    // Move all non-zero elements forward
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[j] = nums[i];
            j++;
        }
    }

    // Fill remaining positions with 0
    while (j < numsSize) {
        nums[j] = 0;
        j++;
    }
}
void sortColors(int* nums, int numsSize) {
    int i = 0, j = 0;

    while (i < numsSize) {
        if (nums[i] == 0) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            j++;
        }
        i++;
    }

    i = j;
    while (i < numsSize) {
        if (nums[i] == 1) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            j++;
        }
        i++;
    }
}

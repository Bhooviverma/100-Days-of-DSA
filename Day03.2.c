int missingNum(int *arr, int size) {
    long long totalSum, arrSum = 0;

    for (int i = 0; i < size; i++) {
        arrSum += arr[i];
    }

    totalSum = (long long)(size + 1) * (size + 2) / 2;

    return (int)(totalSum - arrSum);
}
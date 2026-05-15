/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* relativeSortArray(int* arr1, int arr1Size,
                       int* arr2, int arr2Size,
                       int* returnSize) {

    int* result = (int*)malloc(sizeof(int) * arr1Size);
    int idx = 0;

    // Put elements according to arr2
    for(int i = 0; i < arr2Size; i++) {

        for(int j = 0; j < arr1Size; j++) {

            if(arr1[j] == arr2[i]) {
                result[idx++] = arr1[j];
                arr1[j] = -1;
            }
        }
    }

    // Store starting index of remaining elements
    int start = idx;

    // Add remaining elements
    for(int i = 0; i < arr1Size; i++) {

        if(arr1[i] != -1) {
            result[idx++] = arr1[i];
        }
    }

    // Sort remaining part
    for(int i = start; i < idx; i++) {

        for(int j = i + 1; j < idx; j++) {

            if(result[i] > result[j]) {

                int temp = result[i];
                result[i] = result[j];
                result[j] = temp;
            }
        }
    }

    *returnSize = arr1Size;
    return result;
}

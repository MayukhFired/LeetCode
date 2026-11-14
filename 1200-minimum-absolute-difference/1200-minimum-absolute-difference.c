/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int compare(const void* a , const void* b){
    return (*(int*)a - *(int*)b);
}

int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes) {
    qsort(arr , arrSize , sizeof(int) , compare);

    int min_diff = INT_MAX;
    for(int i = 0; i < arrSize - 1; i++){
        int diff = arr[i + 1] - arr[i];
        if(diff < min_diff){
            min_diff = diff;
        }
    }

    int** result = (int**)malloc((arrSize - 1) * sizeof(int*));
    *returnColumnSizes = (int*)malloc((arrSize - 1) * sizeof(int));
    int count = 0;

    for(int i = 0; i < arrSize - 1; i++){
        if(arr[i + 1] - arr[i] == min_diff){
            result[count] = (int*)malloc(2 * sizeof(int));
            result[count][0] = arr[i];
            result[count][1] = arr[i + 1];
            (*returnColumnSizes)[count] = 2;
            count++;
        }
    }

    *returnSize = count;
    return result;
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void swap(int* a , int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void backtrack(int* nums , int numsSize , int start , int** res , int* returnSize , int* returnColumnSizes) {
    if(start == numsSize) {
        res[*returnSize] = (int*)malloc(numsSize * sizeof(int));
        memcpy(res[*returnSize] , nums , numsSize * sizeof(int));
        returnColumnSizes[*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }

    for(int i = start; i < numsSize; i++) {
        swap(&nums[start] , &nums[i]);
        backtrack(nums , numsSize , start + 1 , res , returnSize , returnColumnSizes);
        swap(&nums[start] , &nums[i]);
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int total_size = 1;
    for(int i = 2; i <= numsSize; i++) {
        total_size *= i;
    }

    int** res = (int**)malloc(total_size * sizeof(int*));
    *returnColumnSizes = (int*)malloc(total_size * sizeof(int));
    *returnSize = 0;

    backtrack(nums , numsSize , 0 , res , returnSize , *returnColumnSizes);
    return res;
}
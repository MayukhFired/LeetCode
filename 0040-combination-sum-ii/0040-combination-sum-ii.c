/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int compare(const void* a , const void* b) {
    return (*(int*)a - *(int*)b);
}

void backtrack(int* candidates , int candidatesSize , int total_left , int index , int* tempList , int tempSize , int*** ans , int* returnSize , int** returnColumnSizes , int* capacity) {
    if(total_left < 0) {
        return;
    }

    if(total_left == 0) {
        if(*returnSize >= *capacity) {
            *capacity *= 2;
            *ans = (int**)realloc(*ans , (*capacity) * sizeof(int*));
            *returnColumnSizes = (int*)realloc(*returnColumnSizes , *(capacity) * sizeof(int));
        }

        (*ans)[*returnSize] = (int*)malloc(tempSize * sizeof(int));
        memcpy((*ans)[*returnSize] , tempList , tempSize * sizeof(int));
        (*returnColumnSizes)[*returnSize] = tempSize;
        (*returnSize)++;
        return;
    }

    for(int i = index; i < candidatesSize && total_left >= candidates[i]; i++) {
        if(i > index && candidates[i] == candidates[i - 1]) {
            continue;
        }

        tempList[tempSize] = candidates[i];
        backtrack(candidates , candidatesSize , total_left - candidates[i] , i + 1 , tempList , tempSize + 1 , ans , returnSize , returnColumnSizes , capacity);
    }
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(candidates , candidatesSize , sizeof(int) , compare);

    int capacity = 64;
    int** ans = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));
    int* tempList = (int*)malloc(candidatesSize * sizeof(int));
    *returnSize = 0;

    backtrack(candidates , candidatesSize , target , 0 , tempList , 0 , &ans , returnSize , returnColumnSizes , &capacity);
    free(tempList);
    return ans;
}
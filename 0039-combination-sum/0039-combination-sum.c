/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void backtrack(int* candidates , int candidatesSize , int target , int start , int* current_path , int path_len , int** result , int* returnSize , int* returnColumnSizes){
    if(target == 0){
        result[*returnSize] = (int*)malloc(path_len * sizeof(int));
        memcpy(result[*returnSize] , current_path , path_len * sizeof(int));
        returnColumnSizes[*returnSize] = path_len;
        (*returnSize)++;
        return;
    }

    for(int i = start; i < candidatesSize; i++){
        if(candidates[i] > target){
            continue;
        }

        current_path[path_len] = candidates[i];

        backtrack(candidates , candidatesSize , target - candidates[i] , i , current_path , path_len + 1 , result , returnSize , returnColumnSizes);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int combi = 150;
    int** res = (int**)malloc(combi * sizeof(int*));
    *returnColumnSizes = (int*)malloc(combi * sizeof(int));
    *returnSize = 0;

    int* current_path = (int*)malloc((target + 1) * sizeof(int));

    backtrack(candidates , candidatesSize , target , 0 , current_path , 0 , res , returnSize , *returnColumnSizes);

    free(current_path);
    return res;
}
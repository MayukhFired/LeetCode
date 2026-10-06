/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void backtrack(int start , int k , int target , int* path , int pathSize , int*** result , int* returnSize , int** returnColumnSizes){
    if(pathSize == k){
        if(target == 0){
            (*result)[*returnSize] = (int*)malloc(k *sizeof(int));
            for(int i = 0; i < k; i++){
                (*result)[*returnSize][i] = path[i];
            }
            (*returnColumnSizes)[*returnSize] = k;
            (*returnSize)++;
        }

        return;
    }

    if(target < 0){
        return;
    }

    for(int i = start; i <= 9; i++){
        path[pathSize] = i;
        backtrack(i + 1 , k , target - i , path , pathSize + 1 , result , returnSize , returnColumnSizes);
    }
}
int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes) {
    int max_combinations = 150;
    int** result = (int**)malloc(max_combinations * sizeof(int*));
    *returnColumnSizes = (int*)malloc(max_combinations * sizeof(int));
    *returnSize = 0;
    int* path = (int*)malloc(k * sizeof(int));

    backtrack(1 , k , n , path , 0 , &result , returnSize , returnColumnSizes);

    free(path);
    return result;
}
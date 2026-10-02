/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void backtrack(char** result , int* returnSize , char* current , int index , int openCount , int closeCount , int n){
    if(index == 2 * n){
        current[index] = '\0';
        result[*returnSize] = malloc((2 * n + 1) * sizeof(char));
        strcpy(result[*returnSize] , current);
        (*returnSize)++;
        return;
    }

    if(openCount < n){
        current[index] = '(';
        backtrack(result , returnSize , current , index + 1 , openCount + 1 , closeCount , n);
    }

    if(closeCount < openCount){
        current[index] = ')';
        backtrack(result , returnSize , current , index + 1 , openCount , closeCount + 1 , n);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    char** res = malloc(5000 * sizeof(char*));
    *returnSize = 0;
    char* curr = malloc((2 * n + 1) * sizeof(char));
    backtrack(res , returnSize , curr , 0 , 0 , 0  , n);
    free(curr);
    return res;
}
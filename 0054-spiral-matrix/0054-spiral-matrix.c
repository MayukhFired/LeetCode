/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if(matrixSize == 0 || matrixColSize[0] == 0){
        *returnSize = 0;
        return NULL;
    }

    *returnSize = matrixSize * matrixColSize[0];
    int *result = (int*)malloc(matrixSize * matrixColSize[0] * sizeof(int));

    int index = 0;
    int left = 0;
    int right = matrixColSize[0] - 1;
    int top = 0;
    int bottom = matrixSize - 1;

    while(top <= bottom && left <= right){
        for(int i = left; i <= right; i++){
            result[index++] = matrix[top][i];
        }
        top++;

        for(int i = top; i <= bottom; i++){
            result[index++] = matrix[i][right];
        }
        right--;

        if(top <= bottom){
            for(int i = right; i >= left; i--){
                result[index++] = matrix[bottom][i];
            }
            bottom--;
        }

        if(left <= right){
            for(int i = bottom; i >= top; i--){
                result[index++] = matrix[i][left];
            }
            left++;
        }
    }
    return result;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *result = (int *)malloc((digitsSize + 1) *sizeof(int));

    bool allNines = true;
    for(int i = 0; i < digitsSize; i++){
        if(digits[i] != 9){
            allNines = false;
            break;
        }
    }

    if(allNines){
        *returnSize = digitsSize + 1;
        result[0] = 1;
        for(int i = 1; i < *returnSize; i++){
            result[i] = 0;
        }
        return result;
    }else{
        *returnSize = digitsSize;
        for(int i = 0; i < digitsSize; i++){
            result[i] = digits[i];
        }
        for(int i = digitsSize - 1; i >= 0; i--){
            if(result[i] < 9){
                result[i] += 1;
                return result;
            }
            result[i] = 0;
        }
    }
    return result;
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int totalSubsets = 1 << numsSize;
    *returnSize = totalSubsets;

    int** output = (int**)malloc(totalSubsets * sizeof(int*));
    *returnColumnSizes = (int*)malloc(totalSubsets * sizeof(int));
    output[0] = NULL;
    (*returnColumnSizes)[0] = 0;
    int currentCount = 1;

    for(int i = 0; i < numsSize; i++){
        int num = nums[i];
        int existingCount = currentCount;

        for(int j = 0; j < existingCount; j++){
            int oldLen = (*returnColumnSizes)[j];
            int newLen = oldLen + 1;

            int* subset = (int*)malloc(newLen * sizeof(int));

            if(oldLen > 0){
                memcpy(subset , output[j] , oldLen * sizeof(int));
            }

            subset[oldLen] = num;
            output[currentCount] = subset;
            (*returnColumnSizes)[currentCount] = newLen;
            currentCount++;
        }
    }

    return output;
}
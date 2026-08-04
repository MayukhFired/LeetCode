int* findMissingElements(int* nums, int numsSize, int* returnSize) {
    if(numsSize == 0){
        *returnSize = 0;
        return NULL;
    }

    int min = nums[0];
    int max = nums[0];
    for(int i = 1; i < numsSize; i++){
        if(nums[i] < min) min = nums[i];
        if(nums[i] > max) max = nums[i];
    }

    int rangeSize = max - min + 1;
    int* present = (int*)calloc(rangeSize , sizeof(int));
    if(!present){
        *returnSize = 0;
        return NULL;
    }

    int max_missing = rangeSize - numsSize;
    int* result = (int*)malloc(max_missing * sizeof(int));
    *returnSize = 0;

    for(int i = 0; i < numsSize; i++){
        present[nums[i] - min] = 1;
    }

    for(int i = 0; i < rangeSize; i++){
        if(!present[i]){
            result[(*returnSize)++] = i + min;
        }
    }
    free(present);
    return result;
}
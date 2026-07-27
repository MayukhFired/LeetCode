int sorting(const void* a , const void* b){
    return (*(int*)a - *(int*)b);
}

bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums , numsSize, sizeof(int), sorting);
    for(int i = 1; i < numsSize; i++){
        if(nums[i] == nums[i - 1]){
            return true;
        }
    }
    return false;
}
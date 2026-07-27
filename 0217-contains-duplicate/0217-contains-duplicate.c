int sorting(const void* a , const void* b){
    int num1 = *(int*)a;
    int num2 = *(int*)b;

    if(num1 < num2) return -1;
    if(num1 > num2) return 1;
    return 0;
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
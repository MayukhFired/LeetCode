int compare(const void* a , const void* b){
    return (*(int*)a - *(int*)b);
}

int missingMultiple(int* nums, int numsSize, int k) {
    qsort(nums , numsSize , sizeof(int) , compare);
    int multiple = k;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] < multiple){
            continue;
        }
        if(nums[i] == multiple){
            multiple += k;
        }
        if(nums[i] > multiple){
            return multiple;
        }
    }
    return multiple;
}
int compare(const void* a , const void* b){
    int valA = *(const int*)a;
    int valB = *(const int*)b;
    if(valA < valB){
        return -1;
    }
    if(valA > valB){
        return 1;
    }
    return 0;
}

int thirdMax(int* nums, int numsSize) {
    qsort(nums , numsSize , sizeof(int) , compare);

    int elemCount = 1;
    int prevElem = nums[numsSize - 1];

    for(int i = numsSize - 2; i >= 0; i--){
        if(nums[i] != prevElem){
            elemCount++;
            prevElem = nums[i];
        }
        if(elemCount == 3){
            return nums[i];
        }
    }
    return nums[numsSize - 1];
}
int compare(const void *a , const void *b){
    return (*(int*)a - *(int*)b);
}

int maximumProduct(int* nums, int numsSize) {
    qsort(nums , numsSize , sizeof(int) , compare);
    int pro1 = nums[numsSize - 1] * nums[numsSize - 2] * nums[numsSize - 3];
    int pro2 = nums[0] * nums[1] * nums[numsSize - 1];
    return (pro1 > pro2) ? pro1 : pro2;
}
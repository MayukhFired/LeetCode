void moveZeroes(int* nums, int numsSize) {
    int non_zeros = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] != 0){
            nums[non_zeros++] = nums[i];
        }
    }

    for(int i = non_zeros; i < numsSize; i++){
        nums[i] = 0;
    }
}
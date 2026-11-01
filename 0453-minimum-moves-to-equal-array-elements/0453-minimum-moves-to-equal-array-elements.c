int minMoves(int* nums, int numsSize) {
    int sum = nums[0];
    int min_nums = nums[0];
    for(int i = 1; i < numsSize; i++){
        sum += nums[i];
        if(nums[i] < min_nums){
            min_nums = nums[i];
        }
    }

    return sum - numsSize * min_nums;
}
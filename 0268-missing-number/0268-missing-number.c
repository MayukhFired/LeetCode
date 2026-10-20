int missingNumber(int* nums, int numsSize) {
    int sum = numsSize * (numsSize + 1) / 2;
    int num_sum = 0;
    for(int i = 0; i < numsSize; i++){
        num_sum += nums[i];
    }
    return sum - num_sum;
}
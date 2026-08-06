int pivotIndex(int* nums, int numsSize) {
    int totalSum = 0;
    for(int i = 0; i < numsSize; i++){
        totalSum += nums[i];
    }

    int left_sum = 0;
    for(int i = 0; i < numsSize; i++){
        if(left_sum == totalSum - left_sum - nums[i]){
            return i;
        }
        left_sum += nums[i];
    }
    return -1;
}
int minOperations(int* nums, int numsSize) {
    int a = 1;
    int d = 1;

    for(int i = 1; i < numsSize; i++){
        a += nums[i] == (nums[i - 1] + 1) % numsSize;
        d += nums[i - 1] == (nums[i] + 1) % numsSize;
    }

    if(a == numsSize && !nums[0]){
        return 0;
    }

    if(a == numsSize){
        return fmin(numsSize - nums[0] , nums[0] + 2);
    }

    if(d == numsSize){
        return fmin(numsSize - nums[numsSize - 1] , nums[numsSize - 1]) + 1;
    }

    return -1;
}
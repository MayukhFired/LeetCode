int longestSubsequence(int* nums, int numsSize) {
    int result = 0;
    bool iszero = true;
    for(int i = 0; i < numsSize ; i++){
        if(nums[i] != 0) iszero = false;
        result ^= nums[i];
        
    }

    if(iszero){
        return 0;
    }

    if(result != 0){
        return numsSize;
    }else{
        return numsSize - 1;
    }
    return 0;
}
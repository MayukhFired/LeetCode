bool canJump(int* nums, int numsSize) {
    int max_reachable = 0;

    for(int i = 0; i < numsSize; i++){
        if(max_reachable < i){
            return false;
        }

        if(max_reachable < i + nums[i]){
            max_reachable = i + nums[i];
        }

        if(max_reachable >= numsSize - 1){
            return true;
        }
    }

    return false;
}
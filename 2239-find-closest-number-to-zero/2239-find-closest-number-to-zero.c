int findClosestNumber(int* nums, int numsSize) {
    int closest = nums[0];
    for(int i = 0; i < numsSize; i++){
        if(abs(nums[i]) < abs(closest)){
            closest = nums[i];
        }else if(abs(nums[i]) == abs(closest)){
            if(nums[i] > closest){
                closest = nums[i];
            }
        }
    }

    return closest;
}
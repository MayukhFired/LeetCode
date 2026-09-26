int dominantIndex(int* nums, int numsSize) {
    int max_val = -1;
    int second_max = -1;
    int max_idx = -1;

    for(int i = 0; i < numsSize; i++){
        if(nums[i] > max_val){
            second_max = max_val;
            max_val = nums[i];
            max_idx = i;
        }else if(nums[i] > second_max){
            second_max = nums[i];
        }
    }
    return (max_val >= 2 * second_max) ? max_idx : -1;
}
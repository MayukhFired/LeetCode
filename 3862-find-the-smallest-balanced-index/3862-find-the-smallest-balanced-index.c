int smallestBalancedIndex(int* nums, int numsSize) {
    // if(numsSize <= 0 || nums == NULL){
    //     return -1;
    // }
    
    // long long total_sum = 0;
    // for(int i = 0; i < numsSize; i++){
    //     total_sum += nums[i];
    // }

    // long long maxpossible_sum = total_sum;

    // long long right_product = 1;
    // int result = -1;

    // int is_overflowed = 0;
    // long long safe_cap = 1000000000000000LL;
    // for(int i = numsSize - 1; i >= 0; i--){
    //     total_sum -= nums[i];

    //     if(!is_overflowed && total_sum == right_product){
    //         result = i;
    //     }

    //     if(!is_overflowed){
    //         if(nums[i] != 0 && right_product > safe_cap / abs(nums[i])){
    //             is_overflowed = 1;
    //         }else{
    //             right_product *= nums[i];
    //         }
    //     }
    // }

    // return result;

    long long s = 0;
    __int128 p = 1;

    for(int i = 0; i < numsSize; i++){
        s += nums[i];
    }

    for(int i = numsSize - 1; i >= 0; i--){
        s -= nums[i];
        if(s == p){
            return i;
        }

        p *= nums[i];
        if(p >= s){
            break;
        }
    }
    return -1;
}
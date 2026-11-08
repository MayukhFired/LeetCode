int waysToMakeFair(int* nums, int numsSize) {
    int res = 0;
    int left_odd = 0;
    int left_even = 0;
    int odd_sum = 0;
    int even_sum = 0;

    for(int i = 0; i < numsSize; i++){
        if(i % 2 == 0){
            even_sum += nums[i];
        }else{
            odd_sum += nums[i];
        }
    }

    for(int i = 0; i < numsSize; i++){
        if(i % 2 == 0){
            even_sum -= nums[i];
            if(even_sum + left_odd == left_even + odd_sum){
                res++;
            }
            left_even += nums[i];
        }else{
            odd_sum -= nums[i];
            if(even_sum + left_odd == left_even + odd_sum){
                res++;
            }
            left_odd += nums[i];
        }
    }
    return res;
}
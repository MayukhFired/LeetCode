int minimumSumSubarray(int* nums, int numsSize, int l, int r) {
    int ans = INT_MAX;
    for(int i = 0; i < numsSize; i++){
        int sum = 0;
        for(int j = i; j < numsSize; j++){
            sum += nums[j];
            int len = j - i + 1;
            if(len >= l && len <= r && sum > 0){
                ans = fmin(ans , sum);
            }
        }
    }

    return ans == INT_MAX ? -1 : ans;
}
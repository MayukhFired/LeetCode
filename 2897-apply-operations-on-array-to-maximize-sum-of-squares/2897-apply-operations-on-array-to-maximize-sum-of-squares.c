int maxSum(int* nums, int numsSize, int k) {
    long long MOD = 1000000007;
    int bits[30] = {0};
    for(int i = 0; i < numsSize; i++){
        for(int j = 0; j < 30; j++){
            if((nums[i] >> j) & 1){
                bits[j]++;
            }
        }
    }

    long long total_sum = 0;
    for(int step = 0; step < k; step++){
        long long curr_sum = 0;
        for(int i = 0; i < 30; i++){
            if(bits[i] > 0){
                curr_sum |= (1LL << i);
                bits[i]--;
            }
        }
        total_sum = (total_sum + (curr_sum * curr_sum)) % MOD;
    }

    return (int)total_sum;
}
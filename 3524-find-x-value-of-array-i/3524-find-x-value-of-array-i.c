/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
long long* resultArray(int* nums, int numsSize, int k, int* returnSize) {
    long long* res = (long long*)calloc(k , sizeof(long long));
    long long* dp = (long long*)calloc(k , sizeof(long long));
    long long* ndp = (long long*)malloc(k * sizeof(long long));

    for(int i = 0; i < numsSize; i++){
        memset(ndp , 0 , k * sizeof(long long));
        ndp[nums[i] % k]++;
        for(int r = 0; r < k; r++){
            ndp[(int)(((long long)r * nums[i]) % k)] += dp[r];
        }
        memcpy(dp , ndp , k * sizeof(long long));
        for(int r = 0; r < k ; r++){
            res[r] += dp[r];
        }
    }
    free(dp);
    free(ndp);
    *returnSize = k;
    return res;
}
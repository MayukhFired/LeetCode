class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> res(k);
        vector<long long> dp(k);
        int n = nums.size();

        for(int i = 0; i < n; i++){
            vector<long long> ndp(k);
            ndp[nums[i] % k]++;
            for(int r = 0; r < k; r++){
                ndp[(long long)r * nums[i] % k] += dp[r];
            }
            dp = move(ndp);
            for(int r = 0; r < k; r++){
                res[r] += dp[r];
            }
        }
        return res;
    }
};
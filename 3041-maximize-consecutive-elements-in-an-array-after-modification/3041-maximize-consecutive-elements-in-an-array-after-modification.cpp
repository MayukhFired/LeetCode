class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
    // 1----------------------------------------------------------------------------1
        // sort(nums.begin() , nums.end());
        // unordered_map<int , int> dp;
        // int ans = 0;

        // for(int x : nums){
        //     dp[x + 1] = max(dp[x + 1] , dp[x] + 1);
        //     dp[x] = max(dp[x] , dp[x - 1] + 1);
        //     ans = max({ans , dp[x] , dp[x + 1]});
        // }

        // return ans;
    // 1----------------------------------------------------1
        sort(nums.begin() , nums.end());
        int best = 1;
        int keep = 1;
        int bump = 1;
        int last = -10;

        for(int x : nums){
            switch (x - last) {
                case 0: bump = keep + 1; break;
                case 1: ++keep , ++bump; break;
                case 2:
                keep = bump + 1 , bump = 1; break;
                default: keep = bump = 1;
            }
            best = max({best , keep , bump}) , last = x;
        }
        return best;
    }
};
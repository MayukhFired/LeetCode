class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int n = nums.size();
        // int sum = n * (n + 1) / 2;
        // int num_sum = 0;
        // for(int i = 0; i < n; i++){
        //     num_sum += nums[i];
        // }
        // return sum - num_sum;
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i <= n; i++){
            ans ^= i;
        }
        for(int i = 0; i < n; i++){
            ans^= nums[i];
        }
        return ans;
    }
};
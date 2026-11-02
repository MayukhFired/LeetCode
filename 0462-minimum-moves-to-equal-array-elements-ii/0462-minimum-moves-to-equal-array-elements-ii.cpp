class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        long long res = 0;
        int median = nums[nums.size() / 2];
        for(int num : nums){
            res += abs(num - median);
        }
        return res;
    }
};
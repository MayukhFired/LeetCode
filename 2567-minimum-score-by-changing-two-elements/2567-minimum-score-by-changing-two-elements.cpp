class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());

        int opt1 = nums[nums.size() - 3] - nums[0];
        int opt2 = nums[nums.size() - 2] - nums[1];
        int opt3 = nums[nums.size() - 1] - nums[2];

        return min({opt1 , opt2 , opt3});
    }
};
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = nums[0];
        int min_nums = nums[0];
        for(int i = 1; i < nums.size(); i++){
            sum += nums[i];
            min_nums = min(min_nums , nums[i]);
        }
        return sum - nums.size() * min_nums;
    }
};
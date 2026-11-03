class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max_nums = nums[0];
        for(int i = 1; i < nums.size(); i++){
            max_nums = max(max_nums , nums[i]);
        }

        int total = 0;
        for(int i = 0; i < nums.size(); i++){
            total += max_nums - nums[i];
        }
        return total;
    }
};
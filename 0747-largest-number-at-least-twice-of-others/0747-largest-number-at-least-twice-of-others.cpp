class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max_val = -1;
        int secondMax_val = -1;
        int maxIdx = -1;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > max_val){
                secondMax_val = max_val;
                max_val = nums[i];
                maxIdx = i;
            }else if(nums[i] > secondMax_val){
                secondMax_val = nums[i];
            }
        }
        return (max_val >= 2 * secondMax_val) ? maxIdx : -1;
    }
};
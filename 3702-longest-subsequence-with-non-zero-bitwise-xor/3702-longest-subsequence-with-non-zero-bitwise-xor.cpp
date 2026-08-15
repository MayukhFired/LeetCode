class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int result = 0;
        bool allzero = true;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0) allzero = false;
            result ^= nums[i];
        }

        if(allzero){
            return 0;
        }
        if(result != 0){
            return nums.size();
        }else{
            return nums.size() - 1;
        }
    }
};
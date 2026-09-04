class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        if(nums.size() <= 1){
            return 0;
        }

        for(int i = 0; i < nums.size(); i++){
            int leftmax = nums[i];
            int rightmin = nums[i];

            for(int j = 0; j < i; j++){
                leftmax = max(leftmax , nums[j]);
            }

            for(int k = i + 1; k < nums.size(); k ++){
                rightmin = min(rightmin , nums[k]);
            }

            if(leftmax - rightmin <= k){
                return i;
            }

        }
        return -1;
    }
};
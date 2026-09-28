class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != -1){
                int start = i;
                int count = 0;
                while(nums[start] != -1){
                    int next_idx = nums[start];
                    nums[start] = -1;
                    start = next_idx;
                    count++;
                }
                res = max(res , count);
            }
        }
        return res;
    }
};
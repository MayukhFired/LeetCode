class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int max_len = 1;

        for(int start = 0; start < nums.size(); start++){
            int curr_len = 1;
            for(int pos = start + 1; pos < nums.size(); pos++){
                if(nums[pos - 1] < nums[pos]){
                    curr_len++;
                }else{
                    break;
                }
            }
            max_len = max(max_len , curr_len);
        }

        for(int start = 0; start < nums.size(); start++){
            int curr_len = 1;
            for(int pos = start + 1; pos < nums.size(); pos++){
                if(nums[pos - 1] > nums[pos]){
                    curr_len++;
                }else{
                    break;
                }
            }
            max_len = max(max_len , curr_len);
        }

        return max_len;
    }
};
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int k = 0;
        int left = 0;
        int curr_sum = 0;
        int max_len = -1;

        for(int i = 0; i < nums.size(); i++){
            k += nums[i];
        }
        k -= x;
        if(k == 0){
            return nums.size();
        }
        if(k < 0){
            return -1;
        }

        for(int right = 0; right < nums.size(); right++){
            curr_sum += nums[right];
            while(curr_sum > k){
                curr_sum -= nums[left++];
            }
            if(curr_sum == k){
                max_len = max(max_len , right - left + 1);
            }
        }
        return max_len == -1 ? -1 : nums.size() - max_len;
    }
};
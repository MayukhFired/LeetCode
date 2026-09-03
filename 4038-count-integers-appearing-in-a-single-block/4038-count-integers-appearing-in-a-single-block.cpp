class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }

        unordered_map<int , int> total_count;
        unordered_set<int> d_nums;
        unordered_map<int , int> block_len;

        for(int num : nums){
            total_count[num]++;
            d_nums.insert(num);
        }

        int i = 0;
        int n = nums.size();
        while(i < n){
            int curr_num = nums[i];
            int curr_len = 0;

            while(i < n && nums[i] == curr_num){
                curr_len++;
                i++;
            }
            block_len[curr_num] = curr_len;
        }

        int special_count = 0;
        for(int num : d_nums){
            if(total_count[num] == block_len[num]){
                special_count++;
            }
        }

        return special_count;
    }
};
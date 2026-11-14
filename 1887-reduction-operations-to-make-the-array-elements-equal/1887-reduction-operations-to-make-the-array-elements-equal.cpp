class Solution {
public:
    int reductionOperations(vector<int>& nums) {
    // 1--------------------------------------------------1
        // sort(nums.begin() , nums.end());
        // int ans = 0;
        // int steps = 0;

        // for(int i = 1; i < nums.size(); i++){
        //     if(nums[i] != nums[i - 1]){
        //         steps++;
        //     }
        //     ans += steps;
        // }
        // return ans;
    // 1---------------------------------------------------1
        int max_nums = INT_MIN;
        for(int num : nums){
            max_nums = max(max_nums , num);
        }
        int ans = 0;
        int steps = 0;
        vector<int> freq(max_nums + 1 , 0);
        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
        }

        for(int val = 1; val <= max_nums; val++){
            if(freq[val] > 0){
                ans += freq[val] * steps;
                steps++;
            }
        }
        return ans;
    }
};
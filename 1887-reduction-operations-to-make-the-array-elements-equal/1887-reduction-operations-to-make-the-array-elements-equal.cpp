class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int ans = 0;
        int steps = 0;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i - 1]){
                steps++;
            }
            ans += steps;
        }
        return ans;
    }
};
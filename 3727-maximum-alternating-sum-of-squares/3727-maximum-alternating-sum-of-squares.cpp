class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<int> multi(nums.size());
        for(int i = 0; i < nums.size(); i++){
            multi[i] = 1LL * nums[i] * nums[i];
        }
        sort(multi.begin() , multi.end());
        long long ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i < nums.size() / 2){
                ans -= multi[i];
            }else{
                ans += multi[i];
            }
        }
        return ans;
    }
};
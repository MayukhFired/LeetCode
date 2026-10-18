class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long a0 = -1e7 , a1 = a0 , b0 = a0 , b1 = a0 , res = a0;
        for(long long num : nums){
            long long nb0 = max(a0 , b1 + num);
            b1 = max(a1 , b0 - num);
            b0 = nb0;
            long long na0 = max(a1 + num , num);
            a1 = a0 - num;
            a0 = na0;
            res = max({res , a0 , a1 , b0 , b1});
        }
        return res;
    }
};
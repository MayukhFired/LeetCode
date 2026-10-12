class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        long long MOD = 1e9 + 7;
        vector<int> bits(30 , 0);

        for(int num : nums){
            for(int i = 0; i < 30; i++){
                if(1 & (num >> i)){
                    bits[i]++;
                }
            }
        }

        long long total_sum = 0;
        for(int step = 0; step < k; step++){
            long long curr_sum = 0;
            for(int i = 0; i < 30; i++){
                if(bits[i] > 0){
                    curr_sum |= (1LL << i);
                    bits[i]--;
                }
            }
            total_sum = (total_sum + (curr_sum * curr_sum)) % MOD;
        }
        return total_sum;
    }
};
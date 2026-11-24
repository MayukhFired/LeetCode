class Solution {
public:
    int maxLength(vector<int>& nums) {
    // 1-----------------------------------------------------------1
        // int res = 0;
        // for(int i = 0; i < nums.size(); i++){
        //     int prod_val = nums[i];
        //     int gcd_val = nums[i];
        //     int lcm_val = nums[i];
        //     for(int j = i + 1; j < nums.size(); j++){
        //         prod_val = prod_val * nums[j];
        //         gcd_val = gcd(gcd_val , nums[j]);
        //         lcm_val = lcm(lcm_val , nums[j]);
        //         if(prod_val > lcm_val * gcd_val){
        //             break;
        //         }
        //         if(prod_val == gcd_val * lcm_val){
        //             res = max(res , j - i + 1);
        //         }
        //     }
        // }
        // return res;
    // 1---------------------------------------------------------------------1
        int res = 2;
        int prod_val = 1;
        int n = nums.size();
        int start = 0;
        int end = 0;

        while(end < n){
            while(gcd(prod_val , nums[end]) > 1){
                prod_val /= nums[start];
                start++;
            }
            prod_val *= nums[end];
            res = max(res , end - start + 1);
            end++;
        }
        return res;
    }
};
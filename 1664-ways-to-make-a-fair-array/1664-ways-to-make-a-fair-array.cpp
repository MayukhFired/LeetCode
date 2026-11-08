class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int even_total = 0;
        int odd_total = 0;

        for(int i =0; i < nums.size(); i++){
            if(i % 2 == 0){
                even_total += nums[i];
            }else{
                odd_total += nums[i];
            }
        }

        int res = 0;
        int left_odd = 0;
        int left_even = 0;

        for(int i = 0; i < nums.size(); i++){
            if(i % 2 == 0){
                even_total -= nums[i];
                if(even_total + left_odd == odd_total + left_even){
                    res++;
                }
                left_even += nums[i];
            }else{
                odd_total -= nums[i];
                if(even_total + left_odd == odd_total + left_even){
                    res++;
                }
                left_odd += nums[i];
            }
        }
        return res;
    }
};
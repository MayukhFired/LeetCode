class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        unsigned __int128 p = 1;
        long long s = 0;

        for(int i = 0; i < nums.size(); i++){
            s += nums[i];
        }

        for(int i = nums.size() - 1; i >= 0; i--){
            s -= nums[i];

            if(s == p){
                return i;
            }

            p *= nums[i];
            if(p >= s){
                break;
            }
        }
        return -1;
    }
};
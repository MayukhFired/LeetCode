class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // if(nums.size() <= 2){
        //     return nums.size();
        // }

        // int prev = 1;
        // int curr = 2;
        // while(curr < nums.size()){
        //     if(nums[prev] == nums[curr] && nums[curr] == nums[prev - 1]){
        //         curr++;
        //     }else{
        //         prev++;
        //         nums[prev] = nums[curr];
        //         curr++;
        //     }
        // }
        // return prev + 1;

        int i , n = nums.size();
        int idx = 0;
        int ans = 0;
        for(i = 0; i < n;){
            int j = i;
            int cnt = 0;
            while(j < n && nums[i] == nums[j]){
                ++cnt;
                ++j;
            }

            for(int j = 0; j < min(cnt , 2); j++){
                nums[idx++] = nums[i];
            }
            i = j;
            ans += min(cnt , 2);
        }
        return ans;
    }
};
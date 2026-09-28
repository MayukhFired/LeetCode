class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        // int res = 0;
        // for(int i = 0; i < nums.size(); i++){
        //     if(nums[i] != -1){
        //         int start = i;
        //         int count = 0;
        //         while(nums[start] != -1){
        //             int next_idx = nums[start];
        //             nums[start] = -1;
        //             start = next_idx;
        //             count++;
        //         }
        //         res = max(res , count);
        //     }
        // }
        // return res;

        int n = nums.size();
        int ans = 0;
        vector<bool> visited(n , false);

        for(int i = 0; i < n; i++){
            if(visited[i]){
                continue;
            }

            int curr = i;
            int count = 0;

            while(!visited[curr]){
                visited[curr] = true;
                curr = nums[curr];
                count++;
            }
            ans = max(ans , count);
        }
        return ans;
    }
};
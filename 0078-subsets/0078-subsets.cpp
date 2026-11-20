class Solution {
    vector<vector<int>> output;
    int n;

    void backtrack(int first , vector<int> curr , vector<int>& nums){
        output.push_back(curr);
        for(int i = first; i < n; i++){
            curr.push_back(nums[i]);
            backtrack(i + 1 , curr , nums);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    // 1---------------------------------------------------------1
        // vector<vector<int>> output;
        // output.push_back({});
        // for(int num : nums){
        //     vector<vector<int>> subsets;
        //     for(vector<int> curr : output) {
        //         vector<int> temp = curr;
        //         temp.push_back(num);
        //         subsets.push_back(temp);
        //     }
        //     for(vector<int> curr : subsets){
        //         output.push_back(curr);
        //     }
        // }
        // return output;
    // 1--------------------------------------------------------1
        n = nums.size();
        vector<int> curr;
        backtrack(0 , curr , nums);
        return output;
    }
};
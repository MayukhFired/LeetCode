class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> output;
        output.push_back({});
        for(int num : nums){
            vector<vector<int>> subsets;
            for(vector<int> curr : output) {
                vector<int> temp = curr;
                temp.push_back(num);
                subsets.push_back(temp);
            }
            for(vector<int> curr : subsets){
                output.push_back(curr);
            }
        }
        return output;
    }
};
class Solution {
private:
    void backtrack(vector<int>& candidates , int target , int start , vector<int>& current_path , vector<vector<int>>& res){
        if(target == 0){
            res.push_back(current_path);
            return;
        }

        for(int i = start; i < candidates.size(); i++){
            if(candidates[i] > target){
                continue;
            }
            current_path.push_back(candidates[i]);
            backtrack(candidates , target - candidates[i] , i , current_path , res);
            current_path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> current_path;
        backtrack(candidates , target , 0 , current_path , res);
        return res;
    }
};
class Solution {
    private:
        vector<vector<int>> f;
public:
    int dfs(const vector<int>& stoneValue , int left , int right){
        if(left == right){
            return 0;
        }
        
        if(f[left][right]){
            return f[left][right];
        }
        int sum = accumulate(stoneValue.begin() + left , stoneValue.begin() + right + 1 , 0);
        int sum1 = 0;
        for(int i = left; i < right; i++){
            sum1 += stoneValue[i];
            int sum2 = sum - sum1;
            if(sum1 < sum2){
                f[left][right] = max(f[left][right] , dfs(stoneValue , left , i) + sum1);
            }else if(sum1 > sum2){
                f[left][right] = max(f[left][right] , dfs(stoneValue , i + 1 , right) + sum2);
            }else{
                f[left][right] = max(f[left][right] , max(dfs(stoneValue , left , i) , dfs(stoneValue , i + 1 , right)) + sum1);
            }
        }
        return f[left][right];
    }
    
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        f.assign(n , vector<int>(n));
        return dfs(stoneValue , 0 , n - 1);
    }
};
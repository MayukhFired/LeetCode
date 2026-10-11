class Solution {
public:
// 1------------------------------------------------------------------------------------1
    // int solve(int i , int j , int m , int n , vector<vector<int>>& dp){
    //     if(i == m - 1 || j == n - 1){
    //         return 1;
    //     }

    //     if(i < 0 || i >= m || j < 0 || j >= n){
    //         return 0;
    //     }

    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }

    //     int right = solve(i , j + 1 , m , n, dp);
    //     int down = solve(i + 1 , j , m , n , dp);

    //     return dp[i][j] = right + down;
    // }
// 1---------------------------------------------------------------------------------------1
    int uniquePaths(int m, int n) {
    // 1-------------------------------------------------------------------1
        // vector<vector<int>> dp(m + 1 , vector<int>(n + 1 , -1));
        // return solve(0 , 0 , m , n , dp);
    // 1--------------------------------------------------------------------1

    vector<vector<int>> dp(m , vector<int>(n , 1));
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];

    }
};
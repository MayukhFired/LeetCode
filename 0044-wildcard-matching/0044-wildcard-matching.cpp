class Solution {
public:
// 1---------------------------------------------------------------------------------------1
    // bool solve(string& s , string& p , int i , int j , vector<vector<int>>& dp) {
    //     if(i < 0 && j < 0) {
    //         return true;
    //     }
    //     if(j < 0 && i >= 0) {
    //         return false;
    //     }

    //     if(i < 0 && j >= 0) {
    //         for(int k = 0; k <= j; k++) {
    //             if(p[k] != '*') {
    //                 return false;
    //             }
    //         }
    //         return true;
    //     }

    //     if(dp[i][j] != -1) {
    //         return dp[i][j];
    //     }

    //     if(p[j] == s[i] || p[j] == '?') {
    //         return dp[i][j] = solve(s , p , i - 1 , j - 1 , dp);
    //     }else if(p[j] == '*') {
    //         return dp[i][j] = solve(s , p , i - 1 , j , dp) || solve(s , p , i , j - 1, dp);
    //     }
    //     return dp[i][j] = false;
    // }
// 1---------------------------------------------------------------------------------------------1
    bool isMatch(string s, string p) {
    // 1---------------------------------------------------1
        // int n = s.length();
        // int m = p.length();
        // vector<vector<int>>dp(n , vector<int>(m , -1));
        // return solve(s , p , n - 1 , m - 1 , dp);
    // 1--------------------------------------------------1

    // 2----------------------------------------------------------------------2
        // int n = s.length();
        // int m = p.length();
        // vector<vector<bool>> dp(n + 1, vector<bool>(m +1 , false));
        // dp[0][0] = true;

        // for(int i = 1; i <= n; i++) {
        //     dp[i][0] = false;
        // }

        // for(int j = 1; j <= m; j++) {
        //     if(p[j - 1] == '*') {
        //         dp[0][j] = dp[0][j - 1];
        //     }else{
        //         dp[0][j] = false;
        //     }
        // }

        // for(int i = 1; i <= n; i++) {
        //     for(int j = 1; j <= m; j++) {
        //         if(p[j - 1] == s[i - 1] || p[j - 1] == '?') {
        //             dp[i][j] = dp[i - 1][j - 1];
        //         }else if(p[j - 1] == '*') {
        //             dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
        //         }else{
        //             dp[i][j] = false;
        //         }
        //     }
        // }
        // return dp[n][m];
    // 2--------------------------------------------------------------------2
        int i = 0;
        int j = 0;
        int startIdx = -1;
        int matchIdx = 0;
        int n = static_cast<int>(s.length());
        int m = static_cast<int>(p.length());

        while(i < n) {
            if(j < m && (p[j] == s[i] || p[j] == '?')) {
                i++;
                j++;
            }else if(j < m && p[j] == '*') {
                startIdx = j;
                matchIdx = i;
                j++;
            }else if(startIdx != -1) {
                j = startIdx + 1;
                matchIdx++;
                i = matchIdx;
            }else{
                return false;
            }
        }

        while(j < m && p[j] == '*') {
            j++;
        }

        return j == m;
    }
};
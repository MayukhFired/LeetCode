class Solution {
public:
    int numTrees(int n) {
    // 1----------------------------------------------------------------------1
        // vector<int> uniqueTrees(n + 1 , 1);
        // for(int nodes = 2; nodes <= n; nodes++){
        //     int total = 0;
        //     for(int root = 1; root <= nodes; root++){
        //         total += uniqueTrees[root - 1] * uniqueTrees[nodes - root];
        //     }
        //     uniqueTrees[nodes] = total;
        // }
        // return uniqueTrees[n];
    // 1----------------------------------------------------------------------1
        int dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i <= n; i++){
            int total = 0;
            for(int j = 1; j <= i; j++){
                total += dp[j - 1] * dp[i - j];
            }
            dp[i] = total;
        }
        return dp[n];
    }
};
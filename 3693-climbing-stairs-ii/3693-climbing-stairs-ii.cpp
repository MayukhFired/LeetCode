class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
    // 1-----------------------------------------------------------------1
        // int a = 0; 
        // int b = 0;
        // int c = 0;

        // for(int i = 0; i < n; i++){
        //     int n = min({a + 9 , b + 4 , c + 1}) + costs[i];
        //     a = b;
        //     b = c;
        //     c = n;
        // }
        // return c;
    // 1----------------------------------------------------------------1
        vector<int> dp(n + 1 , INT_MAX / 2);
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            dp[i] = min(dp[i] , dp[i - 1] + costs[i - 1] + 1);

            if(i >= 2){
                dp[i] = min(dp[i] , dp[i - 2] + costs[i - 1] + 4);
            }

            if(i >= 3){
                dp[i] = min(dp[i] , dp[i - 3] + costs[i - 1] + 9);
            }
        }
        return dp[n];
    }
};
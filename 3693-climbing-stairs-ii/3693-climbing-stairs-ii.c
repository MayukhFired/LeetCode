int climbStairs(int n, int* costs, int costsSize) {
// 1----------------------------------------------------------------------1
    // int a = 0;
    // int b = 0;
    // int c = 0;

    // for(int i = 0; i < n; i++){
    //     int n = fmin(a + 9 , fmin(b + 4 , c + 1)) + costs[i];
    //     a = b;
    //     b = c;
    //     c = n;
    // }
    // return c;
// 1---------------------------------------------------------------------1

    int* dp = (int*)malloc((n + 1) * sizeof(int));
    for(int i = 0; i <= n; i++){
        dp[i] = INT_MAX / 2;
    }

    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        dp[i] = fmin(dp[i] , dp[i - 1] + costs[i - 1] + 1);
        if(i >= 2){
            dp[i] = fmin(dp[i] , dp[i - 2] + costs[i - 1] + 4);
        }
        if(i >= 3){
            dp[i] = fmin(dp[i] , dp[i - 3] + costs[i - 1] + 9);
        }
    }
    return dp[n];
}
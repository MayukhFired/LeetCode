int solve(int n , int* dp){
    if(n <= 0){
        return 0;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    for(int i = 1; i*i <= n; i++){
        if(solve(n - i * i , dp) == 0){
            return dp[n] = 1;
        }
    }
    return dp[n] = 0;
}

bool winnerSquareGame(int n) {
   int* dp = (int*)malloc((n + 1) * sizeof(int));
    if (dp == NULL) {
        return false; // Memory allocation failed
    }
    
    // Initialize all states to -1
    memset(dp, -1, (n + 1) * sizeof(int));
    int res = solve(n , dp);
    free(dp);
    return res;
}
int solve(int i , int j , int m , int n , int** dp){
    if(i == m - 1 || j == n - 1){
        return 1;
    }

    if(i < 0 || i >= m || j < 0 || j >= n){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int right = solve(i , j + 1 , m , n , dp);
    int down = solve(i + 1 , j , m , n, dp);

    return dp[i][j] = right + down;
}

int uniquePaths(int m, int n) {
    int** dp = (int**)malloc(m * sizeof(int*));
    for(int i = 0; i < m; i++){
        dp[i] = (int*)malloc(n * sizeof(int));
        for(int j = 0; j < n; j++){
            dp[i][j] = -1;
        }
    }

    int res = solve(0 , 0 , m , n, dp);

    for(int i = 0; i < m; i++){
        free(dp[i]);
    }
    free(dp);
    return res;
}
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    if(obstacleGrid == NULL || obstacleGridSize == 0 || obstacleGridColSize == NULL || obstacleGrid[0][0] == 1){
        return 0;
    }

    int m = obstacleGridSize;
    int n = obstacleGridColSize[0];
    int* dp = (int*)calloc(n , sizeof(int));
    if(dp == NULL){
        return 0;
    }

    dp[0] = 1;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(obstacleGrid[i][j] == 1){
                dp[j] = 0;
            }else if(j > 0){
                dp[j] += dp[j - 1];
            }
        }
    }

    int res = dp[n - 1];
    free(dp);
    return res;
}
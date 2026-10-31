int uniquePaths(int** grid, int gridSize, int* gridColSize) {
    const int MOD = 1000000007;
    int m = gridSize;
    int n = gridColSize[0];

    int*** f = (int***)malloc(m * sizeof(int**));
    for(int i = 0; i < m; i++){
        f[i] = (int**)malloc(n * sizeof(int*));
        for(int j = 0; j < n; j++){
            f[i][j] = (int*)calloc(2 , sizeof(int));
        }
    }

    f[0][0][0] = 1;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i > 0){
                if(grid[i - 1][j] == 0){
                    f[i][j][0] = (f[i - 1][j][0] + f[i - 1][j][1]) % MOD;
                }else{
                    f[i][j][0] = f[i - 1][j][1];
                }
            }
            if(j > 0){
                if(grid[i][j - 1] == 0){
                    f[i][j][1] = (f[i][j - 1][0] + f[i][j - 1][1]) % MOD;
                }else{
                    f[i][j][1] = f[i][j - 1][0];
                }
            }
        }
    }

    int res = (f[m - 1][n - 1][0] + f[m - 1][n - 1][1]) % MOD;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            free(f[i][j]);
        }
        free(f[i]);
    }
    free(f);

    return res;
}
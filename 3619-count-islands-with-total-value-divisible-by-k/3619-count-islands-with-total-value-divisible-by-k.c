int countIslands(int** grid, int gridSize, int* gridColSize, int k) {
    int m = gridSize;
    int n = gridColSize[0];
    int ans = 0;
    int dirs[5] = {1 , 0 , -1 , 0 , 1};

    int* island = (int*)malloc(m * 2 * n * sizeof(int));

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(!grid[i][j]){
                continue;
            }

            long long total = grid[i][j];
            grid[i][j] = 0;

            int head = 0;
            int tail = 0;
            island[tail++] = i;
            island[tail++] = j;

            while(head < tail){
                int x = island[head++];
                int y = island[head++];
                for(int d = 0; d < 4; d++){
                    int a = x + dirs[d];
                    int b = y + dirs[d + 1];
                    if(a >= 0 && a < m && b >= 0 && b < n && grid[a][b]){
                        total += grid[a][b];
                        grid[a][b] = 0;
                        island[tail++] = a;
                        island[tail++] = b;
                    }
                }
            }
            if(total % k == 0){
                ans++;
            }
        }
    }
    return ans;
}
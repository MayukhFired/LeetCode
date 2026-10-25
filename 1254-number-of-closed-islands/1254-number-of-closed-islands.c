typedef struct{
    int r;
    int c;
} Point;

bool bfs(int x , int y , int m , int n , int** grid  , bool** visit){
    Point* q = (Point*)malloc((m * n) * sizeof(Point));
    int head = 0;
    int tail = 0;

    q[tail++] = (Point){x , y};
    visit[x][y] = true;
    bool isClosed = true;

    int dirx[4] = {0 , 1 , 0 , -1};
    int diry[4] = {-1 , 0 , 1 , 0};

    while(head < tail){
        int x1 = q[head].r;
        int y1 = q[head].c;
        head++;

        for(int i = 0;i < 4; i++){
            int r = x1 + dirx[i];
            int c = y1 + diry[i];
            if(r < 0 || r >= m || c < 0 || c >= n){
                isClosed = false;
            }else if(grid[r][c] == 0 && !visit[r][c]){
                visit[r][c] = true;
                q[tail++] = (Point){r , c};
            }
        }
    }
    free(q);
    return isClosed;
}

int closedIsland(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];

    bool** visit = (bool**)malloc(m * sizeof(bool*));
    for(int i = 0; i < m; i++){
        visit[i] = (bool*)calloc(n , sizeof(bool));
    }
    int count = 0;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 0 && !visit[i][j]){
                if(bfs(i , j , m , n, grid , visit)){
                    count++;
                }
            }
        }
    }

    for(int i = 0; i < m; i++){
        free(visit[i]);
    }
    free(visit);
    return count;
}
// 1--------------------------------------------------------------------------------1
// typedef struct{
//     int r;
//     int c;
// } Point;

// bool bfs(int x , int y , int m , int n , int** grid  , bool** visit){
//     Point* q = (Point*)malloc((m * n) * sizeof(Point));
//     int head = 0;
//     int tail = 0;

//     q[tail++] = (Point){x , y};
//     visit[x][y] = true;
//     bool isClosed = true;

//     int dirx[4] = {0 , 1 , 0 , -1};
//     int diry[4] = {-1 , 0 , 1 , 0};

//     while(head < tail){
//         int x1 = q[head].r;
//         int y1 = q[head].c;
//         head++;

//         for(int i = 0;i < 4; i++){
//             int r = x1 + dirx[i];
//             int c = y1 + diry[i];
//             if(r < 0 || r >= m || c < 0 || c >= n){
//                 isClosed = false;
//             }else if(grid[r][c] == 0 && !visit[r][c]){
//                 visit[r][c] = true;
//                 q[tail++] = (Point){r , c};
//             }
//         }
//     }
//     free(q);
//     return isClosed;
// }
// 1--------------------------------------------------------------------------------1

void floodfill(int r , int c , int m , int n, int** grid){
    if(r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != 0){
        return;
    }

    grid[r][c] = 1;

    floodfill(r + 1 , c , m , n , grid);
    floodfill(r - 1 , c , m , n, grid);
    floodfill(r , c + 1 , m , n, grid);
    floodfill(r , c - 1 , m , n, grid);
}

int closedIsland(int** grid, int gridSize, int* gridColSize) {
// 1-------------------------------------------------------------------------1
    // int m = gridSize;
    // int n = gridColSize[0];

    // bool** visit = (bool**)malloc(m * sizeof(bool*));
    // for(int i = 0; i < m; i++){
    //     visit[i] = (bool*)calloc(n , sizeof(bool));
    // }
    // int count = 0;

    // for(int i = 0; i < m; i++){
    //     for(int j = 0; j < n; j++){
    //         if(grid[i][j] == 0 && !visit[i][j]){
    //             if(bfs(i , j , m , n, grid , visit)){
    //                 count++;
    //             }
    //         }
    //     }
    // }

    // for(int i = 0; i < m; i++){
    //     free(visit[i]);
    // }
    // free(visit);
    // return count;
// 1----------------------------------------------------------------------------------1
    int m = gridSize;
    int n = gridColSize[0];

    for(int j = 0; j < n; j++){
        if(grid[0][j] == 0){
            floodfill(0 , j , m , n , grid);
        }
        if(grid[m - 1][j] == 0){
            floodfill(m - 1 , j , m , n , grid);
        }
    }

    for(int i = 0; i < m; i++){
        if(grid[i][0] == 0){
            floodfill(i , 0 , m , n, grid);
        }
        if(grid[i][n - 1] == 0){
            floodfill(i , n - 1 , m , n , grid);
        }
    }

    int count = 0;
    for(int i = 0; i < m - 1; i++){
        for(int j = 0; j < n - 1; j++){
            if(grid[i][j] == 0){
                count++;
                floodfill(i , j , m , n , grid);
            }
        }
    }
    return count;
}
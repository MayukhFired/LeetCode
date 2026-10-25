class Solution {
public:
// 1---------------------------------------------------------------------------------------------------------1
    // bool bfs(int x , int y , int m , int n , vector<vector<int>>& grid , vector<vector<bool>>& visit){
    //     queue<pair<int , int>> q;
    //     q.push({x , y});
    //     visit[x][y] = 2;
    //     bool isClosed = true;

    //     vector<int> dirx{0 , 1 , 0 , -1};
    //     vector<int> diry{-1 , 0 , 1 , 0};

    //     while(!q.empty()){
    //         x = q.front().first;
    //         y = q.front().second;
    //         q.pop();

    //         for(int i = 0; i < 4; i++){
    //             int r = x + dirx[i];
    //             int c = y + diry[i];
    //             if(r < 0 || r >= m || c < 0 || c >= n){
    //                 isClosed = false;
    //             }else if(grid[r][c] == 0 && !visit[r][c]){
    //                 q.push({r , c});
    //                 visit[r][c] = true;
    //             }
    //         }
    //     }
    //     return isClosed;
    // }
// 1---------------------------------------------------------------------------1
    void floodfill(int r , int c , int m , int n , vector<vector<int>>& grid){
        if(r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != 0){
            return;
        }

        grid[r][c] = 1;

        floodfill(r + 1 , c , m , n , grid);
        floodfill(r - 1 , c , m , n , grid);
        floodfill(r , c + 1 , m , n , grid);
        floodfill(r , c - 1 , m , n , grid);
    }
    int closedIsland(vector<vector<int>>& grid) {
// 1----------------------------------------------------------------1
    //     int m = grid.size();
    //     int n = grid[0].size();
    //     vector<vector<bool>> visit(m , vector<bool>(n));
    //     int count = 0;
    //     for(int i = 0; i < m; i++){
    //         for(int j = 0; j < n; j++){
    //             if(grid[i][j] == 0 && !visit[i][j] && bfs(i , j , m , n , grid , visit)){
    //                 count++;
    //             }
    //         }
    //     }
    //     return count;
    // }
// 1---------------------------------------------------------------1
    int m = grid.size();
    int n = grid[0].size();

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
    for(int i = 1; i < m - 1; i++){
        for(int j = 1; j < n - 1; j++){
            if(grid[i][j] == 0){
                count++;
                floodfill(i , j , m , n , grid);
            }
        }
    }
    return count;
    }
};
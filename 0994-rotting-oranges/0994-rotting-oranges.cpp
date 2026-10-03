class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int , int>> q;
        
        int fresh = 0;
        int min = 0;

        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] == 2){
                    q.push({r , c});
                }else if(grid[r][c] == 1){
                    fresh++;
                }
            }
        }

        if(fresh == 0){
            return 0;
        }

        int dRow[] = {1 , -1 , 0 , 0};
        int dCol[] = {0 , 0 , 1 , -1};

        while(!q.empty() && fresh > 0){
            min++;
            int curr_level = q.size();

            for(int i = 0; i < curr_level; i++){
                auto [r , c] = q.front();
                q.pop();

                for(int j = 0; j < 4; j++){
                    int row = r + dRow[j];
                    int col = c + dCol[j];

                    if(row >= 0 && row < rows && col >= 0 && col < cols && grid[row][col] == 1){
                        grid[row][col] = 2;
                        fresh--;
                        q.push({row , col});
                    }
                }
            }
        }

        return (fresh == 0) ? min : -1;
    }
};
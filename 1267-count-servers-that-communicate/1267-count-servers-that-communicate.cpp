class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
    // 1---------------------------------------------------------------------------------------1
        // int count = 0;
        // int m = grid.size();
        // int n = grid[0].size();

        // for(int row = 0; row < m; row++){
        //     for(int col = 0; col < n; col++){
        //         if(grid[row][col] == 1){
        //             bool can = false;
        //             for(int otherCol = 0; otherCol < n; otherCol++){
        //                 if(otherCol != col && grid[row][otherCol] == 1){
        //                     can = true;
        //                     break;
        //                 }
        //             }
        //             if(can){
        //                 count++;
        //             }else{
        //                 for(int otherRow = 0; otherRow < m; otherRow++){
        //                     if(otherRow != row && grid[otherRow][col] == 1){
        //                         can = true;
        //                         break;
        //                     }
        //                 }
        //                 if(can){
        //                     count++;
        //                 }
        //             }
        //         }
        //     }
        // }
        // return count;
    // 1--------------------------------------------------------------------------------------1

        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> rowCounts(m , 0);
        vector<int> colCounts(n , 0);

        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 1){
                    rowCounts[row]++;
                    colCounts[col]++;
                }
            }
        }

        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 1){
                    if(rowCounts[row] > 1 || colCounts[col] > 1){
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
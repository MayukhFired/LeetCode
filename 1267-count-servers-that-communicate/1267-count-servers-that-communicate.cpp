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

    // 2--------------------------------------------------------------------------------------2
        // int count = 0;
        // int m = grid.size();
        // int n = grid[0].size();
        // vector<int> rowCounts(m , 0);
        // vector<int> colCounts(n , 0);

        // for(int row = 0; row < m; row++){
        //     for(int col = 0; col < n; col++){
        //         if(grid[row][col] == 1){
        //             rowCounts[row]++;
        //             colCounts[col]++;
        //         }
        //     }
        // }

        // for(int row = 0; row < m; row++){
        //     for(int col = 0; col < n; col++){
        //         if(grid[row][col] == 1){
        //             if(rowCounts[row] > 1 || colCounts[col] > 1){
        //                 count++;
        //             }
        //         }
        //     }
        // }

        // return count;
    // 2------------------------------------------------------------------------------------2

    // 3------------------------------------------------------------------------------------3
        // int count = 0;
        // int m = grid.size();
        // int n = grid[0].size();
        // vector<int> colCount(n , 0);
        // vector<int> InRow(m , -1);

        // for(int row = 0; row < m; row++){
        //     int countRow = 0;
        //     for(int col = 0; col < n; col++){
        //         if(grid[row][col]){
        //             count++;
        //             countRow++;
        //             colCount[col]++;
        //             if(countRow == 1){
        //                 InRow[row] = col;
        //             }else{
        //                 InRow[row] = -1;
        //             }
        //         }
        //     }
        // }
        // for(int row = 0; row < m; row++){
        //     int col = InRow[row];
        //     if(col != -1 && colCount[col] == 1){
        //         count--;
        //     }
        // }
        // return count;
    // 3------------------------------------------------------------------------------------3
        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for(int rowIndex = 0; rowIndex < rows; rowIndex++){
            int rowCounts = 0;
            int serverIndex = -1;
            for(int colIndex = 0; colIndex < cols; colIndex++){
                if(grid[rowIndex][colIndex]){
                    if(rowCounts == 0){
                        serverIndex = colIndex;
                    }
                    rowCounts += 1;
                }
            }

            bool can = (rowCounts != 1);
            if(!can){
                for(int i = 0; i < rows; i++){
                    if(i != rowIndex && grid[i][serverIndex]){
                        can = true;
                        break;
                    }
                }
            }
            if(can){
                count += rowCounts;
            }
        }
        return count;
    }
};
int countServers(int** grid, int gridSize, int* gridColSize) {
// 1--------------------------------------------------------------------------------------------1
    // int count = 0;
    // int numRow = gridSize;
    // int numCol = gridColSize[0];

    // for(int row = 0; row < numRow; row++){
    //     for(int col = 0; col < numCol; col++){
    //         if(grid[row][col] == 1){
    //             bool can = false;
    //             for(int otherCol = 0; otherCol < numCol; otherCol++){
    //                 if(otherCol != col && grid[row][otherCol] == 1){
    //                     can = true;
    //                     break;
    //                 }
    //             }
    //             if(can){
    //                 count++;
    //             }else{
    //                 for(int otherRow = 0; otherRow < numRow; otherRow++){
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
// 1-------------------------------------------------------------------------------------------------1

// 2-------------------------------------------------------------------------------------------------2
    // int m = gridSize;
    // int n = gridColSize[0];
    // int count = 0;
    // int* rowCounts = (int*)calloc(m , sizeof(int));
    // int* colCounts = (int*)calloc(n , sizeof(int));

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

    // free(rowCounts);
    // free(colCounts);
    // return count;
// 2------------------------------------------------------------------------------------------------2
     
    int count = 0;
    int m = gridSize;
    int n = gridColSize[0];
    int* colCount = (int*)calloc(n , sizeof(int));
    int* InRow = (int*)malloc(m * sizeof(int));
    for(int i = 0; i < m; i++){
        InRow[i] = -1;
    }

    for(int row = 0; row < m; row++){
        int countRow = 0;
        for(int col = 0; col < n; col++){
            if(grid[row][col]){
                count++;
                countRow++;
                colCount[col]++;
                if(countRow == 1){
                    InRow[row] = col;
                }else{
                    InRow[row] = -1;
                }
            }
        }
    }

    for(int row = 0; row < m; row++){
        int col = InRow[row];
        if(col != -1 && colCount[col] == 1){
            count--;
        }
    }

    free(InRow);
    free(colCount);
    return count;
}
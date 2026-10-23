int countNegatives(int** grid, int gridSize, int* gridColSize) {
    // int count = 0;
    // for(int i = 0; i < gridSize; i++){
    //     for(int j = 0; j < gridColSize[i]; j++){
    //         if(grid[i][j] < 0){
    //             count += gridColSize[i] - j;
    //             break;
    //         }
    //     }
    // }
    // return count;

    int count = 0;
    int i = gridSize - 1;
    int j = 0; 
    int n = gridColSize[0];

    while(i >= 0 && j < n){
        if(grid[i][j] >= 0){
            j++;
        }else{
            count += n - j;
            i--;
        }
    }
    return count;
}
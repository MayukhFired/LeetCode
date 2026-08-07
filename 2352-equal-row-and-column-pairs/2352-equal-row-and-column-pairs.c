int equalPairs(int** grid, int gridSize, int* gridColSize) {
    int count = 0;
    for(int r = 0; r < gridSize; r++){
        for(int c = 0; c < gridSize; c++){
            int is_equal = true;
            for(int i = 0; i < gridSize; i++){
                if(grid[r][i] != grid[i][c]){
                    is_equal = false;
                }
            }
            if(is_equal){
                count++;
            }
        }
    }
    return count;
}
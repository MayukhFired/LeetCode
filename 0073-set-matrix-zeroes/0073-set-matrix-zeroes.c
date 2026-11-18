void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    bool zeroinFirst = false;
    for(int row = 0; row < matrixSize; row++){
        if(matrix[row][0] == 0){
            zeroinFirst = true;
        }
        for(int col = 1; col < matrixColSize[0]; col++){
            if(matrix[row][col] == 0){
                matrix[row][0] = 0;
                matrix[0][col] = 0;
            }
        }
    }

    for(int row = matrixSize - 1; row >= 0; row--){
        for(int col = matrixColSize[0] - 1; col >= 1; col--){
            if(matrix[row][0] == 0 || matrix[0][col] == 0){
                matrix[row][col] = 0;
            }
        }
        if(zeroinFirst){
            matrix[row][0] = 0;
        }
    }
}
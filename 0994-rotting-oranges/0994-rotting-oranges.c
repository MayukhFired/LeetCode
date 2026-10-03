typedef struct{
    int r;
    int c;
} Point;

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = gridColSize[0];
    int len = rows * cols;
    Point queue[len];
    int head = 0;
    int tail = 0;

    int fresh = 0;
    int min = 0;

    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            if(grid[r][c] == 2){
                queue[tail++] = (Point){r , c};
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

    while(head < tail && fresh > 0){
        min++;
        int curr_level = tail - head;
        for(int i = 0; i < curr_level; i++){
            Point curr = queue[head++];
            for(int j = 0; j < 4; j++){
                int row = curr.r + dRow[j];
                int col = curr.c + dCol[j];

                if(row >= 0 && row < rows && col >= 0 && col < cols && grid[row][col] == 1){
                    grid[row][col] = 2;
                    fresh--;
                    queue[tail++] = (Point){row , col};
                }
            }
        }
    }
    return (fresh == 0) ? min : -1;
}
typedef struct{
    int r;
    int c;
} Point;

int nearestExit(char** maze, int mazeSize, int* mazeColSize, int* entrance, int entranceSize) {
    int rows = mazeSize;
    int cols = mazeColSize[0];

    int startRow = entrance[0];
    int startCol = entrance[1];

    int len = rows * cols;
    Point* queue = (Point*)malloc(len * sizeof(Point));
    int* stepsQueue = (int*)malloc(len * sizeof(int));

    int head = 0;
    int tail = 0;

    queue[tail] = (Point){startRow , startCol};
    stepsQueue[tail] = 0;
    tail++;

    maze[startRow][startCol] = '+';

    int dRow[] = {-1 , 1 , 0 , 0};
    int dCol[] = {0 , 0 , -1 , 1};
    int res = -1;

    while(head < tail){
        Point curr = queue[head];;
        int steps = stepsQueue[head];
        head++;

        for(int i = 0; i < 4; i++){
            int nr = curr.r + dRow[i];
            int nc = curr.c + dCol[i];

            if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && maze[nr][nc] == '.'){
                if(nr == 0 || nr == rows - 1 || nc == 0 || nc == cols - 1){
                    res = steps + 1;
                    goto cleanup;
                }

                maze[nr][nc] = '+';
                queue[tail] = (Point){nr , nc};
                stepsQueue[tail] = steps + 1;
                tail++;
            }
        }
    }
cleanup:
    free(queue);
    free(stepsQueue);
    return res;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** createGrid(int m, int n, int* returnSize) {
    *returnSize = m;
    char** grid = (char**)malloc(m * sizeof(char*));
    grid[0] = (char*)malloc((n + 1) * sizeof(char));
    for(int i = 0; i < n ; i++){
        grid[0][i] = '.';
    }
    grid[0][n] = '\0';

    char* row = (char*)malloc((n + 1) * sizeof(char));
    for(int i = 0; i < n - 1; i++){
        row[i] = '#';
    }

    row[n - 1] = '.';
    row[n] = '\0';

    for(int i = 1; i < m; i++){
        grid[i] = (char*)malloc((n + 1) *sizeof(char));
        strcpy(grid[i] , row);
    }

    free(row);
    return grid;
}
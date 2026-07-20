/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** shiftGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes) {
    int m = gridSize;
    int n = gridColSize[0];
    int total = m * n;
    k = k % total;

    *returnSize = m;
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    int** result = (int**)malloc(m * sizeof(int*));
    for(int r = 0; r < m; r++){
        result[r] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[r] = n;
    }

    for(int r = 0; r < m; r++){
        for(int c = 0; c < n; c++){
            int flat_index = r * n + c;
            int new_flat_index = (flat_index + k) % total;
            int new_r = new_flat_index / n;
            int new_c = new_flat_index % n;
            result[new_r][new_c] = grid[r][c];
        }
    }

    return result;
}
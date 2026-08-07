//Brute force solution of this problem 
// int equalPairs(int** grid, int gridSize, int* gridColSize) {
//     int count = 0;
//     for(int r = 0; r < gridSize; r++){
//         for(int c = 0; c < gridSize; c++){
//             int is_equal = true;
//             for(int i = 0; i < gridSize; i++){
//                 if(grid[r][i] != grid[i][c]){
//                     is_equal = false;
//                 }
//             }
//             if(is_equal){
//                 count++;
//             }
//         }
//     }
//     return count;
// }

#define BASE 131
#define MOD 1000000007

int equalPairs(int** grid, int gridSize, int* gridColSize){
    int RowHashes[gridSize];
    int ColHashes[gridSize];
    for(int i = 0; i < gridSize; i++){
        long long RowH = 0;
        long long ColH = 0;
        for(int j = 0; j < gridSize; j++){
            RowH = (RowH * BASE + grid[i][j]) % MOD;
            ColH = (ColH * BASE + grid[j][i]) % MOD;
        }
        RowHashes[i] = RowH;
        ColHashes[i] = ColH;
    }
    int count = 0;
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < gridSize; j++){
            if(RowHashes[i] == ColHashes[j]){
                count++;
            }
        }
    }

    return count;
}
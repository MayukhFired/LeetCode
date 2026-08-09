#define Max(a , b) ((a) > (b) ? (a) : (b))
int Solve(int i , int m , int n , int* suffix_nums , int** memo){
    if(i + 2 * m >= n){
        return suffix_nums[i];
    }

    if(memo[i][m] != -1){
        return memo[i][m];
    }

    int max_stone = 0;
    for(int x = 1; x <= 2 * m && i + x <= n; x++){
        int opponent_score = Solve(i + x , Max(m , x) , n , suffix_nums , memo);
        int current_score = suffix_nums[i] - opponent_score;
        max_stone = Max(max_stone , current_score);
    } 

    return memo[i][m] = max_stone;
}

int stoneGameII(int* piles, int pilesSize) {
    int* suffix_nums = (int*)malloc((pilesSize + 1) * sizeof(int));
    suffix_nums[pilesSize] = 0; 
    for(int i = pilesSize - 1; i >= 0; i--){
        suffix_nums[i] = suffix_nums[i + 1] + piles[i];
    }

    int** memo = (int**)malloc(pilesSize * sizeof(int*));
    for(int i = 0; i < pilesSize; i++){
        memo[i] = (int*)malloc((pilesSize + 1) * sizeof(int));
        memset(memo[i] , -1 , (pilesSize + 1) * sizeof(int));
    }
    int result = Solve(0 , 1 , pilesSize , suffix_nums , memo);
    for(int i = 0; i < pilesSize; i++){
        free(memo[i]);
    }
    free(memo);
    free(suffix_nums);
    return result;
}
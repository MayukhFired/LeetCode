#define max(a , b) ((a) > (b) ? (a) : (b))
#define min(a , b) ((a) < (b) ? (a) : (b))

int solve(int i , int j , int* nums, int memo[501][501]){
    if(i > j){
        return 0;
    }

    if(i == j){
        return nums[i];
    }

    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    int take_i = nums[i] + min(solve(i + 2 , j , nums , memo) , solve(i + 1 , j - 1 , nums , memo));
    int take_j = nums[j] + min(solve(i , j - 2 , nums , memo) , solve(i + 1 , j - 1 , nums , memo));
    return memo[i][j] = max(take_i , take_j); 
}

bool stoneGame(int* piles, int pilesSize) {
    int sum = 0;
    for(int k = 0; k < pilesSize; k++){
        sum += piles[k];
    }

    int memo[501][501];
    memset(memo, -1, sizeof(memo));
    int p_1 = solve(0 , pilesSize - 1 , piles , memo);
    int p_2 = sum - p_1;
    return (p_1 >= p_2);
}

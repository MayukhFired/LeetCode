#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
// int solve(int i , int j , int* nums , int memo[21][21]){
    int solve(int i , int j , int* nums , int memo[21][21]){
    if(i > j){
        return 0;
    }

    if(i == j){
        return nums[i];
    }

    if(memo[i][j] != -1){
        return memo[i][j];
    }

    // int take_1 = nums[i] + min(solve(i + 2 , j , nums , memo) , solve(i + 1 , j - 1, nums , memo));
    // int take_2 = nums[j] + min(solve(i , j - 2 , nums , memo) , solve(i + 1 , j - 1 ,nums , memo));
    // return memo[i][j] = max(take_1 , take_2);
    int take_1 = nums[i] - solve(i + 1 , j , nums , memo);
    int take_2 = nums[j] - solve(i , j - 1 , nums , memo);
    return memo[i][j] = max(take_1 , take_2);
}

bool predictTheWinner(int* nums, int numsSize) {
    int sum = 0;
    int memo[21][21];
    for(int i = 0; i < 21; i++) {
        for(int j = 0; j < 21; j++) {
            memo[i][j] = -1;
        }
    }
    // for(int k = 0; k < numsSize; k++){
    //     sum += nums[k];
    // }

    // int p_1 = solve(0 , numsSize - 1 , nums, memo);
    // int p_2 = sum - p_1;
    // return (p_1 >= p_2);
    return (solve(0 , numsSize - 1 , nums, memo) >= 0);
}
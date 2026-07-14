#define MOD 1000000007


int gcd(int a , int b){
    while(b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int dp[201][201][201];

int solve(int i , int g1 , int g2 , int* nums , int numsSize , int max_val){
    if(i == numsSize){
        return (g1 > 0 && g2 > 0 && g1 == g2) ? 1 : 0;
    }

    if(dp[i][g1][g2] != -1){
        return dp[i][g1][g2];
    }

    long long ans = solve(i + 1 , g1 ,  g2 , nums , numsSize , max_val);

    int next_g1 = (g1 == 0) ? nums[i] : gcd(g1 , nums[i]);
    ans = (ans + solve(i + 1 , next_g1 , g2 , nums , numsSize , max_val)) % MOD;

    int next_g2 = (g2 == 0) ? nums[i] : gcd(g2 , nums[i]);
    ans = (ans + solve(i + 1 , g1 , next_g2 , nums , numsSize , max_val)) % MOD;

    return dp[i][g1][g2] = ans;
}
int subsequencePairCount(int* nums, int numsSize) {
    int max_val = 0;
    for(int i = 0; i < numsSize ; i++){
        if(nums[i] > max_val){
            max_val = nums[i];
        }
    }

    for(int i = 0; i <= numsSize; i++){
        for(int j = 0; j <= max_val; j++){
            for(int k = 0; k <= max_val; k++){
                dp[i][j][k] = -1;
            }
        }
    }

    return solve(0 , 0 , 0 , nums , numsSize , max_val);
}
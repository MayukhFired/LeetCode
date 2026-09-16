static const long long MOD = 1000000007LL;
long long quickPow(long long a , long long e){
    long long result = 1;
    while(e > 0){
        if(e & 1){
            result = result * a % MOD;
        }
        a = a * a % MOD;
        e >>= 1;
    }
    return result;
}
int numberOfSets(int n, int k) {
    //This solution uses dp method to solve the problem

    // const int MOD = 1000000007;
    // int* dp = malloc(n * sizeof(int));
    // int* prefixSums = calloc((n + 1) , sizeof(int));
    // for(int j = 0; j < n; j++){
    //     dp[j] = 1;
    //     prefixSums[j + 1] = (prefixSums[j] + dp[j]) % MOD;
    // }

    // for(int i = 1; i <= k ; i++){
    //     dp[0] = 0;
    //     for(int j = 1; j < n; j++){
    //         dp[j] = (dp[j - 1] + prefixSums[j]) % MOD;
    //     }
    //     for(int j = 0; j < n; j++){
    //         prefixSums[j + 1] = (prefixSums[j] + dp[j]) % MOD;
    //     }
    // }

    // int answer = dp[n - 1];
    // free(dp);
    // free(prefixSums);
    // return answer;

    int m = 2 * k;
    long long num = 1;
    long long d = 1;
    for(int i = 1; i <= m; i++){
        num = num * (n + k - i) % MOD;
        d = d * i % MOD;
    }

    return (int)(num * quickPow(d , MOD - 2) % MOD);
}
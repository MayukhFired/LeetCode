int distinctSubseqII(char* s) {
    int n = strlen(s);
    const int MOD = 1e9 + 7;

    int* dp = (int*)malloc((n + 1) * sizeof(int));
    dp[0] = 1;
    int last[26];
    for(int i = 0; i < 26; i++){
        last[i] = -1;
    }

    for(int i = 0; i < n; i++){
        int x = s[i] - 'a';
        dp[i + 1] = (dp[i] * 2) % MOD;
        if(last[x] >= 0){
            dp[i + 1] -= dp[last[x]];
        }
        dp[i + 1] = (dp[i + 1] + MOD) % MOD;
        last[x] = i;
    }

    int result = dp[n] - 1;
    if(result < 0){
        result += MOD;
    }

    free(dp);
    return result;
}
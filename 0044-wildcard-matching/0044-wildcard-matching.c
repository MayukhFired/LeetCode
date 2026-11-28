bool solve(const char* s , const char* p , int i , int j , int** dp) {
    if(i < 0 && j < 0) {
        return true;
    }
    if(j < 0 && i >= 0) {
        return false;
    }

    if(i < 0 && j >= 0) {
        for(int k = 0; k <= j; k++) {
            if(p[k] != '*') {
                return false;
            }
        }
        return true;
    }

    if(dp[i][j] != -1) {
        return dp[i][j] == 1;
    }

    bool ans = false;
    if(p[j] == s[i] || p[j] == '?') {
        ans = solve(s , p , i - 1, j - 1 , dp);
    }else if(p[j] == '*') {
        ans = solve(s , p , i - 1 , j , dp) || solve(s , p , i , j - 1 , dp);
    }

    dp[i][j] = ans ? 1 : 0;
    return ans;
}

bool isMatch(char* s, char* p) {
    int n = strlen(s);
    int m = strlen(p);

    if(n == 0) {
        for(int k = 0; k < m; k++) {
            if(p[k] != '*') {
                return false;
            }
        }
        return true;
    }

    int** dp = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++) {
        dp[i] = (int*)malloc(m * sizeof(int));
        memset(dp[i] , -1 , m * sizeof(int));
    }

    bool res = solve(s , p , n - 1, m - 1 , dp);

    for(int i = 0; i < n; i++) {
        free(dp[i]);
    }
    free(dp);
    return res;
}
bool dp(int i , int j , const char* s , const char* p , int n , int m , int* memo){
    int cache_idx = i * (m + 1) + j;

    if(memo[cache_idx] != -1){
        return memo[cache_idx];
    }

    bool ans;
    if(j == m){
        ans = (i == n);
    }else{
        bool first_match = (i < n && (p[j] == s[i] || p[j] == '.'));

        if(j + 1 < m && p[j + 1] == '*'){
            ans = dp(i , j + 2 , s , p , n , m , memo) || (first_match && dp(i + 1 , j , s , p , n , m , memo));
        }else{
            ans = first_match && dp(i + 1 , j + 1 , s , p , n , m , memo);
        }
    }
    return memo[cache_idx] = ans;
}

bool isMatch(char* s, char* p) {
    int n = strlen(s);
    int m = strlen(p);

    int total_states = (n + 1) * (m + 1);
    int* memo = (int*)malloc(total_states * sizeof(int));

    memset(memo , -1 , total_states * sizeof(int));
    bool result = dp(0 , 0 , s , p , n, m , memo);
    free(memo);
    return result;
}
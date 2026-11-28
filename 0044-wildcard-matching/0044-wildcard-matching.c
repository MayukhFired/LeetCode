// 1--------------------------------------------------------------------------1
// bool solve(const char* s , const char* p , int i , int j , int** dp) {
//     if(i < 0 && j < 0) {
//         return true;
//     }
//     if(j < 0 && i >= 0) {
//         return false;
//     }

//     if(i < 0 && j >= 0) {
//         for(int k = 0; k <= j; k++) {
//             if(p[k] != '*') {
//                 return false;
//             }
//         }
//         return true;
//     }

//     if(dp[i][j] != -1) {
//         return dp[i][j] == 1;
//     }

//     bool ans = false;
//     if(p[j] == s[i] || p[j] == '?') {
//         ans = solve(s , p , i - 1, j - 1 , dp);
//     }else if(p[j] == '*') {
//         ans = solve(s , p , i - 1 , j , dp) || solve(s , p , i , j - 1 , dp);
//     }

//     dp[i][j] = ans ? 1 : 0;
//     return ans;
// }
// 1--------------------------------------------------------------------------------1

bool isMatch(char* s, char* p) {
// 1-------------------------------------------------------1 
    // int n = strlen(s);
    // int m = strlen(p);

    // if(n == 0) {
    //     for(int k = 0; k < m; k++) {
    //         if(p[k] != '*') {
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    // int** dp = (int**)malloc(n * sizeof(int*));
    // for(int i = 0; i < n; i++) {
    //     dp[i] = (int*)malloc(m * sizeof(int));
    //     memset(dp[i] , -1 , m * sizeof(int));
    // }

    // bool res = solve(s , p , n - 1, m - 1 , dp);

    // for(int i = 0; i < n; i++) {
    //     free(dp[i]);
    // }
    // free(dp);
    // return res;
// 1---------------------------------------------------------1

// 1---------------------------------------------------------------1
    // int n = strlen(s);
    // int m = strlen(p);
    // bool** dp = (bool**)malloc((n + 1) * sizeof(bool*));
    // for(int i = 0; i <= n; i++) {
    //     dp[i] = (bool*)calloc((m + 1) , sizeof(bool));
    // }
    // dp[0][0] = true;

    // for(int j = 1; j <= m; j++) {
    //     if(p[j - 1] == '*') {
    //         dp[0][j] = dp[0][j - 1];
    //     }else{
    //         dp[0][j] = false;
    //     }
    // }

    // for(int i = 1; i <= n; i++) {
    //     for(int j = 1; j <= m; j++) {
    //         if(p[j - 1] == s[i - 1] || p[j - 1] == '?') {
    //             dp[i][j] = dp[i - 1][j - 1];
    //         }else if(p[j - 1] == '*') {
    //             dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
    //         }else{
    //             dp[i][j] = false;
    //         }
    //     }
    // }

    // bool res = dp[n][m];
    // for(int i = 0; i <= n; i++) {
    //     free(dp[i]);
    // }
    // free(dp);
    // return res;
// 1--------------------------------------------------------------------------1
    int i = 0;
    int j = 0;
    int startIdx = -1;
    int matchIdx = 0;
    int n = (int)strlen(s);
    int m = (int)strlen(p);

    while(i < n) {
        if(j < m && (p[j] == s[i] || p[j] == '?')) {
            i++;
            j++;
        }else if(j < m && p[j] == '*') {
            startIdx = j;
            matchIdx = i;
            j++;
        }else if(startIdx != -1) {
            j = startIdx + 1;
            matchIdx++;
            i = matchIdx;
        }else{
            return false;
        }
    }

    while(j < m && p[j] == '*') {
        j++;
    }

    return j == m;
}
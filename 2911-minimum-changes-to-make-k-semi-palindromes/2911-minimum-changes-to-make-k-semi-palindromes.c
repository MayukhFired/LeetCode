#define INF 10000
#define Min(a , b) ((a) < (b) ? (a) : (b))

static int memo[201][201];
static int cost[201][201];
static int temp[201][201];

static int solve(int idx , int k , int n){
    if(idx == n || k == 0){
        return (idx == n && k == 0) ? 0 : INF;
    }
    if(memo[idx][k] != -1){
        return memo[idx][k];
    }
    int res = INF;
    for(int len = 2; idx + len <= n; len++){
        int next = solve(idx + len , k - 1 , n);
        res = Min(res , cost[idx][len] + next); 
    }

    return memo[idx][k] = res;
}

int minimumChanges(char* s, int k) {
    int n = strlen(s);
    memset(memo , -1 , sizeof(memo));
    memset(cost , 0x3f , sizeof(cost));

    for(int d = 1; d <= n; d++){
        memset(temp , 0 , sizeof(temp));
        for(int len = 2 * d; len <= n; len += d){
            for(int idx = 0; idx + len <= n; idx++){
                int ops = 0;
                for(int o = 0; o < d; o++){
                    if(s[idx + o] != s[idx + len - d + o]){
                        ops++;
                    }
                }
                temp[idx][len] = ops + temp[idx + d][len - 2 * d];
                cost[idx][len] = Min(cost[idx][len] , temp[idx][len]);
            }
        }
    }
    return solve(0 , k , n);
}
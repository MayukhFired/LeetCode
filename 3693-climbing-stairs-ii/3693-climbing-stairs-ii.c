int climbStairs(int n, int* costs, int costsSize) {
    int a = 0;
    int b = 0;
    int c = 0;

    for(int i = 0; i < n; i++){
        int n = fmin(a + 9 , fmin(b + 4 , c + 1)) + costs[i];
        a = b;
        b = c;
        c = n;
    }
    return c;
}
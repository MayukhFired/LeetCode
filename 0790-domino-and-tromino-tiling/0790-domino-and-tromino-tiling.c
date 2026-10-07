
int numTilings(int n) {
    if(n <= 2){
        return n;
    }
    if(n == 3){
        return 5;
    }

    int p3 = 1;
    int p2 = 2;
    int p1 = 5;

    for(int i = 4; i <= n; i++){
        int curr = (int)(((2LL * p1) + p3) % 1000000007);
        p3 = p2;
        p2 = p1;
        p1 = curr;
    }
    return p1;
}
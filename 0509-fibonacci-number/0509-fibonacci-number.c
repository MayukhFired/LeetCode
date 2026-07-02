

int fib(int n){
    int p1 = 1;
    int p2 = 0;
    int current = 0;
    if(n == 0){
        return 0;
    }
    if(n == 1 || n == 2){
        return 1;
    }

    for(int i = 2; i <= n; i++){
        current = p1 + p2;
        p2 = p1;
        p1 = current;
    }

    return current;
}
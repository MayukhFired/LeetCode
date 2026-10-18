#define MOD 1000000007
long long power(long long b , long long e , long long m){
    long long r = 1;
    b %= m;
    while(e > 0){
        if(e & 1){
            r = (r * b) % m;
        }
        b = (b * b) % m;
        e >>= 1;
    }
    return r;
}

int numOfWays(int* nums, int numsSize) {
    int* born = (int*)malloc((numsSize + 3) * sizeof(int));
    for(int i = 0; i < numsSize + 3; i++){
        born[i] = -1;
    }

    for(int i = 0; i < numsSize; i++){
        born[nums[i]] = i;
    }

    born[numsSize + 1] = -2;
    long long fact = 1;
    long long sizes = 1;

    for(int k = 2; k <= numsSize; k++){
        fact = (fact * k) % MOD;
    }

    int* stack = (int*)malloc((numsSize + 3) * sizeof(int));
    int stackTop = 0;
    stack[stackTop] = 0;

    for(int v = 1; v <= numsSize + 1; v++){
        while(stackTop > 0 && born[stack[stackTop]] > born[v]){
            stackTop--;
            sizes = (sizes * (v - stack[stackTop] - 1)) % MOD;
        }
        stackTop++;
        stack[stackTop] = v;
    }

    long long inv_sizes = power(sizes , MOD - 2 , MOD);
    long long ans = (fact * inv_sizes) % MOD;
    ans = (ans - 1 + MOD) % MOD;

    free(born);
    free(stack);
    return (int)ans;
}
#define max(a , b) ((a) > (b) ? (a) : (b))
int dfs(int* stoneValue , int left , int right , int** f){
    if(left == right){
        return 0;
    }

    if(f[left][right] != 0){
        return f[left][right];
    }

    int sum = 0;
    for(int i = left; i <= right; i++){
        sum += stoneValue[i];
    }
    int sum1 = 0;
    for(int i = left; i < right; i++){
        sum1 += stoneValue[i];
        int sum2 = sum - sum1;
        if(sum1 < sum2){
            f[left][right] = max(f[left][right] , dfs(stoneValue , left, i , f) + sum1);
        }else if(sum1 > sum2){
            f[left][right] = max(f[left][right] , dfs(stoneValue , i + 1, right , f) + sum2);
        }else{
            f[left][right] = max(f[left][right] , max(dfs(stoneValue , left , i , f) , dfs(stoneValue , i + 1 , right , f)) + sum1);
        }
    }
    return f[left][right];
}

int stoneGameV(int* stoneValue, int stoneValueSize) {
    int** f = (int**)malloc(sizeof(int*) * stoneValueSize);
    for(int i = 0; i < stoneValueSize; i++){
        f[i] = (int*)calloc(stoneValueSize , sizeof(int));
    }

    int result = dfs(stoneValue , 0 , stoneValueSize - 1 , f);
    for(int i = 0; i < stoneValueSize; i++){
        free(f[i]);
    }
    free(f);
    return result;
}
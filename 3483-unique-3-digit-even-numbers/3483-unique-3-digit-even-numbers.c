int totalNumbers(int* digits, int digitsSize) {
    int ans = 0;
    bool vis[1000] = {false};

    for(int i = 0; i < digitsSize; i++){
        if(digits[i] == 0){
            continue;
        }
        for(int j = 0; j < digitsSize; j++){
            if(j == i){
                continue;
            }
            for(int k = 0; k < digitsSize; k++){
                if(k == i || k == j || digits[k] % 2 != 0){
                    continue;
                }
                int x = digits[i] * 100 + digits[j] * 10 + digits[k];
                if(!vis[x]){
                    vis[x] = true;
                    ans++;
                }
            }
        }
    }
    return ans;
}
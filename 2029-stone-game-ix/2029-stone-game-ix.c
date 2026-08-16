bool stoneGameIX(int* stones, int stonesSize) {
    int c0 = 0;
    int c1 = 0;
    int c2 = 0;
    for(int i = 0; i < stonesSize; i++){
        if(stones[i] % 3 == 0){
            c0++;
        }else if(stones[i] % 3 == 1){
            c1++;
        }else{
            c2++;
        }
    }
    if(c0 % 2 == 0){
        return c1 > 0 && c2 > 0;
    }
    return abs(c1 - c2) > 2;
}
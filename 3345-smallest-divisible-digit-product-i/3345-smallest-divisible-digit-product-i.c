int smallestNumber(int n, int t) {
    
    while(true){
        int temp = n;
        int dp = 1;
        while(temp > 0){
            dp *= (temp % 10);
            temp /= 10;
        }

        if(dp % t == 0){
            return n;
        }
        n++;
    }
}
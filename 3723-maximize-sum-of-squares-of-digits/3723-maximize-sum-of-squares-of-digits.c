#define min(a , b) ((a) < (b) ? (a) : (b))
char* maxSumOfSquares(int num, int sum) {
    if(sum > 9 * num || sum < 0){
        return "";
    }

    char* ans = (char*)malloc((num + 1) * sizeof(char));
    if(ans == NULL){
        return "";
    }

    int index = 0;
    while(num-- > 0){
        int digit = min(9 , sum);
        ans[index++] = '0' + digit;
        sum -= digit;
    }

    ans[index] = '\0';
    return ans;
}
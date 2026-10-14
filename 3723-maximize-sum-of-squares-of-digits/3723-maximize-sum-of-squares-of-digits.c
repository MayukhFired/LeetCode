#define min(a , b) ((a) < (b) ? (a) : (b))
char* maxSumOfSquares(int num, int sum) {
    if(sum > 9 * num || sum < 0){
        return "";
    }

// 1----------------------------------------------------------1
    // char* ans = (char*)malloc((num + 1) * sizeof(char));
    // if(ans == NULL){
    //     return "";
    // }

    // int index = 0;
    // while(num-- > 0){
    //     int digit = min(9 , sum);
    //     ans[index++] = '0' + digit;
    //     sum -= digit;
    // }

    // ans[index] = '\0';
    // return ans;
// 1-----------------------------------------------------------1

    int r = sum % 9;
    char* ans = (char*)malloc(num + 1);
    int idx = 0;
    int nine = sum / 9;
    for(int i = 0; i < nine; i++){
        ans[idx++] = '9';
    }
    if(r > 0){
        ans[idx++] = '0' + r;
    }
    while(idx < num){
        ans[idx++] = '0';
    }
    ans[idx] = '\0';
    return ans;
}
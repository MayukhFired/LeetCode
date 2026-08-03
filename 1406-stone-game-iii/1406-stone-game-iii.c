//The first code is solved by using recursion method


#define max(a, b) ((a) > (b) ? (a) : (b))
// int solve(int* stoneValue , int i , int n , int* t){
//     if(i >= n){
//         return 0;
//     }

//     if(t[i] != -1){
//         return t[i];
//     }

//     int result = stoneValue[i] - solve(stoneValue , i + 1 , n , t);

//     if(i + 1 < n){
//         result = max(result , stoneValue[i] + stoneValue[i + 1] - solve(stoneValue , i + 2 , n ,t));
//     }

//     if(i + 2 < n){
//         result = max(result , stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - solve(stoneValue , i + 3 , n , t));
//     }

//     return t[i] = result;
// }

// char* stoneGameIII(int* stoneValue, int stoneValueSize) {
//     int memo[stoneValueSize + 1];
//     memset(memo , -1 , sizeof(memo));
//     int diff = solve(stoneValue , 0 , stoneValueSize, memo);

//     if(diff > 0){
//         return "Alice";
//     }else if(diff < 0){
//         return "Bob";
//     }
//     return "Tie";
// }
char* stoneGameIII(int* stoneValue, int stoneValueSize){
    int memo[stoneValueSize + 1];
    memset(memo , -1 , sizeof(int));
    int a = 0;//i + 1
    int b = 0;//i + 2
    int c = 0;//i + 3
    for(int i = stoneValueSize - 1; i >= 0; i--){
        int result = INT_MIN;
        result = max(result , stoneValue[i] - a);
        if(i + 1 < stoneValueSize){
            result = max(result , stoneValue[i] + stoneValue[i + 1] - b);
        }
        if(i + 2 < stoneValueSize){
            result = max(result , stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - c);
        }
        c = b; 
        b = a;
        a = result;
    }
    int diff = a;
    if(diff > 0){
        return "Alice";
    }
    if(diff < 0){
        return "Bob";
    }
    return "Tie";
}
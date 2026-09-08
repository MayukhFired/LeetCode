class Solution {
public:
    int countCommas(int n) {
        // int com = 0;
        // for(int i = 0; i <= n; i++){
        //     if(i > 999){
        //         com++;
        //     }
        // }
        // return com;
        return max((n - 999) , 0);
    }
};
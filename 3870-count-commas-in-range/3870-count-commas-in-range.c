int countCommas(int n) {
    // int com = 0;
    // for(int i = 0; i <= n; i++){
    //     if(i > 999){
    //         com++;
    //     }
    // }
    // return com;

    return fmax((n - 999) , 0);
}
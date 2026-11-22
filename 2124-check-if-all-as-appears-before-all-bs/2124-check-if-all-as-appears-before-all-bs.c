bool checkString(char* s) {
// 1--------------------------------------------1
    // int n = strlen(s);
    // int last_a = -1;
    // int first_b = n;

    // for(int i = 0; i < n; i++){
    //     if(s[i] == 'a'){
    //         last_a = fmax(last_a , i);
    //     }else{
    //         first_b = fmin(first_b , i);
    //     }
    // }

    // return last_a < first_b;
// 1----------------------------------------------1
    return strstr(s , "ba") == NULL;
}
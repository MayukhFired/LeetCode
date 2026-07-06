bool solve(char* s , int i , int j){
        if(i >= j){
            return true;
        }

        if(s[i] == s[j]){
            return solve(s , i + 1 , j - 1);
        }

        return false;
}

char* longestPalindrome(char* s) {
    int len = strlen(s);
    int Max_len = 0;
    int start = 0;

    for(int i = 0; i < len; i++){
        for(int j = i; j < len; j++){
            if(solve(s , i , j) == true){
                if(j - i + 1 > Max_len){
                    Max_len = j - i + 1;
                    start = i;
                }
            }
        }
    }
    char* target = (char*)malloc((Max_len + 1)* sizeof(char));
    strncpy(target , s + start , Max_len);
    target[Max_len] = '\0';

    return target;
}
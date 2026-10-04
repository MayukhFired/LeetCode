bool isValid(int index , int openCount , const char* s , int len , int** memo){
    if(index == len){
        return (openCount == 0);
    }

    if(memo[index][openCount] != -1){
        return memo[index][openCount];
    }

    bool valid = false;

    if(s[index] == '*'){
        valid |= isValid(index + 1 , openCount + 1 , s , len , memo);
        if(openCount > 0){
            valid |= isValid(index + 1 , openCount - 1 , s , len , memo);
        }
        valid |= isValid(index + 1 , openCount , s , len , memo);
    }else{
        if(s[index] == '('){
            valid |= isValid(index + 1 , openCount + 1 , s , len , memo);
        }else if(openCount > 0){
            valid |= isValid(index + 1 , openCount - 1 , s , len , memo);
        }
    }
    return memo[index][openCount] = valid;
}

bool checkValidString(char* s) {
    int len = strlen(s);
    if(len == 0){
        return true;
    }

    int** memo = (int**)malloc(len * sizeof(int*));
    for(int i = 0; i < len; i++){
        memo[i] = (int*)malloc((len + 1 ) * sizeof(int));
        memset(memo[i] , -1 , (len + 1) * sizeof(int));
    }

    bool res = isValid(0 , 0 , s , len , memo);

    for(int i = 0; i < len; i++){
        free(memo[i]);
    }

    free(memo);
    return res;
}
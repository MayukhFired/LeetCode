char* removeOuterParentheses(char* s) {
    int len = strlen(s);
    char* res = (char*)malloc(len * sizeof(char));
    char* stack = (char*)malloc((len / 2) * sizeof(char));
    int top = 0;
    int idx = 0;

    for(int i = 0; i < len; i++){
        char curr = s[i];
        if(curr == ')'){
            top--;
        }

        if(top > 0){
            res[idx++] = curr;
        }
        if(curr == '('){
            top++;
        }
    }
    free(stack);
    res[idx] = '\0';
    return res;
}
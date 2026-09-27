void reverse(char* start , char* end){
    while(start < end){
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

char* reverseParentheses(char* s) {
    int n = strlen(s);
    char* res = (char*)malloc((n + 1) * sizeof(char));
    int res_len = 0;
    int* idx_stack = (int*)malloc(n * sizeof(int));
    int top = -1;

    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == '('){
            idx_stack[++top] = res_len;
        }else if(s[i] == ')'){
            int start_idx = idx_stack[top--];
            if(res_len > start_idx){
                reverse(&res[start_idx] , &res[res_len - 1]);
            }
        }else{
            res[res_len++] = s[i];
        }
    }

    res[res_len] = '\0';
    free(idx_stack);
    return res;
}
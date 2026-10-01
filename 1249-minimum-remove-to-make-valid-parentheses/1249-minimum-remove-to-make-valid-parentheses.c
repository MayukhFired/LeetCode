char* minRemoveToMakeValid(char* s) {
    // int len = strlen(s);
    // int* stack = (int*)malloc(len * sizeof(int));
    // int top = -1;

    // for(int i = 0; i < len; i++){
    //     if(s[i] == '('){
    //         stack[++top] = i;
    //     }else if(s[i] == ')'){
    //         if(top != -1){
    //             top--;
    //         }else{
    //             s[i] = '*';
    //         }
    //     }
    // }

    // while(top != -1){
    //     s[stack[top--]] = '*';
    // }

    // free(stack);

    // int write_ptr = 0;
    // for(int read = 0; read < len; read++){
    //     if(s[read] != '*'){
    //         s[write_ptr++] = s[read];
    //     }
    // }
    // s[write_ptr] = '\0';
    // return s;

    int n = strlen(s);
    if (n == 0) {
        char* empty_res = malloc(1);
        empty_res[0] = '\0';
        return empty_res;
    }
    int* stack = malloc(n * sizeof(int));
    int top = 0;
    bool* drop = calloc(n, sizeof(bool));

    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            stack[top++] = i;
        }else if(s[i] == ')'){
            if(top > 0){
                top--;
            }else{
                drop[i] = true;
            }
        }
    }

    while(top > 0){
        drop[stack[--top]] = true;
    }

    char* res = malloc(n + 1);
    int k = 0;
    for(int i = 0; i < n; i++){
        if(!drop[i]){
            res[k++] = s[i];
        }
    }
    res[k] = '\0';

    free(stack);
    free(drop);
    return res;
}
char* minRemoveToMakeValid(char* s) {
    int len = strlen(s);
    int* stack = (int*)malloc(len * sizeof(int));
    int top = -1;

    for(int i = 0; i < len; i++){
        if(s[i] == '('){
            stack[++top] = i;
        }else if(s[i] == ')'){
            if(top != -1){
                top--;
            }else{
                s[i] = '*';
            }
        }
    }

    while(top != -1){
        s[stack[top--]] = '*';
    }

    free(stack);

    int write_ptr = 0;
    for(int read = 0; read < len; read++){
        if(s[read] != '*'){
            s[write_ptr++] = s[read];
        }
    }
    s[write_ptr] = '\0';
    return s;
}
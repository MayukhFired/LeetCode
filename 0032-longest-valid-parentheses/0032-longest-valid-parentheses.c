#define Max(a , b) ((a) > (b) ? (a) : (b))

int longestValidParentheses(char* s) {
    int len = strlen(s);
    if(len == 0){
        return 0;
    }

    int* stack = (int*)malloc((len + 1) * sizeof(int));
    int top = -1;
    int max_len = 0;
    stack[++top] = -1;

    for(int i = 0; i < len; i++){
        if(s[i] == '('){
            stack[++top] = i;
        }else{
            top--;
            if(top == -1){
                stack[++top] = i;
            }else{
                max_len = Max(max_len , i - stack[top]);
            }
        }
    }
    free(stack);
    return max_len;
}
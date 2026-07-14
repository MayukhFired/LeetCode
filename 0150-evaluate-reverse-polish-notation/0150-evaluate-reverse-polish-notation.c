int evalRPN(char** tokens, int tokensSize) {
    int* stack = (int*)malloc(tokensSize *sizeof(int));
    int top = -1;
    int output = 0;
    for(int i = 0; i < tokensSize; i++){
        char* token = tokens[i];
        if(strlen(token) == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' ||token[0] == '/')){

            int num2 = stack[top--];
            int num1 = stack[top--];

            if(token[0] == '+'){
                stack[++top] = num1 + num2;
            }else if(token[0] == '-'){
                stack[++top] = num1 - num2;
            }else if(token[0] == '*'){
                stack[++top] = num1 * num2;
            }else if(token[0] == '/'){
                stack[++top] = num1/num2;
            }
        }else{
            int val = atoi(token);
            stack[++top] = val;
        }
    }
    output = stack[0];
    free(stack);
    return output;
}
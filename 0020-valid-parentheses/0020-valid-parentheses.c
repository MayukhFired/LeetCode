bool isValid(char* s) {
    if(strlen(s) % 2){
        return false;
    }

    char* stack = (char*)malloc(strlen(s) *sizeof(char));
    int top = -1;
    for(int i = 0; i < strlen(s); i++){
        char current = s[i];
        if(current == '(' || current == '{' || current == '['){
            stack[++top] = current;
        }else{
            if(top == -1){
                free(stack);
                return false;
            }

            char topChar = stack[top];
            if((current == ')' && topChar == '(') ||
             (current == '}' && topChar == '{') || 
             (current == ']' && topChar == '[')){
                top--;
            }else{
                free(stack);
                return false;
            }
        }
    }

    bool isString = (top == -1);
    free(stack);
    return isString;
}


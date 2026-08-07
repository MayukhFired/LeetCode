char* removeStars(char* s) {
    int len = strlen(s);
    char* result = (char*)malloc((len + 1) * sizeof(char));
    int top = 0;
    for(int i = 0; i < len; i++){
        if(s[i] == '*'){
            top--;
        }else{
            result[top++] = s[i];
        }
    }
    result[top] = '\0';
    return result;
}
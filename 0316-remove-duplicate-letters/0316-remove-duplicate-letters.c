char* removeDuplicateLetters(char* s) {
    int len = strlen(s);
    int last_index[26] = {0};
    for(int i = 0; i < len; i++){
        last_index[s[i] - 'a'] = i;
    }

    char* stack = (char*)malloc(27* sizeof(char));
    int top = 0;
    bool visited[26] = {false};

    for(int i = 0; i < len; i++){
        int index = s[i] - 'a';

        if(visited[index]){
            continue;
        }

        while(top > 0 && stack[top - 1] > s[i] && last_index[stack[top - 1] - 'a'] > i){
            visited[stack[top - 1] - 'a'] = false;
            top--;
        }

        stack[top++] = s[i];
        visited[index] = true;
    }

    stack[top] = '\0';
    return stack;
}
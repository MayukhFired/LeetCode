void reverse(char* c , int left , int right){
    while(left < right){
        char temp = c[left];
        c[left] = c[right];
        c[right] = temp;

        left++;
        right--;
    }
}

char* reverseWords(char* s) {
    reverse(s , 0 , strlen(s) - 1);
    char* result = (char*)malloc((strlen(s) + 1) * sizeof(char));
    int n = strlen(s);
    int i = 0;
    int r = 0;
    while(i < n){
        while(i < n && s[i] == ' ') i++;
        if(i < n){
            if(r > 0){
                s[r++] = ' ';
            }
            int word_start = r;
            while(i < n && s[i] != ' '){
                s[r++] = s[i++];
            }
            reverse(s , word_start , r - 1);
        }
        i++;
    }
    s[r] = '\0';
    strcpy(result , s);
    return result;
}
bool repeatedSubstringPattern(char* s) {
    int n = strlen(s);
    if(n <= 1){
        return false;
    }

    int c_len = 2 * n;
    char* c = (char*)malloc((c_len + 1) * sizeof(char));

    strcpy(c , s);
    strcat(c , s);
    c[c_len - 1] = '\0';
    char* sliced = c + 1;

    bool res = (strstr(sliced , s) != NULL);
    free(c);
    return res;
}
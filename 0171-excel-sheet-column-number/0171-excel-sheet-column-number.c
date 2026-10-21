int titleToNumber(char* columnTitle) {
    long long ans = 0;
    for(int i = 0; columnTitle[i] != '\0'; i++){
        char ch = columnTitle[i];
        ans = ans * 26 + (ch - 'A' + 1);
    }
    return (int)ans;
}
int reverseDegree(char* s) {
    int count = 0;
    for(int i = 1; i <= strlen(s); i++){
        int curr_char = s[i - 1] - 'a';
        count += (26 - curr_char) * i;
    }
    return count;
}
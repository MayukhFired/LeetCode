char* digitSum(char* s, int k) {
    int len = strlen(s);
    char* curr = (char*)malloc((len + 1) * sizeof(char));
    strcpy(curr , s);

    while(len > k){
        char* next = (char*)malloc((len + 1) * sizeof(char));
        int m = 0;
        for(int i = 0; i < len; i += k){
            int sum = 0;
            for(int j = i; j < len && j < i + k; j++){
                sum += curr[j] - '0';
            }
            m += sprintf(next + m , "%d" , sum);
        }
        next[m] = '\0';
        free(curr);
        curr = next;
        len = m;
    }

    return curr;
}
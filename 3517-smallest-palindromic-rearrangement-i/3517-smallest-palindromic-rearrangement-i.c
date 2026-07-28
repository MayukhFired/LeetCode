int compare(const void* a , const void* b){
    char num1 = *(const char*)a;
    char num2 = *(const char*)b;
    if(num1 < num2) return -1;
    if(num1 > num2) return 1;
    return 0;
}

char* smallestPalindrome(char* s) {
    int n = strlen(s);
    int mid = n / 2;
    qsort(s , mid , sizeof(char) , compare);
    for(int i = 0; i < mid; i++){
        s[n - 1 - i] = s[i];
    }
    return s;
}
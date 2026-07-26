int gcd(int a , int b){
    while(b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

char* gcdOfStrings(char* str1, char* str2) {
    int len_1 = strlen(str1);
    int len_2 = strlen(str2);

    char combo1[len_1 + len_2 + 1];
    char combo2[len_1 + len_2 + 1];

    sprintf(combo1 , "%s%s" , str1 , str2);
    sprintf(combo2 , "%s%s" , str2 , str1);

    if(strcmp(combo1 , combo2) != 0){
        return "";
    }

    int gcd_len = gcd(len_1 , len_2);
    str1[gcd_len] = '\0';
    return str1;
}
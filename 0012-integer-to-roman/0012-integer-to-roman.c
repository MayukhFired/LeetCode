char* intToRoman(int num) {
    int values[] = {1000 , 900 , 500 , 400 , 100 , 90 , 50 , 40 ,10 , 9 , 5 , 4 , 1};
    char* symbols[] = { "M" , "CM" , "D", "CD" , "C" , "XC" , "L" , "XL" , "X" , "IX" ,"V" , "IV" , "I"};

    char* result = (char*)malloc(16 * sizeof(char));
    if(result == NULL) return NULL;
    int len = 0;
    for(int i = 0 ; i < 13; i++){
        while(num >= values[i]){
            char *s = symbols[i];
            while(*s){
                result[len++] = *s++;
            }
            num -= values[i];
        }
    }
    result[len] = '\0';
    return result;
    free(result);
}
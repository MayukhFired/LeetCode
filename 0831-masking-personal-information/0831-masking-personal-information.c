char* maskPII(char* s) {
    int len = strlen(s);
    char* res = (char*)malloc((len + 20) * sizeof(char));
    char* at_ptr = strchr(s , '@');

    if(at_ptr != NULL){
        int at_index = at_ptr - s;
        res[0] = tolower(s[0]);
        strcpy(res + 1 , "*****");
        res[6] = tolower(s[at_index - 1]);

        int j = 7;
        for(int i = at_index ; s[i] != '\0'; i++){
            res[j++] = tolower(s[i]);
        }
        res[j] = '\0';
    }else{
        char digits[20];
        int digit_count = 0;

        for(int i = 0; s[i] != '\0'; i++){
            if(isdigit(s[i])){
                digits[digit_count++] = s[i];
            }
        }

        int country_len = digit_count - 10;
        int res_idx = 0;

        if(country_len > 0){
            res[res_idx++] = '+';
            for(int i =0; i < country_len; i++){
                res[res_idx++] = '*';
            }
            res[res_idx++] = '-';
        }

        strcpy(res + res_idx , "***-***-");
        res_idx += 8;

        for(int i = digit_count - 4; i < digit_count; i++){
            res[res_idx++] = digits[i];
        }
        res[res_idx] = '\0';
    }
    return res;
}
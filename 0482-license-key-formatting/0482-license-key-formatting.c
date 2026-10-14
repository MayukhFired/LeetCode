char* licenseKeyFormatting(char* s, int k) {
    int len = strlen(s);
    char* buffer = (char*)malloc((2 * len + 1) * sizeof(char));
    if(buffer == NULL){
        return "";
    }

    int p = len * 2;
    buffer[p] = '\0';
    int count = 0;

    for(int i = len - 1; i >= 0; i--){
        if(s[i] != '-'){
            if(count > 0 && count % k == 0){
                buffer[--p] = '-';
            }
            buffer[--p] = toupper((unsigned char) s[i]);
            count++;
        }
    }
    return &buffer[p];
}
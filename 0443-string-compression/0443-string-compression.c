int compress(char* chars, int charsSize) {
    int write = 0;
    int i = 0;
    while(i < charsSize){
        int count = 0;
        int current_char = chars[i];
        while(i < charsSize && current_char == chars[i]){
            count++;
            i++;
        }
        chars[write++] = current_char;
        if(count > 1){
            char digits[5];
            int len = sprintf(digits , "%d" , count);
            for(int j = 0; j < len; j++){
                chars[write++] = digits[j];
            }
        }
    }
    return write;
}
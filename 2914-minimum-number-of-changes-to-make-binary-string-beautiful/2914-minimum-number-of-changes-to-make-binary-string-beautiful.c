int minChanges(char* s) {
    char curr_char = s[0];
    int count = 0;
    int min_change = 0;

    for(int i = 0; i < strlen(s); i++){
        if(s[i] == curr_char){
            count++;
            continue;
        }

        if(count % 2 == 0){
            count = 1;
        }else{
            count = 0;
            min_change++;
        }
        curr_char = s[i];
    }
    return min_change;
}
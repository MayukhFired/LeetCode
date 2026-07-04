char* countAndSay(int n) {
    char* current = (char*)malloc(2* sizeof(char));
    strcpy(current , "1");

    if(n == 1){
        return current;
    }

    for(int i = 2; i <= n; i++){
        char* next_str = (char*)malloc(50000* sizeof(char));
        int index = 0;
        int len = strlen(current);
        int j = 0;

        while(j < len){
            int count = 1;
            while(j + 1 < len && current[j] == current[j + 1]){
                count++;
                j++;
            }

            index += sprintf(&next_str[index] , "%d%c" , count , current[j]);
            j++;
        }
        next_str[index] = '\0';
        free(current);
        current = next_str;
    }

    return current;
    free(current);
}
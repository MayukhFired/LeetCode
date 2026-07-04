char* countAndSay(int n) {
    char* next = malloc(50000);
    char* current = malloc(50000);

    strcpy(current , "1");
    if(n == 1){
        free(next);
        return current;
    }

    for(int i = 2; i <= n; i++){
        int k = 0;
        int j = 0;
        int len = strlen(current);

        while(j < len){
            int count = 1;
        while(j < len && current[j] == current[j + 1]){
            count++;
            j++;
        }
        next[k++] = count + '0';
        next[k++] = current[j];
        j++;
        }
          next[k] = '\0';
        char* temp = current;
        current = next;
        next = temp;
    }

    free(next);
    return current;
}
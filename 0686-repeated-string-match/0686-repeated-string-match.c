int repeatedStringMatch(char* a, char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);

    int count = (len_b + len_a - 1) / len_a;
    int max_len = (count + 1) * len_a + 1;
    char* repeated = (char*)malloc(max_len * sizeof(char));
    if(repeated == NULL){
        return -1;
    }

    repeated[0] = '\0';
    for(int i = 0; i < count; i++){
        strcat(repeated , a);
    }

    if(strstr(repeated , b) != NULL){
        free(repeated);
        return count;
    }

    strcat(repeated , a);
    count++;

    if(strstr(repeated , b) != NULL){
        free(repeated);
        return count;
    }

    free(repeated);
    return -1;
}
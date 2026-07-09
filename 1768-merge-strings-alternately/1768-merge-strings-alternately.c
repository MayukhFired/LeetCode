

char * mergeAlternately(char * word1, char * word2){
    int len_1 = strlen(word1);
    int len_2 = strlen(word2);

    char* result = (char*)malloc((len_1 + len_2 + 1) *sizeof(char));

    int i = 0; 
    int j = 0; 
    int k = 0;

    while(i < len_1 && j < len_2){
        result[k++] = word1[i++];
        result[k++] = word2[j++];
    }

    while(i < len_1){
        result[k++] = word1[i++];
    }

    while(j < len_2){
        result[k++] = word2[j++];
    }

    result[k] = '\0';

    return result;
}
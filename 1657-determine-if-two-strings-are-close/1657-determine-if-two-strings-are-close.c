int compare(const void* a , const void* b){
    return(*(int*)b - *(int*)a);
}

bool closeStrings(char* word1, char* word2) {
    if(strlen(word1) != strlen(word2)){
        return false;
    }

    int freq1[26] = {0};
    int freq2[26] = {0};
    for(int i = 0; i < strlen(word1); i++){
        freq1[word1[i] - 'a']++;
        freq2[word2[i] - 'a']++;
    }

    for(int i = 0; i < 26; i++){
        if((freq1[i] == 0 && freq2[i] > 0) || (freq2[i] == 0 && freq1[i] > 0)){
            return false;
        }
    }

    qsort(freq1 , 26 , sizeof(int) , compare);
    qsort(freq2 , 26 , sizeof(int) , compare);
    for(int i = 0; i < 26; i++){
        if(freq1[i] != freq2[i]){
            return false;
        }
    }
    return true;
}
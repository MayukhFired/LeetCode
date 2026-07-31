int compare(const void* a , const void* b){
    return(*(int*)b - *(int*)a);
}

int minimumPushes(char* word) {
    int counts[26] = {0};
    int totalPushes = 0;
    for(int i = 0; word[i] != '\0'; i++){
        counts[word[i] - 'a']++;
    }

    qsort(counts , 26 , sizeof(int) , compare);
    for(int i = 0; i < 26; i++){
        if(counts[i] == 0) break;

        int press = (i / 8) + 1;
        totalPushes += counts[i] * press;
    }
    return totalPushes;
}
bool detectCapitalUse(char* word) {
    int count = 0;
    if(strlen(word) == 1){
        return true;
    }

    for(int i = 0; i < strlen(word); i++){
        if(isupper(word[i])){
            count++;
        }
    }
    if(count == 1 && isupper(word[0])){
        return true;
    }
    if(count == 0 || count == strlen(word)){
        return true;
    }
    return false;
}
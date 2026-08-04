int isVowel(char c){
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int maxVowels(char* s, int k) {
    int count = 0;
    for(int i = 0; i < k ; i++){
        if(isVowel(s[i])){
            count++;
        }
    }
    int max_count = count;
    for(int i = k ; i < strlen(s); i++){
        count = count - isVowel(s[i - k]) + isVowel(s[i]);
        if(max_count < count){
            max_count = count;
        }
    }
    return max_count;
}
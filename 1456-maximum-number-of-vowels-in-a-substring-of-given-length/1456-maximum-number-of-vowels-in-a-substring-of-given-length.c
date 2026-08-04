int isVowel(char c){
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int maxVowels(char* s, int k) {
    int curr_vowels = 0;
    for(int i = 0; i < k; i++){
        if(isVowel(s[i])){
            curr_vowels++;
        }
    }
    int max_vowels = curr_vowels;
    if(k == max_vowels) return k;

    for(int i = k; i < strlen(s); i++){
        curr_vowels += isVowel(s[i]) - isVowel(s[i - k]);
        if(max_vowels < curr_vowels){
            max_vowels = curr_vowels;
        }
        if(max_vowels == k) return k;
    }
    return max_vowels;
}
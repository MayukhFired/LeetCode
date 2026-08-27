char* getMinString(const int* cnt){
    int totalLen = 0;
    for(int i = 0; i < 26; i++){
        totalLen += cnt[i];
    }

    char* res = (char*)malloc((totalLen + 1) * sizeof(char));
    int pos = 0;
    for(int i = 0; i < 26; i++){
        if(cnt[i] > 0){
            memset(res + pos , 'a' + i , cnt[i]);
            pos += cnt[i];
        }
    }
    res[pos] = '\0';
    return res;
}

char* getMaxString(const int* cnt){
    int totalLen = 0;
    for(int i = 0; i < 26; i++){
        totalLen += cnt[i];
    }

    char* res = (char*)malloc((totalLen + 1) * sizeof(char));
    int pos = 0;
    for(int i = 25; i >= 0; i--){
        if(cnt[i] > 0){
            memset(res + pos , 'a' + i , cnt[i]);
            pos += cnt[i];
        }
    }
    res[pos] = '\0';
    return res;
}

bool Greater(const int* cnt , const char* target , int start){
    char* maxStr = getMaxString(cnt);
    bool result = strcmp(maxStr , target + start) > 0;
    free(maxStr);
    return result;
}

char* lexGreaterPermutation(char* s, char* target) {
    int cnt[26] = {0};
    for(int i = 0; s[i] != '\0'; i++){
        cnt[s[i] - 'a']++;
    }

    int n = strlen(target);
    char* res = (char*)malloc((n + 27) * sizeof(char));
    int pos = 0;
    for(int i = 0; i < n; i++){
        int targetChar = target[i] - 'a';
        if(cnt[targetChar] > 0){
            cnt[targetChar]--;
            if(Greater(cnt , target , i + 1)){
                res[pos++] = target[i];
                continue;
            }
            cnt[targetChar]++;
        }
        for(int j = targetChar + 1; j < 26; j++){
            if(cnt[j] > 0){
                cnt[j]--;
                res[pos++] = 'a' + j;

                char* str = getMinString(cnt);
                strcpy(res + pos , str);
                free(str);
                return res;
            }
        }
        break;
    }
    free(res);
    return strdup("");
}
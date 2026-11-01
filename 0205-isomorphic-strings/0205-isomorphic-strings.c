bool isIsomorphic(char* s, char* t) {
    int* IndexT = (int*)malloc(200 * sizeof(int));
    int* IndexS = (int*)malloc(200 * sizeof(int));

    if(strlen(s) != strlen(t)){
        return false;
    }

    for(int i = 0; i < strlen(s); i++){
        if(IndexS[s[i]] != IndexT[t[i]]){
            return false;
        }
        IndexS[s[i]] = i + 1;
        IndexT[t[i]] = i + 1;
    }

    return true;
}
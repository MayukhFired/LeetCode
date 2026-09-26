typedef struct{
    char* key;
    char* val;
    UT_hash_handle hh;
} HashItem;

HashItem* HashFindItem(HashItem** obj , const char* key){
    HashItem* pEntry = NULL;
    HASH_FIND_STR(*obj , key , pEntry);
    return pEntry;
}

bool HashAddItem(HashItem** obj , char* key , char* val){
    if(HashFindItem(obj , key)){
        return false;
    }

    HashItem* pEntry = (HashItem*)malloc(sizeof(HashItem));
    pEntry->key = key;
    pEntry->val = val;
    HASH_ADD_STR(*obj , key , pEntry);
    return true;
}

void HashFree(HashItem** obj){
    HashItem* curr = NULL;
    HashItem* temp = NULL;

    HASH_ITER(hh , *obj , curr , temp){
        HASH_DEL(*obj , curr);
        free(curr);
    }
}

char* evaluate(char* s, char*** knowledge, int knowledgeSize, int* knowledgeColSize) {
    HashItem* dict = NULL;
    for(int i = 0; i < knowledgeSize; i++){
        HashAddItem(&dict , knowledge[i][0] , knowledge[i][1]);
    }   

    bool addKey = false;
    int len = strlen(s);
    int maxResLen = (len / 4) * 10 + len + 1;
    char key[16];
    char *res = (char*)malloc(sizeof(char) * maxResLen);
    int keySize = 0;
    int resSize = 0;
    memset(key , 0 , sizeof(key));

    for(int i = 0; s[i] != '\0'; i++){
        char c = s[i];
        if(c == '('){
            addKey = true;
        }else if(c == ')'){
            HashItem* pEntry = HashFindItem(&dict , key);
            if(pEntry){
                resSize += sprintf(res + resSize , "%s" , pEntry->val);
            }else{
                res[resSize++] = '?';
            }
            addKey = false;
            keySize = 0;
        }else if(addKey){
            if(keySize < sizeof(key) - 1){
                key[keySize++] = c;
                key[keySize] = '\0';
            }
        }else{
            res[resSize++] = c;
        }
    }

    HashFree(&dict);
    res[resSize] = '\0';
    return res;
}
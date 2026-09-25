/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct{
    char* key;
    UT_hash_handle hh;
} HashItem;

HashItem* hashFindItem(HashItem** obj , char* key){
    HashItem* pEntry = NULL;
    HASH_FIND_STR(*obj , key , pEntry);
    return pEntry;
}

bool hashADDItem(HashItem** obj , char* key){
    if(hashFindItem(obj , key)){
        return false;
    }
    HashItem* pEntry = (HashItem*)malloc(sizeof(HashItem));
    pEntry->key = strdup(key);
    HASH_ADD_STR(*obj , key , pEntry);
    return true;
}

void hashFree(HashItem** obj){
    HashItem*  curr = NULL;
    HashItem* temp = NULL;
    HASH_ITER(hh , *obj , curr , temp){
        HASH_DEL(*obj , curr);
        free(curr->key);
        free(curr);
    }
}

typedef struct{
    char* expression;
    int idx;
    int len;
} Parser;

bool isLetter(char c){
    return c >= 'a' && c <= 'z';
}

void setUnion(HashItem** dest , HashItem** src){
    HashItem* curr = NULL;
    HashItem* temp = NULL;
    HASH_ITER(hh , *src , curr , temp){
        hashADDItem(dest , curr->key);
    }
}

int cmpstr(const void* a , const void* b){
    return strcmp(*(const char**)a , *(const char**)b);
}

HashItem* expr_impl(Parser* parser);
HashItem* term_impl(Parser* parser);
HashItem* item_impl(Parser* parser);

HashItem* item_impl(Parser* parser){
    HashItem* ret = NULL;
    if(parser->expression[parser->idx] == '{'){
        parser->idx++;
        HashItem* subResult = expr_impl(parser);
        setUnion(&ret , &subResult);
        hashFree(&subResult);
    }else{
        char str[2] = {parser->expression[parser->idx] , '\0'};
        hashADDItem(&ret , str);
    }
    parser->idx++;
    return ret;
}

HashItem* term_impl(Parser* parser){
    HashItem* ret = NULL;
    hashADDItem(&ret , "");

    while(parser->idx < parser->len && (parser->expression[parser->idx] == '{' || isLetter(parser->expression[parser->idx]))){
        HashItem* sub = item_impl(parser);
        HashItem* temp = NULL;

        HashItem* currLeft = NULL;
        HashItem* tempLeft = NULL;
        HASH_ITER(hh , ret , currLeft , tempLeft){
            HashItem* currRight = NULL;
            HashItem* tempRight = NULL;
            HASH_ITER(hh , sub , currRight , tempRight){
                char* combined = (char*)malloc(strlen(currLeft->key) + strlen(currRight->key) + 1);
                strcpy(combined , currLeft->key);
                strcat(combined , currRight->key);
                hashADDItem(&temp , combined);
                free(combined);
            }
        }

        hashFree(&ret);
        hashFree(&sub);
        ret = temp;
    }
    return ret;
}

HashItem* expr_impl(Parser* parser){
    HashItem* ret = NULL;
    while(true){
        HashItem* termResult = term_impl(parser);
        setUnion(&ret , &termResult);
        hashFree(&termResult);

        if(parser->idx < parser->len && parser->expression[parser->idx] == ','){
            parser->idx++;
            continue;
        }else{
            break;
        }
    }
    return ret;
}

char** braceExpansionII(char* expression, int* returnSize) {
    Parser parser;
    parser.expression = expression;
    parser.idx =0;
    parser.len = strlen(expression);

    HashItem* resultSet = expr_impl(&parser);

    int count = HASH_COUNT(resultSet);
    *returnSize = count;
    char** result = (char**)malloc(count * sizeof(char*));
    HashItem* curr = NULL;
    HashItem* temp = NULL;
    int i = 0;
    HASH_ITER(hh , resultSet , curr , temp){
        result[i] = strdup(curr->key);
        i++;
    }

    qsort(result , count , sizeof(char*) , cmpstr);
    hashFree(&resultSet);

    return result;
}
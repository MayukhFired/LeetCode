/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

typedef struct {
    char* sortedKey;
    char* original;
} AnangramPair;

char* getSorted(const char* s) {
    int count[26] = {0};
    int len = strlen(s);

    for(int i = 0; i < len; i++){
        count[s[i] - 'a']++;
    }

    char* key = (char*)malloc((len + 1) * sizeof(char));
    int pos = 0;
    for(int c = 0; c < 26; c++) {
        while(count[c] > 0) {
            key[pos++] = (char)(c + 'a');
            count[c]--;
        }
    }
    key[pos] = '\0';
    return key;
}

int compare(const void* a , const void* b) {
    const AnangramPair* A = (const AnangramPair*)a;
    const AnangramPair* B = (const AnangramPair*)b;
    return strcmp(A->sortedKey , B->sortedKey);
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if(!strs || strsSize == 0) {
        *returnColumnSizes = NULL;
        return NULL;
    }

    AnangramPair* pairs = (AnangramPair*)malloc(strsSize * sizeof(AnangramPair));
    for(int i = 0; i < strsSize; i++) {
        pairs[i].sortedKey = getSorted(strs[i]);
        pairs[i].original = strs[i];
    }

    qsort(pairs , strsSize , sizeof(AnangramPair) , compare);

    char*** res = (char***)malloc(strsSize * sizeof(char**));
    *returnColumnSizes = (int*)malloc(strsSize * sizeof(int));
    int start = 0;

    for(int i = 1; i <= strsSize; i++) {
        if(i == strsSize || strcmp(pairs[i].sortedKey , pairs[start].sortedKey) != 0) {
            int size = i - start;
            int idx = *returnSize;
            res[idx] = (char**)malloc(size * sizeof(char*));
            (*returnColumnSizes)[idx] = size;

            for(int j = 0; j < size; j++) {
                res[idx][j] = pairs[start + j].original;
            }
            (*returnSize)++;
            start = i;
        }
    }

    for(int i = 0; i < strsSize; i++) {
        free(pairs[i].sortedKey);
    }
    free(pairs);

    return res;
}
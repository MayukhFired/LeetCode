/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* validSequence(char* word1, char* word2, int* returnSize) {
    int n = strlen(word1);
    int m = strlen(word2);

    int* suffix_match = (int*)malloc((m + 1) * sizeof(int));
    for(int i = 0; i <= m ; i++) suffix_match[i] = -1;
    suffix_match[m] = n;

    int i = n - 1;
    for(int j = m - 1; j >= 0; j--){
        while(i >= 0 && word1[i] != word2[j]){
            i--;
        }
        if(i >= 0){
            suffix_match[j] = i;
            i--;
        }else{
            break;
        }
    }
    
    int* result = (int*)malloc(m * sizeof(int));
    int res = 0;
    i = 0;
    bool changed = false;

    for(int j = 0; j < m; j++){
        if(i < n && word1[i] == word2[j]){
            result[res++] = i;
            i++;
        }else{
            if(!changed && i < n && suffix_match[j + 1] > i){
                result[res++] = i;
                i++;
                changed = true;
            }else{
                while(i < n && word1[i] != word2[j]){
                    i++;
                }
                if(i < n){
                    result[res++] = i;
                    i++;
                }else{
                    free(suffix_match);
                    free(result);
                    *returnSize = 0;
                    return NULL;
                }
            }
        }
    }
    free(suffix_match);
    if(res == m){
        *returnSize = m;
        return result;
    }else{
        free(result);
        *returnSize = 0;
        return NULL;
    }
}
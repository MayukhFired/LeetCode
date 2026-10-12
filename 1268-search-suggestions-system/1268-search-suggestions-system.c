/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int compare(const void* a , const void* b){
    return strcmp(*(const char**)a , *(const char**)b);
}

int lowerBound(char** products , int start , int end , const char* target){
    int low = start;
    int high = end;

    while(low < high){
        int mid = low + (high - low) / 2;
        if(strcmp(products[mid] , target) >= 0){
            high = mid;
        }else{
            low = mid + 1;
        }
    }
    return low;
}

char*** suggestedProducts(char** products, int productsSize, char* searchWord, int* returnSize, int** returnColumnSizes) {
    qsort(products , productsSize , sizeof(char*) , compare);
    int len = strlen(searchWord);
    *returnSize = len;

    char*** res = (char***)malloc(len * sizeof(char**));
    *returnColumnSizes = (int*)malloc(len * sizeof(int));
    char curr[2001] = "";
    int start_idx = 0;

    for(int i = 0; i < len; i++){
        curr[i] = searchWord[i];
        curr[i + 1] = '\0';
        int idx = lowerBound(products , start_idx , productsSize , curr);
        res[i] = (char**)malloc(3 * sizeof(char*));
        int count = 0;

        for(int j = 0; j < 3 && (idx + j) < productsSize; j++){
            char* s = products[idx + j];
            if(strncmp(s , curr , strlen(curr)) != 0){
                break;
            }
            res[i][count++] = strdup(s);
        }
        (*returnColumnSizes)[i] = count;
        start_idx = idx;
    }
    return res;
}
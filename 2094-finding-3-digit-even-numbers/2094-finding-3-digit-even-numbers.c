/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare(const void* a , const void* b){
    return (*(int*)a - *(int*)b);
}

int* findEvenNumbers(int* digits, int digitsSize, int* returnSize) {
    int* result = (int*)malloc(1000 * sizeof(int));
    bool vis[1000] = {false};
    int idx = 0;

    for(int i = 0; i < digitsSize; i++){
        if(digits[i] == 0){
            continue;
        }
        for(int j = 0; j < digitsSize; j++){
            for(int k = 0; k < digitsSize; k++){
                if(i == j || j == k || k == i){
                    continue;
                }
                if(digits[k] % 2 != 0){
                    continue;
                }
                int x = digits[i] * 100 + digits[j] * 10 + digits[k];
                if(!vis[x]){
                    vis[x] = true;
                    result[idx] = x;
                    idx++;
                }
            }
        }
    }

    qsort(result , idx , sizeof(int), compare);
    *returnSize = idx;
    return result;
}
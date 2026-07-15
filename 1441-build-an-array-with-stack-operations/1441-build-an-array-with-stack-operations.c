/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** buildArray(int* target, int targetSize, int n, int* returnSize) {
    char** result = (char**)malloc(2 * n * sizeof(char*));
    int s = 1;
    int t = 0;
    int r = 0;

    while(t < targetSize && s <= n){
        if(target[t] == s){
            result[r] = "Push";
            r++;
            t++;
        }else{
            result[r] = "Push";
            r++;
            result[r] = "Pop";
            r++;
        }

            s++;
    }

    *returnSize = r;
    return result;
}
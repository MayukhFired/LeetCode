/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxDepthAfterSplit(char* seq, int* returnSize) {
    int len = strlen(seq);
    int* ans = (int*)malloc(len * sizeof(int));
    int depth = 0;
    *returnSize = len;

    for(int i = 0; i < len; i++){
        if(seq[i] == '('){
            depth++;
            ans[i] = depth % 2;
        }else if(seq[i] == ')'){
            ans[i] = depth % 2;
            depth--;
        }
    }
    return ans;
}
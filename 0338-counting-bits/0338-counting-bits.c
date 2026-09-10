/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize) {
    *returnSize = n + 1;
    int* ans = (int*)calloc((n + 1) , sizeof(int));

    for(int i = 0; i <= n; i++){
        ans[i] = ans[i >> 1] + (i & 1);
    }
    return ans;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    *returnSize = pricesSize;
    int* res = (int*)malloc(pricesSize * sizeof(int));

    for(int i = 0; i < pricesSize; i++){
        res[i] = prices[i];
        for(int j = i + 1; j < pricesSize; j++){
            if(prices[j] <= prices[i]){
                res[i] -= prices[j];
                break;
            }
        }
    }
    return res;
}
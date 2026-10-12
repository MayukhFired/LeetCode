#define Max(a , b) ((a) > (b) ? (a) : (b))
int maxProfit(int* prices, int pricesSize, int fee) {
    int buy = INT_MIN;
    int sell = 0;
    for(int i = 0; i < pricesSize; i++){
        buy = Max(buy , sell - prices[i]);
        sell = Max(sell , buy + prices[i] - fee);
    }

    return sell;
}
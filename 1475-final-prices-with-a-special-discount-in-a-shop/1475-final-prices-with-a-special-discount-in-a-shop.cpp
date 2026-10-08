class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> res(prices.size());
        for(int i = 0; i < prices.size(); i++){
            int newPrice = prices[i];
            for(int j = i + 1; j < prices.size(); j++){
                if(prices[j] <= prices[i]){
                    newPrice -= prices[j];
                    break;
                }
            }
            res[i] = newPrice;
        }
        return res;
    }
};
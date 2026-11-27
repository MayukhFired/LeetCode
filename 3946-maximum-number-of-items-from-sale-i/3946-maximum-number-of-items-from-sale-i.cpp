class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        vector<int> f(budget + 1 , 0);
        int mn = INT_MAX;
        for(const auto& item : items) {
            int factor = item[0];
            int price = item[1];
            mn = min(mn , price);
            int count = 0;

            for(const auto& other : items) {
                if(other[0] % factor == 0) {
                    count++;
                }
            }

            for(int j = budget; j >= price; j--) {
                f[j] = max(f[j] , f[j - price] + count);
            }
        }

        int ans = 0;
        for(int j = 0; j <= budget; j++) {
            ans = max(ans , f[j] + (budget - j) / mn);
        }
        return ans;
    }
};
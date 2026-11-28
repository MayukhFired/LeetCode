class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
    // 1-----------------------------------------------------------------------------1
        // sort(items.begin() , items.end() , [](const auto& a , const auto& b){
        //     return a[1] < b[1];
        // });

        // int mx = 0;
        // for(const auto& item : items) {
        //     mx = max(mx , item[0]);
        // }

        // vector<int> freq(mx + 1 , 0);
        // for(const auto& item : items) {
        //     freq[item[0]]++;
        // }

        // for(int i = 1; i <= mx; i++) {
        //     if(freq[i] > 0) {
        //         for(int j = i * 2; j <= mx; j += i) {
        //             freq[i] += freq[j];
        //         }
        //     }
        // }

        // int mn = items[0][1];
        // int ans = 0;
        // for(const auto& item : items) {
        //     int factor = item[0];
        //     int price = item[1];

        //     if(price - mn > mn) {
        //         break;
        //     }

        //     int count = freq[factor] - 1;
        //     int take = min(count , budget / price);
        //     ans += take * 2;
        //     budget -= take * price;
        // }

        // ans += budget / mn;
        // return ans;
    // 1------------------------------------------------------------------------------1
        int n = items.size();
        int maxFact = 0;
        int minPrice = INT_MAX;
        for(auto& item : items) {
            maxFact = max(maxFact , item[0]);
            minPrice = min(minPrice , item[1]);
        }

        vector<int> freq(maxFact + 1 , 0);
        for(auto& item : items) {
            freq[item[0]]++;
        }

        map<int , long long> mp;
        for(auto& item : items) {
            int f = item[0];
            int price = item[1];
            if(price > 2 * minPrice) continue;
            long long count = 0;
            for(int i = f; i <= maxFact; i += f) {
                count += freq[i];
            }
            count--;
            if(count > 0) {
                mp[price] += count;
            }
        }

        long long bonus = 0;
        long long curr = budget;
        for(auto& [price , count] : mp) {
            if(curr < price) break;
            long long buy = min(count , 1LL * curr / price);
            curr -= price * buy;
            bonus += buy;
        }

        long long ans = curr / minPrice;
        ans += 2 * bonus;
        return ans;
    }
};
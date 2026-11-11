class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
    // 1-------------------------------------------------------------------------------------1
        // long long individual_cost = (1LL * cost1 * need1) + (1LL * cost2 * need2);
        // long long costBoth_value = 1LL * costBoth * max(need1 , need2);

        // long long min_need = min(need1 , need2);
        // long long rem1 = need1 - min_need;
        // long long rem2 = need2 - min_need;
        // long long cost_mixed = (costBoth * min_need) + (cost1 * rem1) + (cost2 * rem2);

        // return min({individual_cost , costBoth_value , cost_mixed});
    // 1------------------------------------------------------------------------------------1
        long long totalCost = 0;

        if(cost1 + cost2 <= costBoth){
            totalCost = (1LL * need1 * cost1) + (1LL * need2 * cost2);
        }else{
            int cnt = min(need1 , need2);
            totalCost = 1LL * costBoth * cnt;
            need1 -= cnt;
            need2 -= cnt;

            if(need1 > 0){
                totalCost += 1LL * need1 * min(costBoth , cost1);
            }else if(need2 > 0){
                totalCost += 1LL * need2 * min(costBoth , cost2);
            }
        }

        return totalCost;
    }
};
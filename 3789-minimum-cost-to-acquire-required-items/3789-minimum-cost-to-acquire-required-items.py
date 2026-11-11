class Solution:
    def minimumCost(self, cost1: int, cost2: int, costBoth: int, need1: int, need2: int) -> int:
    # 1-----------------------------------------------------------------------1
        # individual_cost = (cost1 * need1) + (cost2 * need2)
        # costBoth_value = costBoth * max(need1 , need2)

        # min_need = min(need1 , need2)
        # rem1 = need1 - min_need
        # rem2 = need2 - min_need
        # cost_mixed = (costBoth * min_need) + (rem1 * cost1) + (rem2 * cost2)

        # return min(individual_cost , costBoth_value , cost_mixed)
    # 1----------------------------------------------------------------------1

        totalCost = 0
        if cost1 + cost2 <= costBoth:
            totalCost = (cost1 * need1) + (cost2 * need2)
        else:
            min_need = min(need1 , need2)
            totalCost = min_need * costBoth
            need1 -= min_need
            need2 -= min_need

            if need1 > 0:
                totalCost += need1 * min(cost1 , costBoth)
            elif need2 > 0:
                totalCost += need2 * min(cost2 , costBoth)

        return totalCost
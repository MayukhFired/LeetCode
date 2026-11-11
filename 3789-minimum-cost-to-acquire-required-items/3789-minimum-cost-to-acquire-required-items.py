class Solution:
    def minimumCost(self, cost1: int, cost2: int, costBoth: int, need1: int, need2: int) -> int:
        individual_cost = (cost1 * need1) + (cost2 * need2)
        costBoth_value = costBoth * max(need1 , need2)

        min_need = min(need1 , need2)
        rem1 = need1 - min_need
        rem2 = need2 - min_need
        cost_mixed = (costBoth * min_need) + (rem1 * cost1) + (rem2 * cost2)

        return min(individual_cost , costBoth_value , cost_mixed)
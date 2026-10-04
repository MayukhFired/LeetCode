class Solution:
    def minCostClimbingStairs(self, cost: list[int]) -> int:
        first , second = 0 , 0 

        for c in cost:
            first , second = second , c + min(first , second)
        return min(first , second)
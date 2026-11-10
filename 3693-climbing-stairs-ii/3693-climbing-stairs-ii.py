class Solution:
    def climbStairs(self, n: int, costs: List[int]) -> int:
    #1--------------------------------------------------------------------------1
        # a = b = c = 0
        # for i in range(n):
        #     a , b , c = b , c , min(a + 9 , b + 4 , c + 1) + costs[i]
        # return c
    # 1-------------------------------------------------------------------------1
        dp = [float('inf')] * (n + 1)
        dp[0] = 0
        for i in range(1 , n + 1):
            dp[i] = min(dp[i] , dp[i - 1] + costs[i - 1] + 1)
            if i >= 2:
                dp[i] = min(dp[i] , dp[i - 2] + costs[i - 1] + 4)
            if i >= 3:
                dp[i] = min(dp[i] , dp[i - 3] + costs[i - 1] + 9)

        return dp[n]
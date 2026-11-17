class Solution:
    def numTrees(self, n: int) -> int:
    # 1-----------------------------------------------------------------------1
        # uniqueTrees = [1] * (n + 1)

        # for nodes in range(2 , n + 1):
        #     total = 0
        #     for root in range(1 , nodes + 1):
        #         total += uniqueTrees[root - 1] * uniqueTrees[nodes - root]
        #     uniqueTrees[nodes] = total
        # return uniqueTrees[n]
    # 1-----------------------------------------------------------------------1
        dp = [1] * (n + 1)
        for i in range(2 , n + 1):
            total = 0
            for j in range(1 , i + 1):
                total += dp[j - 1] * dp[i - j]
            dp[i] = total
        return dp[n]
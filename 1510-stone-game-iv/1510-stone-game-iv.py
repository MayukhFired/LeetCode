
class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        dp = {}
        def solve(remain: int) -> bool:
            if remain <= 0:
                return 0
            if remain in dp:
                return dp[remain]
            i = 1
            while i * i <= remain:
                if not solve(remain - i * i):
                    dp[remain] = True
                    return True
                i += 1
            dp[remain] = False
            return False
        return solve(n)
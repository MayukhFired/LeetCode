class Solution:
    def isMatch(self, s: str, p: str) -> bool:
    # 1------------------------------------------------------1
        # n = len(s)
        # m = len(p)
        # dp = [[-1] * m for _ in range(n)]

        # def solve(i: int , j: int) -> bool:
        #     if i < 0 and j < 0:
        #         return True
        #     if j < 0 and i >= 0:
        #         return False
        #     if i < 0 and j >= 0:
        #         for k in range(j + 1):
        #             if p[k] != '*':
        #                 return False
        #         return True
            
        #     if dp[i][j] != -1:
        #         return bool(dp[i][j])

        #     if p[j] == s[i] or p[j] == '?':
        #         ans = solve(i - 1 , j - 1)
        #     elif p[j] == '*':
        #         ans = solve(i - 1 , j) or solve(i , j - 1)
        #     else:
        #         ans = False
            
        #     dp[i][j] = 1 if ans else 0
        #     return ans
        
        # return solve(n - 1, m - 1)
    # 1----------------------------------------------------------------------1
        n = len(s)
        m = len(p)
        dp = [[False] * (m + 1) for _ in range(n + 1)]
        dp[0][0] = True

        for j in range(1 , m + 1):
            if p[j - 1] == '*':
                dp[0][j] = dp[0][j - 1]
            else:
                dp[0][j] = False

        for i in range(1 , n + 1):
            for j in range(1 , m + 1):
                if p[j -1] == s[i - 1] or p[j - 1] == '?':
                    dp[i][j] = dp[i - 1][j - 1]
                elif p[j - 1] == '*':
                    dp[i][j] = dp[i - 1][j] or dp[i][j - 1]
                else:
                    dp[i][j] = False
        
        return dp[n][m]
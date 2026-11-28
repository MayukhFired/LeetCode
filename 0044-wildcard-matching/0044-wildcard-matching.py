class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        n = len(s)
        m = len(p)
        dp = [[-1] * m for _ in range(n)]

        def solve(i: int , j: int) -> bool:
            if i < 0 and j < 0:
                return True
            if j < 0 and i >= 0:
                return False
            if i < 0 and j >= 0:
                for k in range(j + 1):
                    if p[k] != '*':
                        return False
                return True
            
            if dp[i][j] != -1:
                return bool(dp[i][j])

            if p[j] == s[i] or p[j] == '?':
                ans = solve(i - 1 , j - 1)
            elif p[j] == '*':
                ans = solve(i - 1 , j) or solve(i , j - 1)
            else:
                ans = False
            
            dp[i][j] = 1 if ans else 0
            return ans
        
        return solve(n - 1, m - 1)
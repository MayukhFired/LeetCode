class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        n = len(stoneValue)
        @lru_cache(None)
        def solve(i: int) -> int:
            if i >= n:
                return 0
            res = stoneValue[i] - solve(i + 1)
            if i + 1 < n:
                res = max(res , (stoneValue[i] + stoneValue[i + 1] - solve(i + 2)))
            if i + 2 < n:
                res = max(res , (stoneValue[i] + stoneValue[i + 1] + stoneValue[ i + 2] - solve(i + 3)))
            return res
        diff = solve(0)
        if diff > 0:
            return "Alice"
        elif diff < 0:
            return "Bob"
        return "Tie"
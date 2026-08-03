# My first approach was using recursion method

# class Solution:
#     def stoneGameIII(self, stoneValue: List[int]) -> str:
#         n = len(stoneValue)
#         @lru_cache(None)
#         def solve(i: int) -> int:
#             if i >= n:
#                 return 0
#             res = stoneValue[i] - solve(i + 1)
#             if i + 1 < n:
#                 res = max(res , (stoneValue[i] + stoneValue[i + 1] - solve(i + 2)))
#             if i + 2 < n:
#                 res = max(res , (stoneValue[i] + stoneValue[i + 1] + stoneValue[ i + 2] - solve(i + 3)))
#             return res
#         diff = solve(0)
#         if diff > 0:
#             return "Alice"
#         elif diff < 0:
#             return "Bob"
#         return "Tie"
class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        n = len(stoneValue)
        a = 0
        b = 0
        c = 0
        for i in range(n - 1 , -1 , -1):
            result = stoneValue[i] - a
            if i + 1 < n:
                result = max(result , (stoneValue[i] + stoneValue[i + 1] - b))
            if i + 2 < n:
                result = max(result , (stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - c))
            c = b
            b = a
            a = result
        diff = a
        if diff > 0:
            return "Alice"
        elif diff < 0:
            return "Bob"
        return "Tie"
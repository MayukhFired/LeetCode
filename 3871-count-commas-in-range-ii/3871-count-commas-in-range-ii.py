class Solution:
    def countCommas(self, n: int) -> int:
        res = 0
        p = 1000
        while p <= n:
            res += n - p + 1
            p *= 1000
        return res
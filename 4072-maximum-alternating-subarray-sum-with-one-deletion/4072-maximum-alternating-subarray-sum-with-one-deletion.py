class Solution:
    def maxAlternatingSum(self, nums: list[int]) -> int:
        a0 = a1 = b0 = b1 = res = -inf
        for a in nums:
            b0 , b1 = max(a0 , b1 + a) , max(a1 , b0 - a)
            a0 , a1 = max(a1 + a , a) , a0 - a
            res = max(res , a0 , a1 , b0 , b1)
        return res
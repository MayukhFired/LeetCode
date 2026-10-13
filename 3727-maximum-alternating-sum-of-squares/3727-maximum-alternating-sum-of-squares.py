class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        multi = [x * x for x in nums]
        multi.sort()
        small = len(nums) // 2
        return sum(multi[small:]) - sum(multi[:small])
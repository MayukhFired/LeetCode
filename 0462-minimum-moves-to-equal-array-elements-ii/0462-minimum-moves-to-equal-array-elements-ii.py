class Solution:
    def minMoves2(self, nums: list[int]) -> int:
        res = 0
        nums.sort()
        median = nums[len(nums) // 2]
        for num in nums:
            res += abs(num - median)
        return res
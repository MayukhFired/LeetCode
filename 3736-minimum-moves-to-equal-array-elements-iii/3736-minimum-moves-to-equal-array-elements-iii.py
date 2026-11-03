class Solution:
    def minMoves(self, nums: List[int]) -> int:
        max_nums = max(nums)
        total = 0
        for i in range(len(nums)):
            total += max_nums - nums[i]
        return total
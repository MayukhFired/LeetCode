class Solution:
    def majorityElement(self, nums: list[int]) -> int:
        n = len(nums)
        nums.sort()
        return nums[n // 2]
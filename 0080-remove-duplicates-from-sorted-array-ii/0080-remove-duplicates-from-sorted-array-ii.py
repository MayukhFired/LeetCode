class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        if len(nums) <= 2:
            return len(nums)
        curr = 2
        prev = 1
        while curr < len(nums):
            if nums[curr] == nums[prev] and nums[curr] == nums[prev - 1]:
                curr += 1
            else:
                prev += 1
                nums[prev] = nums[curr]
                curr += 1
        return prev + 1
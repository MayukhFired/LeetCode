class Solution:
    def longestSubsequence(self, nums: List[int]) -> int:
        result = 0
        allzero = True
        for i in range(len(nums)):
            if nums[i] != 0:
                allzero = False
            result ^= nums[i]
        if allzero == True:
            return 0
        if result != 0:
            return len(nums)
        else:
            return len(nums) - 1
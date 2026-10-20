class Solution:
    def missingNumber(self, nums: list[int]) -> int:
        #return (len(nums) * (len(nums) + 1) // 2) - sum(nums)
        ans = 0
        for i in range(len(nums) + 1):
            ans ^= i
        for i in range(len(nums)):
            ans ^= nums[i]
        return ans
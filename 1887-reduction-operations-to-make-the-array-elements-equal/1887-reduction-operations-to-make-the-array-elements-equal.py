class Solution:
    def reductionOperations(self, nums: list[int]) -> int:
        nums.sort()
        ans = 0
        steps = 0

        for i in range(1 , len(nums)):
            if nums[i] != nums[i - 1]:
                steps += 1
            ans += steps
        return ans
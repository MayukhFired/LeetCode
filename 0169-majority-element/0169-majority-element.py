class Solution:
    def majorityElement(self, nums: list[int]) -> int:
        # n = len(nums)
        # nums.sort()
        # return nums[n // 2]

        count = 0
        candidate = 0
        for i in range(len(nums)):
            if count == 0:
                candidate = nums[i]
            if candidate == nums[i]:
                count += 1
            else:
                count += -1
        return candidate
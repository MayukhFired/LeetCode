class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        # if len(nums) <= 2:
        #     return len(nums)
        # curr = 2
        # prev = 1
        # while curr < len(nums):
        #     if nums[curr] == nums[prev] and nums[curr] == nums[prev - 1]:
        #         curr += 1
        #     else:
        #         prev += 1
        #         nums[prev] = nums[curr]
        #         curr += 1
        # return prev + 1

        if not nums:
            return 0
        j = 1
        for i in range(1 , len(nums)):
            if j == 1 or nums[i] != nums[j - 2]:
                nums[j] = nums[i]
                j += 1
        return j
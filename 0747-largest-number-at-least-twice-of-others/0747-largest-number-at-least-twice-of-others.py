class Solution:
    def dominantIndex(self, nums: lis[int]) -> int:
        # m = max(nums)
        # if all(m >= 2 * x for x in nums if x != m):
        #     return nums.index(m)
        # return -1

        max_val = max(nums)
        max_idx = nums.index(max_val)

        for i , num in enumerate(nums):
            if i != max_idx and max_val < 2 * num:
                return -1
        return max_idx
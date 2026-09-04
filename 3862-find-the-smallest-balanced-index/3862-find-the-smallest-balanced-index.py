class Solution:
    def smallestBalancedIndex(self, nums: list[int]) -> int:
        if len(nums) == 0:
            return -1
        p = 1
        s = sum(nums)
        result = -1
        max_limit = 10**16

        for j in range(len(nums) - 1 , -1 , -1):
            s -= nums[j]
            if p == s:
                return j
            if p <= max_limit:
                p *= nums[j]
            else:
                p = max_limit + 1
        return result
class Solution(object):
    def canJump(self, nums):
        max_reach = 0
        n = len(nums)
        for i in range(n):
            if i > max_reach:
                return False

            if nums[i] + i > max_reach:
                max_reach = nums[i] + i

            if max_reach >= n - 1:
                return True
        return False
        
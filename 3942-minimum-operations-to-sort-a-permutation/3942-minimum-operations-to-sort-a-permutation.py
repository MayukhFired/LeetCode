class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        a = 1
        d = 1

        for i in range(1 , n):
            a += nums[i] == (nums[i - 1] + 1) % n
            d += nums[i - 1] == (nums[i] + 1) % n
        if a == n:
            return 0 if not nums[0] else min(n - nums[0] , nums[0] + 2)
        if d == n:
            return min(n - nums[-1] , nums[-1]) + 1
        return -1
class Solution:
    def minOperations(self, nums: list[int], x: int) -> int:
        left = 0
        max_len = -1
        curr_sum = 0
        k = sum(nums) - x

        if k == 0:
            return len(nums)
        if k < 0:
            return -1
        for right in range(len(nums)):
            curr_sum += nums[right]
            while curr_sum > k:
                curr_sum -= nums[left]
                left += 1
            if k == curr_sum:
                max_len = max(max_len , right - left + 1)
        return -1 if max_len == -1 else len(nums) - max_len
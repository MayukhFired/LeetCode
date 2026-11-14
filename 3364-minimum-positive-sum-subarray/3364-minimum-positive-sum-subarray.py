class Solution:
    def minimumSumSubarray(self, nums: List[int], l: int, r: int) -> int:
        ans = float('inf')
        for i in range(len(nums)):
            summ = 0
            for j in range(i , len(nums)):
                summ += nums[j]
                length = j - i + 1
                if length >= l and length <= r and summ > 0:
                    ans = min(ans , summ)
        return -1 if ans == float('inf') else ans
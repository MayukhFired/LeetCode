class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        if len(nums) <= 1:
            return 0
        
        for i in range(len(nums)):
            leftmax = nums[i]
            rightmin = nums[i]

            for j in range(i):
                leftmax = max(leftmax , nums[j])
            for m in range(i + 1 , len(nums)):
                rightmin = min(rightmin , nums[m])
            if leftmax - rightmin <= k:
                return i
        return -1
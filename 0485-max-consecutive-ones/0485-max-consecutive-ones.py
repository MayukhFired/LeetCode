class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        max_current = 0
        current = 0
        for i in nums:
            if i == 1:
                current += 1

                if current > max_current:
                    max_current = current
            else:
                current = 0
        return max_current
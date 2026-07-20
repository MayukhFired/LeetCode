# class Solution:
#     def findClosestNumber(self, nums: List[int]) -> int:
#         n = len(nums)
#         closest = nums[0]
#         for i in range(n):
#             if abs(closest) < abs(nums):
#                 closest = nums
#             elif abs(closest) == abs(nums):
#                 if(closest > nums):
#                     closest = nums
#         return closest

from typing import List

class Solution:
    def findClosestNumber(self, nums: List[int]) -> int:
        closest = nums[0]
        
        for num in nums:
            # Check if current number is closer to zero
            if abs(num) < abs(closest):
                closest = num
            # Handle ties by choosing the larger number
            elif abs(num) == abs(closest) and num > closest:
                    closest = num
                    
        return closest

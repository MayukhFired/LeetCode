class Solution:
    def minimizeSum(self, nums: List[int]) -> int:
        nums.sort()
        
        opt1 = nums[len(nums) - 3] - nums[0]
        opt2 = nums[len(nums) - 2] - nums[1]
        opt3 = nums[len(nums) - 1] - nums[2]

        return min(opt1 , opt2 , opt3)
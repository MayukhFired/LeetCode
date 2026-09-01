class Solution:
    def rotate(self, nums: list[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        def rotate(nums: int , start: int , end: int) -> None:
            while start < end:
                temp = nums[start]
                nums[start] = nums[end]
                nums[end] = temp

                start += 1
                end -= 1
        
        numsSize = len(nums)
        k = k % numsSize
        if k == 0:
            return
        rotate(nums , 0 , numsSize - 1)
        rotate(nums , 0 , k - 1)
        rotate(nums , k , numsSize - 1)
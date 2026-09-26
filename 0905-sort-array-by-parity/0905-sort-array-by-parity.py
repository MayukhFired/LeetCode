class Solution:
    def sortArrayByParity(self, nums: list[int]) -> list[int]:
        # left = 0
        # right = len(nums) - 1

        # while left < right:
        #     if nums[left] % 2 > nums[right] % 2:
        #         nums[left] , nums[right] = nums[right] , nums[left]
        #     if nums[left] % 2 == 0:
        #         left += 1
        #     if nums[right] % 2 != 0:
        #         right -= 1
        # return nums

        even = []
        odd = []
        for i in nums:
            if i % 2 == 0:
                even.append(i)
            else:
                odd.append(i)
        return even + odd
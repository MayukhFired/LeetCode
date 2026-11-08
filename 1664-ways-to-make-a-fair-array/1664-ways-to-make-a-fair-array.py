class Solution:
    def waysToMakeFair(self, nums: list[int]) -> int:
        res = 0
        left_odd = 0
        left_even = 0
        even_sum = sum(nums[0::2])
        odd_sum = sum(nums[1::2])
        for i , x in enumerate(nums):
            if i % 2 == 0:
                even_sum -= x
                if even_sum + left_odd == left_even + odd_sum:
                    res += 1
                left_even += x
            else:
                odd_sum -= x
                if even_sum + left_odd == left_even + odd_sum:
                    res += 1
                left_odd += x
        return res
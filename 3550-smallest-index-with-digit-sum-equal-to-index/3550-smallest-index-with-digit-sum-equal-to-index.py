class Solution:
    def smallestIndex(self, nums: List[int]) -> int:
        total_sum = 0
        result = -1
        for i in range(len(nums)):
            curr_num = nums[i]
            while curr_num != 0:
                temp = curr_num % 10
                total_sum += temp
                curr_num //= 10
            if total_sum == i:
                result = i
                break
            else:
                total_sum = 0
        return result
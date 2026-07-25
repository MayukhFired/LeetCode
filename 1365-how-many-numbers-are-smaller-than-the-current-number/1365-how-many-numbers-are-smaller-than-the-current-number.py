class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        n = len(nums)
        count = [0] * 102
        for num in nums:
            count[num] += 1
        running_sum = 0
        for i in range(102):
            temp = count[i]
            count[i] = running_sum
            running_sum += temp

        return [count[num] for num in nums]
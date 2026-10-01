class Solution:
    def thirdMax(self, nums: list[int]) -> int:
        unique_nums = sorted(list(set(nums)))
        return unique_nums[-3] if len(unique_nums) >= 3 else unique_nums[-1]
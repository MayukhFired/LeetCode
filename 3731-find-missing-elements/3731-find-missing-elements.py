class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        if not nums:
            return []
        maximum = max(nums)
        minimum = min(nums)
        num_set = set(nums)
        return [i for i in range(minimum , maximum + 1) if i not in num_set]
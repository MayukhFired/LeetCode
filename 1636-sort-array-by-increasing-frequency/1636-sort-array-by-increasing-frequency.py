class Solution:
    def frequencySort(self, nums: list[int]) -> list[int]:
        freq = Counter(nums)
        return sorted(nums , key = lambda x: (freq[x] , -x))
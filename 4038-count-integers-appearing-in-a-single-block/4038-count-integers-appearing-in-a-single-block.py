class Solution:
    def countSpecialIntegers(self, nums: list[int]) -> int:
        if not nums:
            return 0

        total_count = Counter(nums)
        block_len = {}

        i = 0
        n = len(nums)
        while i < n:
            curr_num = nums[i]
            curr_len = 0
            while i < n and nums[i] == curr_num:
                curr_len += 1
                i += 1
            block_len[curr_num] = curr_len
        special_count = 0
        for num in total_count:
            if total_count[num] == block_len.get(num , 0):
                special_count += 1
        return special_count
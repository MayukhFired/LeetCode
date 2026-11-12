class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        max_len = 1
        
        for start in range(len(nums)):
            curr_len = 1
            for pos in range(start + 1 , len(nums)):
                if nums[pos - 1] < nums[pos]:
                    curr_len += 1
                else:
                    break
            max_len = max(max_len , curr_len)

        for start in range(len(nums)):
            curr_len = 1
            for pos in range(start + 1 , len(nums)):
                if nums[pos - 1] > nums[pos]:
                    curr_len += 1
                else:
                    break
            max_len = max(max_len , curr_len)

        return max_len
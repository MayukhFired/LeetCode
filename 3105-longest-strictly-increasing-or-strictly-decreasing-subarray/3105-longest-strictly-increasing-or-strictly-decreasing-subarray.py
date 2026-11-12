class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
    # 1-------------------------------------------------------------------------------1
        # max_len = 1
        
        # for start in range(len(nums)):
        #     curr_len = 1
        #     for pos in range(start + 1 , len(nums)):
        #         if nums[pos - 1] < nums[pos]:
        #             curr_len += 1
        #         else:
        #             break
        #     max_len = max(max_len , curr_len)

        # for start in range(len(nums)):
        #     curr_len = 1
        #     for pos in range(start + 1 , len(nums)):
        #         if nums[pos - 1] > nums[pos]:
        #             curr_len += 1
        #         else:
        #             break
        #     max_len = max(max_len , curr_len)

        # return max_len
    # 1-----------------------------------------------------------------------------1
        max_len = 1
        inc = 1
        dec = 1

        for pos in range(len(nums) - 1):
            if nums[pos + 1] > nums[pos]:
                inc += 1
                dec = 1
            elif nums[pos + 1] < nums[pos]:
                dec += 1
                inc = 1
            else:
                inc = 1
                dec = 1
            max_len = max(max_len , inc , dec)
        
        return max_len
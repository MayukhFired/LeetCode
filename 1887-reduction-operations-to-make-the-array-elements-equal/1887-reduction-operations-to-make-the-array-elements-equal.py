class Solution:
    def reductionOperations(self, nums: list[int]) -> int:
    # 1----------------------------------------------------1
        # nums.sort()
        # ans = 0
        # steps = 0

        # for i in range(1 , len(nums)):
        #     if nums[i] != nums[i - 1]:
        #         steps += 1
        #     ans += steps
        # return ans
    # 1---------------------------------------------------1
        max_val = max(nums)
        ans = 0
        steps = 0
        freq = [0] * (max_val + 1)

        for x in nums:
            freq[x] += 1
        
        for val in range(1 , max_val + 1):
            if freq[val] > 0:
                ans += freq[val] * steps
                steps += 1

        return ans
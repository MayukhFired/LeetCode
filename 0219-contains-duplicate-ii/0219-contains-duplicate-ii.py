class Solution:
    def containsNearbyDuplicate(self, nums: list[int], k: int) -> bool:
        # seen = set()
        # for i , num in enumerate(nums):
        #     if i > k:
        #         seen.remove(nums[i - k - 1])
        #     if num in seen:
        #         return True
        #     seen.add(num)
        # return False

        # seen = {}
        # for i in range(len(nums)):
        #     if nums[i] in seen:
        #         if i - seen[nums[i]] <= k:
        #             return True
        #     seen[nums[i]] = i
        # return False

        if len(set(nums)) == len(nums):
            return False
        nums.reverse()
        for left in range(len(nums) - 1):
            for right in range(left + 1 , min(left + k + 1 , len(nums))):
                if nums[left] == nums[right]:
                    return True
        return False
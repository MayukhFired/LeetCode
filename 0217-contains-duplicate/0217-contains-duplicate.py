class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        # nums.sort()
        # for i in range(1 , len(nums)):
        #     if nums[i - 1] == nums[i]:
        #         return True
        # return False

         return len(nums) != len(set(nums))

        # seen = set()
        # for num in nums:
        #     if num in seen:
        #         return True
        #     seen.add(num)
        # return False
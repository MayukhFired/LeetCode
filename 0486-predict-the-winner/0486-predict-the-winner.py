# class Solution:
#     def predictTheWinner(self, nums: List[int]) -> bool:
#         @lru_cache(None)
#         def solve(i: int , j: int) -> int:
#             if i > j:
#                 return 0
#             if i == j:
#                 return nums[i]
#             take_1 = nums[i] + min(solve(i + 2, j) , solve(i + 1 , j - 1))
#             take_2 = nums[j] + min(solve(i , j - 2) , solve(i + 1 , j - 1))
#             return max(take_1 , take_2)
#         total = sum(nums)
#         p_1 = solve(0 , len(nums) - 1)
#         p_2 = total - p_1
#         return p_1 >= p_2

class Solution:
    def predictTheWinner(self, nums: List[int]) -> bool:
        @lru_cache(None)
        def solve(i: int , j: int) -> int:
            if i > j:
                return 0
            if i == j:
                return nums[i]
            take_1 = nums[i] - solve(i + 1 , j)
            take_2 = nums[j] - solve(i , j - 1)
            return max(take_1 , take_2)
        return solve(0 , len(nums) - 1) >= 0
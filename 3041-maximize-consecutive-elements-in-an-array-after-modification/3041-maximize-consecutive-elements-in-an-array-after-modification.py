class Solution:
    def maxSelectedElements(self, nums: List[int]) -> int:
    # 1------------------------------------------------------------------------------1
        # nums.sort()
        # dp = {}
        # ans = 0

        # for x in nums:
        #     dp[x + 1] = max(dp.get(x + 1 , 0) , dp.get(x , 0) + 1)
        #     dp[x] = max(dp.get(x , 0) , dp.get(x - 1 , 0) + 1)
        #     ans = max(ans , dp[x] , dp[x + 1])

        # return ans
    # 1------------------------------------------------------------------------------1
        best = keep = bump = 1
        last = -10

        for x in sorted(nums):
            match x - last:
                case 0: bump = keep + 1
                case 1:
                    keep , bump = keep + 1 , bump + 1
                case 2:
                    keep , bump = bump + 1 , 1
                case _:
                    keep = bump = 1
            best , last = max(best , keep , bump) , x
        return best
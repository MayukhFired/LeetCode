class Solution:
    def maxLength(self, nums: List[int]) -> int:
    # 1-----------------------------------------------------------1
        # res = 0
        # for i in range(len(nums)):
        #     prod_val = nums[i]
        #     gcd_val = nums[i]
        #     lcm_val = nums[i]
        #     for j in range(i + 1 , len(nums)):
        #         prod_val = prod_val * nums[j]
        #         gcd_val = gcd(gcd_val , nums[j])
        #         lcm_val = lcm(lcm_val , nums[j])
        #         if prod_val > gcd_val * lcm_val:
        #             break
        #         if prod_val == gcd_val * lcm_val:
        #             res = max(res , j - i + 1)
        # return res
    # 1-----------------------------------------------------------1
        res = 2
        prod_val = 1
        n = len(nums)
        start = 0
        end = 0

        while end < n:
            while gcd(prod_val , nums[end]) > 1:
                prod_val //= nums[start]
                start += 1

            prod_val *= nums[end]
            res = max(res , end - start + 1)
            end += 1

        return res
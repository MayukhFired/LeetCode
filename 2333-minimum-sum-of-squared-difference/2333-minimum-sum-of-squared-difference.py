class Solution:
    def minSumSquareDiff(self, nums1: list[int], nums2: list[int], k1: int, k2: int) -> int:
        # 1------------------------------------------------------------1
        # k = k1 + k2
        # n = len(nums1)
        # max_diff = 0
        # for i in range(n):
        #     nums1[i] = abs(nums1[i] - nums2[i])
        #     max_diff = max(max_diff , nums1[i])

        # l , r , res = 0 , max_diff , 0

        # while l <= r:
        #     mid = (l + r) >> 1
        #     if sum(num - mid for num in nums1 if num > mid) <= k:
        #         r = mid - 1
        #         res = mid
        #     else:
        #         l = mid + 1
        
        # for num in nums1:
        #     if num > res:
        #         k -= num - res
        
        # nums1.sort(reverse = True)
        # ans = 0

        # for num in nums1:
        #     diff = min(num , res)
        #     if k > 0 and diff > 0:
        #         diff -= 1
        #         k -= 1
        #     ans += diff * diff
        # return ans
        # 1-----------------------------------------------------------------1

        k = k1 + k2
        d = [abs(a - b) for a , b in zip(nums1 , nums2)]
        if sum(d) <= k:
            return 0

        d.sort(reverse = True)
        d.append(0)
        n = len(nums1)

        for i in range(1 , n + 1):
            cost = (d[i - 1] - d[i]) * i
            if cost > k:
                q , r = divmod(k , i)
                hi = d[i - 1] - q
                return (hi * hi * (i - r) + (hi - 1) * (hi - 1) * r + sum(x * x for x in d[i:n]))
            k -= cost
        return 0
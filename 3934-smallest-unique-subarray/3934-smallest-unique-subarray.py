class Solution:
    def smallestUniqueSubarray(self, nums: List[int]) -> int:
    # 1-------------------------------------------------------------------------------1
        # n = len(nums)
        # if n == 0:
        #     return 0

        # rank = sorted(set(nums))
        # comp = {v: i for i, v in enumerate(rank)}
        # rank = [comp[x] for x in nums]
        # sa = list(range(n))
        # k = 1
        # temp = [0] * n

        # while k < n:
        #     sa.sort(key=lambda i: (rank[i], rank[i + k] if i + k < n else -1))
        #     temp[sa[0]] = 0
        #     prev = sa[0]

        #     for idx in range(1, n):
        #         curr = sa[idx]
        #         a1 = rank[prev]
        #         a2 = rank[prev + k] if prev + k < n else -1
        #         b1 = rank[curr]
        #         b2 = rank[curr + k] if curr + k < n else -1
        #         temp[curr] = temp[prev] + (0 if (a1 == b1 and a2 == b2) else 1)
        #         prev = curr
        #     rank, temp = temp, rank
        #     if rank[sa[-1]] == n - 1:
        #         break
        #     k <<= 1

        # pos = [0] * n
        # for i in range(n):
        #     pos[sa[i]] = i

        # lcp = [0] * n
        # h = 0
        # for i in range(n):
        #     pi = pos[i]
        #     if pi == 0:
        #         h = 0
        #         continue
        #     j = sa[pi - 1]

        #     while i + h < n and j + h < n and nums[i + h] == nums[j + h]:
        #         h += 1
        #     lcp[pi] = h
        #     if h:
        #         h -= 1

        # ans = n
        # for i in range(n):
        #     nxt = lcp[i + 1] if i + 1 < n else 0
        #     need = (lcp[i] if lcp[i] > nxt else nxt) + 1
        #     if sa[i] + need - 1 < n and need < ans:
        #         ans = need
        # return ans
    # 1------------------------------------------------------------------------------1
        MOD = 1000000007
        BASE = 911382323

        n = len(nums)
        h = [0] * (n + 1)
        p = [0] * (n + 1)
        p[0] = 1

        for i in range(n):
            h[i + 1] = (h[i] * BASE + nums[i]) % MOD
            p[i + 1] = p[i] * BASE % MOD

            def check(length):
                cnt = {}
                for l in range(n - length + 1):
                    r = l + length
                    key = (h[r] - h[l] * p[length] % MOD + MOD) % MOD
                    cnt[key] = cnt.get(key , 0) + 1
                
                for times in cnt.values():
                    if times == 1:
                        return True
                return False

        low , high = 1 , n
        while low < high:
            mid = low + (high - low) // 2
            if check(mid):
                high = mid
            else:
                low = mid + 1

        return low
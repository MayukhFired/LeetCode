1class Solution:
2    def findKthSmallest(self, coins: List[int], k: int) -> int:
3        n = len(coins)
4        subset_lcm = []
5        for i in range(1 , 1 << n):
6            current_lcm = 1
7            count = 0
8            for j in range(n):
9                if(i >> j) & 1:
10                    count += 1
11                    current_lcm = math.lcm(current_lcm , coins[j])
12            sign = 1 if count % 2 == 1 else -1
13            subset_lcm.append((current_lcm , sign))
14        def count_amounts(max_val : int) -> int:
15            total_count = 0
16            for lcm , sign in subset_lcm:
17                total_count += sign * (max_val // lcm)
18            return total_count
19        low = 1
20        high = k * min(coins)
21        ans = high
22        while low <= high:
23            mid = low + (high - low) // 2
24            if count_amounts(mid) >= k:
25                ans = mid
26                high = mid - 1
27            else:
28                low = mid + 1
29        return ans
class Solution:
    def maxSum(self, nums: List[int], k: int) -> int:
        MOD = 10**9 + 7
        bits = [0] * 30

        for num in nums:
            for i in range(30):
                if (num >> i) & 1:
                    bits[i] += 1
        total_sum = 0

        for step in range(k):
            curr_sum = 0
            for i in range(30):
                if bits[i] > 0:
                    curr_sum |= (1 << i)
                    bits[i] -= 1
            total_sum = (total_sum + (curr_sum * curr_sum)) % MOD
        return total_sum
class Solution:
    def minSumOfLengths(self, arr: List[int], target: int) -> int:
        # pos = {0: -1}
        # n = len(arr)
        # s = 0
        # ans = n + 1
        # min_l = n
        # for i , x in enumerate(arr):
        #     s += x
        #     if s- target in pos:
        #         j = pos[s - target]
        #         length = i - j
        #         ans = min(ans , length + (n if j == -1 else arr[j]))
        #         min_l = min(min_l , length)
        #     arr[i] = min_l
        #     pos[s] = i
        # return -1 if ans == n + 1 else ans

        n = len(arr)
        INF = n + 1
        min_len = [INF] * n

        left = 0
        curr_sum = 0
        min_total_sum = INF
        curr_min_len = INF

        for right in range(n):
            curr_sum += arr[right]
            while curr_sum > target and left <= right:
                curr_sum -= arr[left]
                left += 1
            if curr_sum == target:
                curr_len = right - left + 1
                if left > 0 and min_len[left - 1] != INF:
                    min_total_sum = min(min_total_sum , curr_len + min_len[left - 1])
                curr_min_len = min(curr_min_len , curr_len)
            min_len[right] = curr_min_len
        return -1 if min_total_sum == INF else min_total_sum
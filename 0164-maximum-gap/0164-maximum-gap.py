class Solution:
    def maximumGap(self, nums: list[int]) -> int:
        n = len(nums)
        if n < 2:
            return 0
        min_val = min(nums)
        max_val = max(nums)

        if min_val == max_val:
            return 0

        bucket_size = max(1 , (max_val - min_val) // (n - 1))
        bucket_count = (max_val - min_val) // bucket_size + 1

        buckets = [[float('inf') , float('-inf')] for _ in range(bucket_count)]
        for num in nums:
            bucket_idx = (num - min_val) // bucket_size
            buckets[bucket_idx][0] = min(buckets[bucket_idx][0] , num)
            buckets[bucket_idx][1] = max(buckets[bucket_idx][1] , num)

        max_gap = 0
        previous_max = min_val

        for curr_min , curr_max in buckets:
            if curr_min == float('inf'):
                continue
            max_gap = max(max_gap , curr_min - previous_max)
            previous_max = curr_max
        return max_gap
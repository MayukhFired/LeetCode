class Solution(object):
    def gcdValues(self, nums, queries):
        max_num = max(nums)
        counts = Counter(nums)
        cnt_gcd = [0] * (max_num + 1)
        for i in range(max_num, 0, -1):
            multiples_count = 0
            for j in range(i, max_num + 1, i):
                multiples_count += counts[j]
            
            total_pairs = (multiples_count * (multiples_count - 1)) // 2
            
            for j in range(2 * i, max_num + 1, i):
                total_pairs -= cnt_gcd[j]
                
            cnt_gcd[i] = total_pairs
            
        prefix_sums = [0] * (max_num + 1)
        for i in range(1, max_num + 1):
            prefix_sums[i] = prefix_sums[i - 1] + cnt_gcd[i]
            
        result = []
        for q in queries:
            
            idx = bisect.bisect_right(prefix_sums, q)
            result.append(idx)
            
        return result
        
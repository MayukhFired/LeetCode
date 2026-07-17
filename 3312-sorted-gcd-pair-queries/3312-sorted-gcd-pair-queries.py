class Solution(object):
    def gcdValues(self, nums, queries):
        max_num = max(nums)
        counts = Counter(nums)
        
        # cnt_gcd[g] will store the EXACT number of pairs that have gcd(a, b) == g
        cnt_gcd = [0] * (max_num + 1)
        
        # Step 2: Work backwards from max_num down to 1 (Inclusion-Exclusion Math)
        for i in range(max_num, 0, -1):
            # Count how many total numbers in nums are multiples of i
            multiples_count = 0
            for j in range(i, max_num + 1, i):
                multiples_count += counts[j]
            
            # Total possible pairs formed by these multiples
            total_pairs = (multiples_count * (multiples_count - 1)) // 2
            
            # Subtract pairs whose GCD is a larger multiple of i (e.g., 2i, 3i, 4i)
            for j in range(2 * i, max_num + 1, i):
                total_pairs -= cnt_gcd[j]
                
            cnt_gcd[i] = total_pairs
            
        # Step 3: Compute running totals (Prefix Sum) of the pair counts
        prefix_sums = [0] * (max_num + 1)
        for i in range(1, max_num + 1):
            prefix_sums[i] = prefix_sums[i - 1] + cnt_gcd[i]
            
        # Step 4: Map each query to its corresponding GCD index via Binary Search
        result = []
        for q in queries:
            # We want to find the first position where prefix_sums[idx] > q
            idx = bisect.bisect_right(prefix_sums, q)
            result.append(idx)
            
        return result
        
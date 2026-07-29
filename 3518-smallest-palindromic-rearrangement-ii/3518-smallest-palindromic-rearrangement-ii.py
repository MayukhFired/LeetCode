from collections import Counter
import math

class Solution:
    def smallestPalindrome(self, s: str, k: int) -> str:
        # Step 1: Count character frequencies
        counts = Counter(s)
        
        # Step 2: Initialize arrays for the left half and trace any middle character
        half_counts = [0] * 26
        mid_char = ""
        total_len = 0
        
        for char, count in counts.items():
            idx = ord(char) - ord('a')
            half_counts[idx] = count // 2
            total_len += half_counts[idx]
            
            # An odd frequency means this character sits in the exact middle
            if count % 2 != 0:
                mid_char = char
        
        # Helper function to compute total unique arrangements capped at k
        def count_arrangements(pool_counts: list[int]) -> int:
            total = sum(pool_counts)
            ways = 1
            for current_count in pool_counts:
                if current_count > 0:
                    ways *= math.comb(total, current_count)
                    if ways >= k:
                        return k  # Cap early to save memory and processing time
                    total -= current_count
            return ways

        # Step 3: Fast feasibility check
        if count_arrangements(half_counts) < k:
            return ""

        # Step 4: Greedily build the left half character by character
        left_half = []
        for step in range(total_len):
            for i in range(26):
                if half_counts[i] == 0:
                    continue
                
                # Speculatively take one character
                half_counts[i] -= 1
                arrangements = count_arrangements(half_counts)
                
                # Check if our target k falls within this branch
                if arrangements >= k:
                    left_half.append(chr(ord('a') + i))
                    break  # Lock character and move to next position
                else:
                    k -= arrangements  # Skip branch and reduce k
                    half_counts[i] += 1  # Put the character back

        # Step 5: Mirror and assemble the final palindrome
        left_str = "".join(left_half)
        return left_str + mid_char + left_str[::-1]

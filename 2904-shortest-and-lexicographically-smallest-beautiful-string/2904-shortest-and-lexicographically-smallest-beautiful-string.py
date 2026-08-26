class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
        best_left = -1
        min_len = len(s) + 1
        ones = 0
        l = 0
        for r in range(len(s)):
            if s[r] == '1':
                ones += 1
            while ones == k:
                curr_len = r - l + 1
                if curr_len < min_len:
                    min_len = curr_len
                    best_left = l
                elif curr_len == min_len:
                    if best_left == -1 or s[l:l + curr_len] < s[best_left:best_left + min_len]:
                        best_left = l
                if s[l] == '1':
                    ones -= 1
                l += 1
        return "" if best_left == -1 else s[best_left:best_left + min_len]
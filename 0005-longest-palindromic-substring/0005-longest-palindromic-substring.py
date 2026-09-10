class Solution:
    def longestPalindrome(self, s: str) -> str:
        if not s:
            return ""
        def solve(i: int , j : int) -> tuple[int , int]:
            while i >= 0 and j < len(s) and s[i] == s[j]:
                i -= 1
                j += 1
            return i + 1 , j - 1 - i
        start = 0
        max_len = 0
        for i in range(len(s)):
            start1 , len1 = solve(i , i)
            if len1 > max_len:
                max_len = len1
                start = start1

            start2 , len2 = solve(i , i + 1)
            if max_len < len2:
                max_len = len2
                start = start2

        return s[start : start + max_len]